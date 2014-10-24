/*! Undirected Graph Implementation for EE360C Lab 1 */

#include "undirected_graph.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

undirected_graph::undirected_graph() { }

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

    nodes[id0]->add_adjacent_node(nodes[id1], comm_time);
    nodes[id1]->add_adjacent_node(nodes[id0], comm_time);
}

auto undirected_graph::do_query(graph_query* query) -> void {

    if (!query->has_query()) {
        std::cout << "NO QUERY!\n";
        return;
    }

    dfs(query, query->get_device_i(), query->get_time_a());
}

auto undirected_graph::dfs(graph_query* query,
                           size_t curr_dev_id,
                           size_t curr_edge_weight) -> bool {

    if (curr_dev_id == query->get_device_j()) {
        /* Found */
        std::cout << "FOUND: " << curr_dev_id << "\n";
        return true;
    } else {
        auto adj_nodes = nodes[curr_dev_id]->get_adjacent_nodes();

        for (const auto an : adj_nodes) {
            if ((an->node->is_enabled()) &&
                (curr_edge_weight >= query->get_time_a()) &&
                (an->edge_weight >= curr_edge_weight) &&
                (an->edge_weight <= query->get_time_b())) {

                an->node->disable();
                query->push_trace(curr_dev_id, an->node->get_id(), an->edge_weight);
                std::cout << "    pushing: i: " << curr_dev_id
                          << " j: " << an->node->get_id()
                          << " w: " << an->edge_weight << "\n";

                if (dfs(query, an->node->get_id(), an->edge_weight)) {
                    return true;
                } else {
                    query->pop_trace();
                }

                /* Not found, then backtrack */
                std::cout << "    backtracking: " << curr_dev_id << "\n";
            }
        }
    }
    return false;
}

auto undirected_graph::reset_nodes() -> void {

    for (const auto n : nodes) { n->reset(); }
}

auto undirected_graph::to_string() const
    -> const std::string {

    std::stringstream str;
    for (const auto n : nodes) {
        str << n->to_string() << "\n";
    }

    return str.str();
}
