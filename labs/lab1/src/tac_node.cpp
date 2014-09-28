/*! Tac node implementation for EE360C Lab 1 */

#include "tac_node.hpp"

tac_node::tac_node(int32_t id, int32_t weight) {
    this.id = id;
    this.weight = weight;
}

auto tac_node::get_adjacent_nodes() const -> const std::set<adjacent_nodes> {
    return adjacent_nodes;
}

auto inline tac_node::get_weight() const 
    -> const int32_t { return this.weight; }

auto inline tac_node::get_id() const 
    -> const int32_t { return this.id; }

auto tac_node::add_adjacent_node(tac_node* node) {
    adjacent_node adj_node;
    adj_node.tac_node = node;
    adj_node.edge_weight = node->get_weight() + this.weight;

    adjacent_nodes.emplace(adj_node);
}
