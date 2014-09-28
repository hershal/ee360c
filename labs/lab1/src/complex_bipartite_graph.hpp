/*! Complex Bipartite Graph Header for EE360C Lab 1 */

#ifndef COMPLEX_BIPARTITE_GRAPH_H
#define COMPLEX_BIPARTITE_GRAPH_H

#include "tac_node.hpp"
#include "tic_node.hpp"

#include <map>
#include <utility>
#include <vector>

class complex_bipartite_graph {
public:
    complex_bipartite_graph(uint32_t num_tics, uint32_t num_tacs);
    auto mwmcm() -> void;
    auto generate_data_structures() -> void;
    auto add_tic(int32_t id, int32_t weight, int32_t min, int32_t max) -> void;
    auto add_tac(int32_t id, int32_t weight) -> void;
    auto to_string() const -> const std::string;

private:
    auto calculate_adjacency_lists() -> void;
    auto reset_edges() -> void;

    std::vector<tic_node> tic_nodes;
    std::vector<tac_node> tac_nodes;

    /* Maps the index of the calculation to the weight-cardinality */
    std::map<uint32_t, std::pair<uint32_t, int32_t> > weight_cardinality_map;
};

#endif  /* COMPLEX_BIPARTITE_GRAPH_H */
