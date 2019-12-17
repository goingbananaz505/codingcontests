import os
import re as regex
import subprocess


class CppMerger:
    def __init__(self, file_path):
        self.__main_file_abspath = self.__get_abspath(file_path)
        self.__main_file_dir_abspath = os.path.dirname(self.__main_file_abspath)
        self.merged_file_abspath = os.path.realpath(
            os.path.join(self.__main_file_dir_abspath, '..', 'Temp', self.__get_project_name() + '.cpp'))
        self.__code_lines = self.__get_file_content(self.__main_file_abspath)
        self.__relative_includes_regex_pattern = r'^#include\s+\"(?P<header_file_path>[^\"]+)\"$'

    def merge(self):
        while self.__are_any_relative_includes_in_code():
            self.__expand_code()
            self.__beautify_code()
        self.__save_merged_file()
        self.__test_correctness_of_merged_file()
        self.__copy_file_content_to_clipboard()

    @staticmethod
    def __get_abspath(file_path):
        expanded_user_from_tilde_file_path = os.path.expanduser(file_path)
        absolute_path_from_cwd_and_relative = os.path.realpath(expanded_user_from_tilde_file_path)
        return absolute_path_from_cwd_and_relative

    @staticmethod
    def __get_file_content(file_abspath):
        return [line.rstrip('\n').rstrip() for line in open(file_abspath)]

    def __are_any_relative_includes_in_code(self):
        pattern = self.__relative_includes_regex_pattern
        relative_include_file_paths = list(filter(lambda line: regex.search(pattern, line), self.__code_lines))
        return len(relative_include_file_paths) > 0

    def __expand_code(self):
        found_index = self.__get_index_of_first_header_include_occurrence()
        relative_file_path = self.__get_relative_include_from_line(self.__code_lines[found_index])
        file_abspath = os.path.join(self.__main_file_dir_abspath, relative_file_path)
        lines_to_be_inserted = self.__get_file_content(file_abspath)
        code = self.__code_lines
        self.__code_lines = code[0: found_index] + lines_to_be_inserted + code[found_index + 1:]

    def __beautify_code(self):
        pass

    def __save_merged_file(self):
        with open(self.merged_file_abspath, 'w') as f:
            [f.write("%s\n" % line) for line in self.__code_lines]

    def __test_correctness_of_merged_file(self):
        outfile_path = os.path.join(self.__main_file_dir_abspath, 'a.out')
        subprocess.run(['g++', '-std=c++11', self.merged_file_abspath,
                        '-o', outfile_path],
                       stdout=subprocess.PIPE)
        if os.path.exists(outfile_path):
            os.remove(outfile_path)

    def __copy_file_content_to_clipboard(self):
        process = subprocess.Popen(
            'pbcopy', env={'LANG': 'en_US.UTF-8'}, stdin=subprocess.PIPE)
        output = '\n'.join(self.__code_lines)
        process.communicate(output.encode('utf-8'))

    @staticmethod
    def __get_root_directory_name_from_file_path(file_path):
        return os.path.basename(os.path.dirname(file_path))

    def __get_project_name(self):
        return self.__get_root_directory_name_from_file_path(self.__main_file_abspath)

    def __get_relative_include_from_line(self, include_line):
        pattern = self.__relative_includes_regex_pattern
        return regex.search(pattern, include_line).group('header_file_path')

    def __get_index_of_first_header_include_occurrence(self):
        pattern = self.__relative_includes_regex_pattern
        for i in range(len(self.__code_lines)):
            line = self.__code_lines[i]
            if regex.search(pattern, line):
                return i
