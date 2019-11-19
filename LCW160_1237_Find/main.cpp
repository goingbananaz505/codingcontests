#include <iostream>
#include "solution.h"

int main(int argc, const char * argv[]) {
    CustomFunction f; int z = 5;
    
    Solution s;
    auto solution = s.findSolution(f, z);
    for(const auto& pair : solution) {
        std::cout << pair[0] << " " << pair[1] << std::endl;
    }
    
    return 0;
}
