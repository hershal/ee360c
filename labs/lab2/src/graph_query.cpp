/*! Graph Query Results Wrapper Implementation */

#include "graph_query.hpp"

#include <sstream>

graph_query::graph_query() {
    this->query_set = false;
}

auto graph_query::get_device_i() const -> const size_t { return this->device_i; }
auto graph_query::get_device_j() const -> const size_t { return this->device_j; }
auto graph_query::get_time_a() const -> const uint32_t { return this->time_a; }
auto graph_query::get_time_b() const -> const uint32_t { return this->time_b; }

auto graph_query::add_query(
    const size_t device_i, const size_t device_j,
    const uint32_t time_a, const uint32_t time_b) -> void {

    this->device_i = device_i;
    this->device_j = device_j;
    this->time_a = time_a;
    this->time_b = time_b;
    this->query_set = true;
}

auto graph_query::has_query() const -> const bool {
    return this->query_set;
}

auto graph_query::push_trace(
    size_t device_i, size_t device_j,
    uint32_t edge_weight) -> void {

    trace t;
    t.device_i = device_i;
    t.device_j = device_j;
    t.edge_weight = edge_weight;

    trace_list.push_back(t);
}

auto graph_query::pop_trace() -> void {
    trace_list.pop_back();
}

auto graph_query::clear_traces() -> void {
    trace_list.clear();
}

auto graph_query::to_string() const -> const std::string {

    std::stringstream stb;

    /* DO WORK */
    if (has_query()) {
        stb << "Query:\n"
            << "  U_i=" << device_i
            << "  U_j=" << device_j
            << "  T_a=" << time_a
            << "  T_b=" << time_b
            << "\n";
        if (trace_list.size() > 0) {
            stb << "Trace list:\n";
            for (const auto t : trace_list) {
                stb << "  " << t.device_i
                    << " " << t.device_j
                    << " " << t.edge_weight
                    << "\n";
            }
        } else {
            stb << "No traces.\n";
        }
    }

    return stb.str();
}
