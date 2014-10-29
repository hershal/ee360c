#include "program_options.hpp"
#include "file_importer.hpp"

#include <iostream>

auto main(int ac, char** av) -> int {

    /* std::cout << "parsing options\n"; */
    auto options = program_options(ac, av);

    /* std::cout << "processing files\n"; */
    for (const auto file : options.get_input_output_file_map()) {
        /* std::cout << file.first << " -> " << file.second << std::endl; */
        file_importer importer = file_importer(file.first, file.second);
        importer.generate_graph();
    }
}
