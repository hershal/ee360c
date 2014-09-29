/*! Tac Node implementation for EE360C Lab 1 */

#include "tac_node.hpp"

#include <sstream>

/* REMOVE ME */
#include <iostream>

tac_node::tac_node(int32_t id, int32_t weight) {

    this->id = id;
    this->weight = weight;
}

auto tac_node::reset() -> void {
    this->enabled = 1;
}

auto tac_node::add_adjacent_node(std::shared_ptr<tac_node> node) -> void {
    adjacent_node adj_node;
    adj_node.node = node;
    adj_node.edge_weight = node->get_weight() + this->weight;
    adjacent_nodes.push_back(std::make_shared<adjacent_node>(adj_node));
    std::cout << "adding adjacent node to "
              << id << ": "
              << node->get_id() << " "
              << weight << "     "
              << adjacent_nodes.size() << "\n";
}

auto tac_node::sort_adjacent_nodes() -> void {
    std::sort(adjacent_nodes.begin(), adjacent_nodes.end(),
              [] (const std::shared_ptr<adjacent_node>& l, 
                  const std::shared_ptr<adjacent_node>& r) {
                  return l.get()->edge_weight > r.get()->edge_weight;
              });
}

auto tac_node::get_adjacent_nodes() const
    -> const std::vector<std::shared_ptr<adjacent_node> > {
    return adjacent_nodes;
}

auto tac_node::get_weight() const
    -> const int32_t { return this->weight; }

auto tac_node::get_id() const
    -> const int32_t { return this->id; }

auto tac_node::is_enabled() const
    -> const bool { return this->enabled; }

auto tac_node::disable() -> void { this->enabled = 0; }

auto tac_node::to_string() const
    -> const std::string {

    std::stringstream str;
    str << "tac "
        << "id: " << this->get_id() << "\t"
        << "weight: " << this->get_weight();

    return str.str();
}
