#include <iostream>
#include "program_options.hpp"

auto main(int ac, char** av) -> int {

    std::cout << "main\n";
    auto options = program_options(ac, av);

    for (const auto file : options.get_input_output_file_map()) {
        std::cout << file.first << " -> " << file.second << "\n" << std::endl;
    }
}
