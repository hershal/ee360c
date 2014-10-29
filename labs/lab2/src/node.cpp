/*! Node implementation for EE360C Lab 1 */

#include "node.hpp"

#include <sstream>

/* REMOVE ME */
#include <iostream>

node::node(size_t id) {
    this->id = id;
}

auto node::reset() -> void {
    for (const auto an : adjacent_nodes) {
        an->enabled = 1;
    }
}

auto node::add_adjacent_node(std::shared_ptr<node> nref, uint32_t edge_weight) -> void {
    adjacent_node adj_node;
    adj_node.nref = nref;
    adj_node.edge_weight = edge_weight;
    adj_node.enabled = true;
    adjacent_nodes.push_back(std::make_shared<adjacent_node>(adj_node));
    /* std::cout << "adding adjacent node to " */
    /*           << id << ": " */
    /*           << node->get_id() << " " */
    /*           << edge_weight << "     " */
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

auto node::get_id() const
    -> const int32_t { return this->id; }

auto node::is_enabled(int32_t adj_node_id) const
    -> const bool {

    /* TODO: Remove this loop somehow */
    /* I'm currently using a std::vector to store the nodes which are
       adjacent to the current node. I should probably make this a
       more effecient data structure, such as a hash but I'm not sure
       what implications that has toward the graph structure. I should
       definitely look into this. */
    for (const auto an : adjacent_nodes) {
        if (an->nref->get_id() == adj_node_id) {
            return an->enabled;
        }
    }

    /* If the adj_node_id was not found, return false */
    return false;
}

auto node::disable(int32_t adj_node_id) -> void {

    for (const auto an : adjacent_nodes) {
        if (an->nref->get_id() == adj_node_id) {
            an->enabled = 0;
        }
    }
}

auto node::to_string() const
    -> const std::string {

    std::stringstream str;
    str << ""
        << "id: " << this->get_id() << "\n";

    for (const auto a : adjacent_nodes) {
        str << "  id: " << a->nref->get_id() << "\n"
            << "  edge_weight: " << a->edge_weight << "\n"
            << "  enabled: " << a->enabled << "\n";
    }

    return str.str();
}
