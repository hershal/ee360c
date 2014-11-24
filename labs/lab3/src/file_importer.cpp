#include "file_importer.hpp"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>

file_importer::file_importer(std::string file_input, std::string file_output) {
    file_importer(file_input, file_output, true);
}

file_importer::file_importer(std::string file_input, std::string file_output,
                             bool output_enabled) {

    this->output_enabled = output_enabled;
    this->file_input = file_input;
    this->file_output = file_output;
}

auto file_importer::generate_graph() -> void {

    /* Generate structures here */
    std::cout << "importing file: " << this->file_input << "\n";

    std::ifstream fin;
    fin.open(this->file_input);

    parsing_state pstate = kPSInit;

    /* Parse the current file */
    std::string line;
    size_t num_fragments = 0;
    size_t current_fragment = 0;

    /* undirected_graph graph; */
    /* graph_query query; */

    while (fin) {
        std::getline(fin, line);

        std::size_t pos = 0;
        std::vector<std::string> tokens;

        /* Parse the current line and break it up into elements
           separated by a space so that we can determine what the line is */
        while ((pos = line.find(" "))) {
            tokens.emplace_back(line.substr(0, pos));
            line.erase(0, pos + 1);
            if (pos == std::string::npos) { break; }
        }

        try {
            /* Init: input the number of traces and number of devices */
            if (pstate == kPSInit) {
                num_fragments = stoi(tokens[0]);

                printf("num fragments: %zu\n", num_fragments);

                /* graph = undirected_graph(num_devices); */
                pstate = kPSFragmentParse;

            } else if ((tokens.size() == 1) && (pstate == kPSFragmentParse)) {
                const std::string fragment = tokens[0];
                /* graph.add_connection(device_i, device_j, communication_time); */

                printf("fragment: %s\n", fragment.c_str());

                ++current_fragment;

                if (current_fragment == num_fragments) {
                    pstate = kPSQueryParse;
                }
            } else if ((tokens.size() == 1) && (pstate == kPSQueryParse)) {
                const std::string full_string = tokens[0];

                printf("query string: %s\n", full_string.c_str());
                
                /* query.add_query(device_i, device_j, time_a, time_b); */
                pstate = kPSDone;
            } else {
                if ((current_fragment == num_fragments)
                    /* && (query.has_query()) */
                    && (pstate == kPSDone)) {
                    printf("done parsing\n");
                } else {
                    printf("Unknown specification error!\n");
                    printf("Everything fell through!\n");
                    exit(1);
                }
            }
        } catch (std::exception e) {
            std::cout << e.what() << "\n";
            exit(1);
        }
    }

    /* Not very pretty code below heren */
    std::ofstream fout;

    if (output_enabled) {
        fout.open(file_output);
    }
    
    /* std::cout << query.to_string() << "\n"; */
    /* std::cout << graph.to_string() << "\n"; */

    /* std::cout << "running...\n"; */

    /* graph.do_query(&query); */
    /* std::cout << query.to_string() << "\n"; */


    if (output_enabled) {
        /* fout << query.to_output(); */
        fout.close();
    }
}
