/*! Graph Query Results Wrapper Header */

#ifndef GRAPH_QUERY_WRAPPER_H
#define GRAPH_QUERY_WRAPPER_H

#include <vector>
#include <string>
#include "undirected_graph.hpp"

class graph_query {
public:
    graph_query();
    auto add_query(const size_t device_i, const size_t device_j,
                   const uint32_t time_a, const uint32_t time_b) -> void;
    auto do_query(const undirected_graph* graph) -> void;
    auto to_string() const -> const std::string;
private:
    size_t device_i;
    size_t device_j;
    uint32_t time_a;
    uint32_t time_b;
};

#endif  /* GRAPH_QUERY_WRAPPER_H */
