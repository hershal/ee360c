/*! Graph Query Results Wrapper Header */

#ifndef GRAPH_QUERY_WRAPPER_H
#define GRAPH_QUERY_WRAPPER_H

#include <vector>
#include <string>

class graph_query {
public:
    graph_query();

    auto get_device_i() const -> const size_t;
    auto get_device_j() const -> const size_t;
    auto get_time_a() const -> const uint32_t;
    auto get_time_b() const -> const uint32_t;

    auto add_query(const size_t device_i, const size_t device_j,
                   const uint32_t time_a, const uint32_t time_b) -> void;

    auto has_query() const -> const bool;
    auto to_string() const -> const std::string;
private:
    size_t device_i;
    size_t device_j;
    uint32_t time_a;
    uint32_t time_b;
    bool query_set;
    std::vector<std::string> trace_list;
};

#endif  /* GRAPH_QUERY_WRAPPER_H */
