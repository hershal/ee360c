/*! Undirected Graph Header for EE360C Lab 2 */

#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "node.hpp"
#include "graph_query.hpp"

#include <map>
#include <vector>
#include <set>
#include <memory>
#include <utility>

class undirected_graph {
public:
    undirected_graph();
    undirected_graph(size_t num_nodes);
    auto add_connection(std::string fragment) -> void;
    auto add_node(size_t id) -> void;
    auto do_query(graph_query* query) -> void;

    auto dfs(graph_query* query, size_t curr_dev_id,
             size_t curr_edge_weight) -> bool;

    auto to_string() const -> const std::string;

private:
    auto reset_nodes() -> void;
    std::vector<std::shared_ptr<node> > nodes;
};

#endif  /* UNDIRECTED_GRAPH_H */
