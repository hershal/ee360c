/*! Complex Bipartite Graph Header for EE360C Lab 1 */

#ifndef COMPLEX_BIPARTITE_GRAPH_H
#define COMPLEX_BIPARTITE_GRAPH_H

#include "tac_node.hpp"
#include "tic_node.hpp"

#include <map>
#include <utility>

class complex_bipartite_graph {
public:
    complex_bipartite_graph();
    auto generate_data_structures(std::string file_input) -> void;
    auto mwmcm() -> void;

private:
    auto calculate_adjacency_lists() -> void;
    auto reset_edges() -> void;

    std::set<tic_node> tic_nodes;
    std::set<tac_node> tac_nodes;

    /* Maps the index of the calculation to the weight-cardinality */
    std::map<uint32_t, std::pair<uint32_t, int32_t> > weight_cardinality_map;
};

#endif  /* COMPLEX_BIPARTITE_GRAPH_H */
