/*! Complex Bipartite Graph Implementation for EE360C Lab 1 */

#include "complex_bipartite_graph.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

complex_bipartite_graph::complex_bipartite_graph(
    uint32_t num_tics, uint32_t num_tacs) {

    tic_nodes.reserve(num_tics);
    tic_nodes.reserve(num_tacs);
}

auto complex_bipartite_graph::add_tic(
    int32_t id, int32_t weight, int32_t min, int32_t max) 
    -> void {

    tic_nodes.emplace_back(id, min, max, weight);
}

auto complex_bipartite_graph::add_tac(
    int32_t id, int32_t weight)
    -> void {

    tac_nodes.emplace_back(id, weight);
}

auto complex_bipartite_graph::generate_data_structures() -> void {

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

auto complex_bipartite_graph::to_string() const
    -> const std::string {

    std::stringstream str;
    for (const auto tic : tic_nodes) {
        str << tic.to_string() << "\n";
    }

    for (const auto tac : tac_nodes) {
        str << tac.to_string() << "\n";
    }

    return str.str();
}
