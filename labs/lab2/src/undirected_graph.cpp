/*! Undirected Graph Implementation for EE360C Lab 1 */

#include "undirected_graph.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

undirected_graph::undirected_graph(
    size_t num_tics, size_t num_tacs) {

    tic_nodes.reserve(num_tics);
    tic_nodes.reserve(num_tacs);
}

auto undirected_graph::add_tic(
    int32_t id, int32_t weight, int32_t min, int32_t max)
    -> void {

    tic_nodes.emplace_back(std::make_shared<tic_node>(id, min, max, weight));
}

auto undirected_graph::add_tac(
    int32_t id, int32_t weight)
    -> void {

    tac_nodes.emplace_back(std::make_shared<tac_node>(id, weight));
}

auto undirected_graph::reset() -> void {

    for (auto tic : tic_nodes) { tic->reset(); }
    for (auto tac : tac_nodes) { tac->reset(); }
}

auto undirected_graph::to_string() const
    -> const std::string {

    std::stringstream str;
    for (const auto n : nodes) {
        str << n->to_string() << "\n";
    }

    return str.str();
}
