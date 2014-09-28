/*! Tac Node implementation for EE360C Lab 1 */

#include "tac_node.hpp"

#include <sstream>

tac_node::tac_node(int32_t id, int32_t weight) {

    this->id = id;
    this->weight = weight;
}

auto tac_node::reset_adjacency_enabled() -> void {
    for (auto adj_node : adjacent_nodes) {
        adj_node->enabled = 1;
    }
}

auto tac_node::add_adjacent_node(tac_node* node) -> void {
    adjacent_node adj_node;
    adj_node.node = node;
    adj_node.edge_weight = node->get_weight() + this->weight;

    adjacent_nodes.emplace(std::make_shared<adjacent_node>(adj_node));
}

auto tac_node::get_adjacent_nodes() const
    -> const std::set<std::shared_ptr<adjacent_node> > {
    return adjacent_nodes;
}

auto inline tac_node::get_weight() const
    -> const int32_t { return this->weight; }

auto inline tac_node::get_id() const
    -> const int32_t { return this->id; }

auto tac_node::to_string() const
    -> const std::string {

    std::stringstream str;
    str << "tac "
        << "id: " << this->get_id() << "\t"
        << "weight: " << this->get_weight();

    return str.str();
}
