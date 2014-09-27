#include <iostream>
#include "program_options.hpp"

auto main(int ac, char** av) -> int {
    
    std::cout << "main\n";
    auto options = program_options(ac, av);
}
