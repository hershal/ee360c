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
    std::cout << "importing file: " << this->file_input << "\n";

    std::ifstream fin;
    fin.open(this->file_input);

    parsing_state pstate = kPSInit;

    /* Parse the current file */
    std::string line;
    size_t num_devices = 0;
    size_t num_traces = 0;

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
                num_devices = tokens[0];
                num_traces = tokens[1];

                graph = undirected_graph(num_devices);
                pstate = kPSNumTicTac;

            } else if ((tokens.size() == 3) && (pstate == kPSTraceParse)) {
                const size_t device_i = stoi(tokens[0]);
                const size_t device_j = stoi(tokens[1]);
                const uint32_t communication_time = stoi(tokens[2]);
                graph.add_connection(device_i, device_j, communication_time);
            } else if ((tokens.size() == 4) && (pstate == kPSTics)) {
                const size_t device_i = stoi(tokens[0]);
                const size_t device_j = stoi(tokens[1]);
                const uint32_t time_a = stoi(tokens[2]);
                const uint32_t time_b = stoi(tokens[3]);

                query.add_query(device_i, device_j, time_a, time_b);

            } else {
                std::cout << "Unknown specification error!\n"
                          << "Everything fell through!\n";
            }
        } catch (std::exception e) {
            std::cout << e.what() << "\n";
            exit(1);
        }

    }

    std::ofstream fout;
    fout.open(file_output);
    for (auto i=0; i<graphs.size(); ++i) {
        std::cout << "instance: " << i << "\n";
        std::cout << graphs[i].to_string() << "\n";
        const auto mwmcms = graphs[i].find_mwmcms();

        std::cout << "writing output\n";

        const auto highest_cardinality_match = mwmcms.rbegin();
        const auto highest_weight_match = highest_cardinality_match->second.rbegin();
        fout << highest_weight_match->second.size() << "\n";
        for (const auto match : highest_weight_match->second) {
            fout << match.to_string() << "\n";
        }
    }
    fout.close();
}
