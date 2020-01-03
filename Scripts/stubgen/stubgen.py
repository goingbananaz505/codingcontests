import sys
from codeforcesstubgenerator import CodeForcesStubGenerator


def main():
    (problem_url, local_project_path) = get_commandline_arguments()
    generator = CodeForcesStubGenerator(problem_url)
    generator.add_stub_problem_solution_to_project(local_project_path)


def get_commandline_arguments():
    problem_url = sys.argv[1]
    local_project_path = sys.argv[2]
    return problem_url, local_project_path


if __name__ == "__main__":
    main()
