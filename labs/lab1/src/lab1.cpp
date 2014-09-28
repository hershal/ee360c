#include "program_options.hpp"
#include "complex_bipartite_graph.hpp"

#include <iostream>

auto main(int ac, char** av) -> int {

    std::cout << "main\n";
    auto options = program_options(ac, av);

    for (const auto file : options.get_input_output_file_map()) {
        std::cout << file.first << " -> " << file.second << "\n" << std::endl;
    }

    for (const auto file : options.get_input_output_file_map()) {
        complex_bipartite_graph cbg = complex_bipartite_graph();
        cbg.generate_data_structures(file.first);
    }
}
