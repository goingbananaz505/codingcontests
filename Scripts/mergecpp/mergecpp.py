import sys
from cppmerger import CppMerger


def main():
    merger = CppMerger(sys.argv[1])
    merger.merge()
    print(merger.merged_file_abspath)


if __name__ == "__main__":
    main()
