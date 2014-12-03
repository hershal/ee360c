#include "program_options.hpp"
#include "file_importer.hpp"

auto main(int ac, char** av) -> int {

    auto options = new program_options(ac, av);

    for (const auto file : *(options->get_input_output_file_map())) {
        file_importer importer
            = file_importer(file.first, file.second,
                            options->get_output_enabled());
        importer.generate_graph();
    }
    delete options;
    exit(0);
}
