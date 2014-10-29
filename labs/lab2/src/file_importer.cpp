#include "file_importer.hpp"

#include <iostream>
#include <fstream>
#include <exception>

file_importer::file_importer(std::string file_input, std::string file_output) {

    this->file_input = file_input;
    this->file_output = file_output;
}

auto file_importer::generate_graph() -> void {

    /* Generate structures here */
    /* std::cout << "importing file: " << this->file_input << "\n"; */

    std::ifstream fin;
    fin.open(this->file_input);

    parsing_state pstate = kPSInit;

    /* Parse the current file */
    std::string line;
    size_t num_devices = 0;
    size_t num_traces = 0;
    size_t current_trace = 0;

    undirected_graph graph;
    graph_query query;

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
                num_devices = stoi(tokens[0]);
                num_traces = stoi(tokens[1]);

                graph = undirected_graph(num_devices);
                pstate = kPSTraceParse;

            } else if ((tokens.size() == 3) && (pstate == kPSTraceParse)) {
                const size_t device_i = stoi(tokens[0]);
                const size_t device_j = stoi(tokens[1]);
                const uint32_t communication_time = stoi(tokens[2]);
                graph.add_connection(device_i, device_j, communication_time);
                ++current_trace;

                if (current_trace == num_traces) {
                    pstate = kPSQueryParse;
                }
            } else if ((tokens.size() == 4) && (pstate == kPSQueryParse)) {
                const size_t device_i = stoi(tokens[0]);
                const size_t device_j = stoi(tokens[1]);
                const uint32_t time_a = stoi(tokens[2]);
                const uint32_t time_b = stoi(tokens[3]);

                query.add_query(device_i, device_j, time_a, time_b);
                pstate = kPSDone;
            } else {
                if ((current_trace == num_traces) &&
                    (query.has_query()) && (pstate == kPSDone)) {
                    /* std::cout << "done parsing\n"; */
                } else {
                    /* std::cout << "Unknown specification error!\n" */
                    /*           << "Everything fell through!\n"; */
                    exit(1);
                }
            }
        } catch (std::exception e) {
            /* std::cout << e.what() << "\n"; */
            exit(1);
        }
    }

    /* std::ofstream fout; */
    /* fout.open(file_output); */

    /* std::cout << query.to_string() << "\n"; */
    /* std::cout << graph.to_string() << "\n"; */

    /* std::cout << "running...\n"; */

    graph.do_query(&query);
    /* std::cout << query.to_string() << "\n"; */

    /* fout << query.to_output(); */
    std::cout << query.to_output();

    /* fout.close(); */
}
