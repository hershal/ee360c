/*! Complex Bipartite Graph Header for EE360C Lab 1 */

#ifndef COMPLEX_BIPARTITE_GRAPH_H
#define COMPLEX_BIPARTITE_GRAPH_H

#include "tac_node.hpp"
#include "tic_node.hpp"

#include <map>
#include <utility>
#include <vector>
#include <memory>

class complex_bipartite_graph {
public:
    complex_bipartite_graph(size_t num_tics, size_t num_tacs);
    auto mwmcm() -> void;
    auto generate_lehmers() -> void;
    auto calculate_adjacency_lists() -> void;
    auto add_tic(int32_t id, int32_t weight, int32_t min, int32_t max) -> void;
    auto add_tac(int32_t id, int32_t weight) -> void;
    auto to_string() const -> const std::string;
    auto generate_weight_map() -> void;
    auto num_lehmers() -> size_t;
    auto generate_lehmer_for_idx(size_t idx) -> void;

private:
    auto reset() -> void;

    auto get_tic_with_id(int32_t id) const -> std::shared_ptr<tic_node>;
    auto get_tac_with_id(int32_t id) const -> std::shared_ptr<tac_node>;

    std::vector<std::shared_ptr<tic_node> > tic_nodes;
    std::vector<std::shared_ptr<tac_node> > tac_nodes;

    /* Maps the index of the calculation to the weight-cardinality */
    std::map<size_t, int32_t> index_weight_map;
    std::map<size_t, std::vector<int32_t> > index_lehmer_map;
};

#endif  /* COMPLEX_BIPARTITE_GRAPH_H */
