/*! Undirected Graph Header for EE360C Lab 2 */

#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "tac_node.hpp"
#include "tic_node.hpp"
#include "mwmcm.hpp"

#include <map>
#include <vector>
#include <set>
#include <memory>
#include <utility>

class undirected_graph {
public:
    undirected_graph(size_t num_tics, size_t num_tacs);
    auto add_node(int32_t id, int32_t weight, int32_t min, int32_t max) -> void;
    auto to_string() const -> const std::string;

private:
    auto reset() -> void;

    std::vector<std::shared_ptr<node> > nodes;
};

#endif  /* UNDIRECTED_GRAPH_H */
