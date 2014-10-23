/*! Graph Query Results Wrapper Implementation */

#include "graph_query.hpp"

#include <sstream>

graph_query::graph_query() { }

auto graph_query::add_query(
    const size_t device_i, const size_t device_j,
    const uint32_t time_a, const uint32_t time_b) -> void {

    this->device_i = device_i;
    this->device_j = device_j;
    this->time_a = time_a;
    this->time_b = time_b;
}

auto graph_query::do_query(const undirected_graph* graph) -> void {

    /* DO WORK */
}

auto graph_query::to_string() const -> const std::string {

    std::stringstream stb;

    /* DO WORK */

    return stb.str();
}
