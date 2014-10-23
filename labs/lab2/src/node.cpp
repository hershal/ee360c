/*! Node implementation for EE360C Lab 1 */

#include "node.hpp"

#include <sstream>

/* REMOVE ME */
#include <iostream>

node::node(int32_t id, int32_t weight) {

    this->id = id;
    this->weight = weight;
}

auto node::reset() -> void {
    this->enabled = 1;
}

auto node::add_adjacent_node(std::shared_ptr<node> node) -> void {
    adjacent_node adj_node;
    adj_node.node = node;
    adj_node.edge_weight = node->get_weight() + this->weight;
    adjacent_nodes.push_back(std::make_shared<adjacent_node>(adj_node));
    /* std::cout << "adding adjacent node to " */
    /*           << id << ": " */
    /*           << node->get_id() << " " */
    /*           << weight << "     " */
    /*           << adjacent_nodes.size() << "\n"; */
}

auto node::sort_adjacent_nodes() -> void {
    std::sort(adjacent_nodes.begin(), adjacent_nodes.end(),
              [] (const std::shared_ptr<adjacent_node>& l,
                  const std::shared_ptr<adjacent_node>& r) {
                  return l.get()->edge_weight > r.get()->edge_weight;
              });
}

auto node::get_adjacent_nodes() const
    -> const std::vector<std::shared_ptr<adjacent_node> > {
    return adjacent_nodes;
}

auto node::get_weight() const
    -> const int32_t { return this->weight; }

auto node::get_id() const
    -> const int32_t { return this->id; }

auto node::is_enabled() const
    -> const bool { return this->enabled; }

auto node::disable() -> void { this->enabled = 0; }

auto node::to_string() const
    -> const std::string {

    std::stringstream str;
    str << ""
        << "id: " << this->get_id() << "\t"
        << "weight: " << this->get_weight();

    return str.str();
}
