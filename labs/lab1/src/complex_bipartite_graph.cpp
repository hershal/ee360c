/*! Complex Bipartite Graph Implementation for EE360C Lab 1 */

#include "complex_bipartite_graph.hpp"

#include <iostream>

complex_bipartite_graph::complex_bipartite_graph() { }

auto complex_bipartite_graph::generate_data_structures(std::string file_input)
    -> void {

    /* Generate structures here */
    std::cout << "generating data structures\n";
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
