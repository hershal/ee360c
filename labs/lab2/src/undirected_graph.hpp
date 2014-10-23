/*! Undirected Graph Header for EE360C Lab 2 */

#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "node.hpp"

#include <map>
#include <vector>
#include <set>
#include <memory>
#include <utility>

class undirected_graph {
public:
    undirected_graph(size_t num_nodes);
    auto add_connection(size_t id0, size_t id1, uint32_t comm_time) -> void;
    auto add_node(size_t id) -> void;
    auto to_string() const -> const std::string;

private:
    auto reset_nodes() -> void;

    std::vector<std::shared_ptr<node> > nodes;
};

#endif  /* UNDIRECTED_GRAPH_H */
