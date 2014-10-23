/*! Undirected Graph Implementation for EE360C Lab 1 */

#include "undirected_graph.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

undirected_graph::undirected_graph(size_t num_nodes) {

    nodes.reserve(num_nodes);
    for (size_t i=0; i<num_nodes; ++i) {
        add_node(i);
    }
}

auto undirected_graph::add_node(size_t id) -> void {

    nodes.emplace_back(std::make_shared<node>(id));
}

auto undirected_graph::add_connection(
    size_t id0, size_t id1, uint32_t comm_time) -> void {

    nodes[id0].add_adjacent_node(nodes[id1], comm_time);
    nodes[id1].add_adjacent_node(nodes[id0], comm_time);
}

auto undirected_graph::reset_nodes() -> void {

    for (const auto n : nodes) { node->reset(); }
}

auto undirected_graph::to_string() const
    -> const std::string {

    std::stringstream str;
    for (const auto n : nodes) {
        str << n->to_string() << "\n";
    }

    return str.str();
}
