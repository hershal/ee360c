/*! Graph Query Results Wrapper Implementation */

#include "graph_query.hpp"

#include <sstream>

graph_query::graph_query() {
    this->query_set = false;
}

auto graph_query::add_query(
    const size_t device_i, const size_t device_j,
    const uint32_t time_a, const uint32_t time_b) -> void {

    this->device_i = device_i;
    this->device_j = device_j;
    this->time_a = time_a;
    this->time_b = time_b;
    this->query_set = true;
}

auto graph_query::do_query(const undirected_graph* graph) -> void {

    if (!this->query_set) {
        return;
    }

    /* DO WORK */
}

auto graph_query::has_query() const -> const bool {
    return this->query_set;
}

auto graph_query::to_string() const -> const std::string {

    std::stringstream stb;

    /* DO WORK */
    stb << "U_i=" << device_i
        << " U_j=" << device_j
        << " T_a=" << time_a
        << " T_b=" << time_b
        << "\n";

    return stb.str();
}
