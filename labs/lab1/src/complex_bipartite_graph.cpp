/*! Complex Bipartite Graph Implementation for EE360C Lab 1 */

#include "complex_bipartite_graph.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <sstream>

complex_bipartite_graph::complex_bipartite_graph() { num_instances = -1; }

auto complex_bipartite_graph::generate_data_structures(std::string file_input)
    -> void {

    /* Generate structures here */
    std::cout << "generating data structures\n";

    std::ifstream fin;
    fin.open(file_input);

    std::string line;

    /* Parse the current file */
    while (fin) {
        std::getline(fin, line);

        std::size_t pos = 0;
        std::vector<std::string> toks;

        /* Parse the current line */
        while ((pos = line.find(" "))) {
            toks.emplace_back(line.substr(0, pos));
            line.erase(0, pos + 1);
            if (pos == std::string::npos) { break; }
        }
        /* std::cout << "toks (" << toks.size() << "): "; */
        /* for (const auto tok : toks) { std::cout << tok << " "; } */
        /* std::cout << "\n"; */

        try {
            if ((toks.size() == 1) && (this->num_instances < 0)) {
                /* Num instances */
                this->num_instances = std::stoi(toks[0]);
            } else if (toks.size() == 2) {
                /* Tac node */
                const int32_t id = stoi(toks[0]);
                const int32_t weight = stoi(toks[1]);
                tac_nodes.emplace_back(id, weight);
            } else if (toks.size() == 4) {
                /* Tic node */
                const int32_t id = stoi(toks[0]);
                const int32_t min = stoi(toks[1]);
                const int32_t max = stoi(toks[2]);
                const int32_t weight = stoi(toks[3]);
                tic_nodes.emplace_back(id, min, max, weight);
            }
        } catch (std::exception e) {
            std::cout << e.what() << "\n";
            exit(1);
        }
    }

    std::cout << to_string();
}

auto complex_bipartite_graph::mwmcm() -> void {
    /* Do the MWMCM algorithm here */
}

auto complex_bipartite_graph::calculate_adjacency_lists() -> void {
    /* Calculate the adjacency lists */
}

auto complex_bipartite_graph::reset_edges() -> void {
    for (auto tic : tic_nodes) {
        tic.reset_adjacency_enabled();
    }

    for (auto tac : tac_nodes) {
        tac.reset_adjacency_enabled();
    }
}

auto complex_bipartite_graph::to_string() const
    -> const std::string {

    std::stringstream str;
    str << "num_instances: " << num_instances << "\n";
    for (const auto tic : tic_nodes) {
        str << tic.to_string() << "\n";
    }

    for (const auto tac : tac_nodes) {
        str << tac.to_string() << "\n";
    }

    return str.str();
}
