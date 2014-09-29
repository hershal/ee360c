/*! Complex Bipartite Graph Implementation for EE360C Lab 1 */

#include "complex_bipartite_graph.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

complex_bipartite_graph::complex_bipartite_graph(
    size_t num_tics, size_t num_tacs) {

    tic_nodes.reserve(num_tics);
    tic_nodes.reserve(num_tacs);
}

auto complex_bipartite_graph::add_tic(
    int32_t id, int32_t weight, int32_t min, int32_t max)
    -> void {

    tic_nodes.emplace_back(std::make_shared<tic_node>(id, min, max, weight));
}

auto complex_bipartite_graph::add_tac(
    int32_t id, int32_t weight)
    -> void {

    tac_nodes.emplace_back(std::make_shared<tac_node>(id, weight));
}

auto complex_bipartite_graph::generate_lehmers() -> void {

    /* Generate structures here */
    std::cout << "generating data structures\n";

    for (auto i=0; i<num_lehmers(); ++i) {
        generate_lehmer_for_idx(i);    
    }
}

auto complex_bipartite_graph::find_mwmcms() -> void {
    /* Do the MWMCM algorithm here */
}

auto complex_bipartite_graph::calculate_adjacency_lists() -> void {
    /* Calculate the adjacency lists */

    for (auto tic : tic_nodes) {
        for (auto tac : tac_nodes) {
            if (tac->get_id() <= tic->get_max() && tac->get_id() >= tic->get_min()) {

                std::cout << tic->get_id() << " -> " << tac->get_id() << "\n";

                tic->add_adjacent_node(tac);
                tac->add_adjacent_node(tic);
            }
        }
    }

    for (auto tic : tic_nodes) { tic->sort_adjacent_nodes(); }
    for (auto tac : tac_nodes) { tac->sort_adjacent_nodes(); }

    for (const auto tic : tic_nodes) {
        std::cout << "tic (" << tic->get_id() <<  ")\n";
        std::cout << "calculated " << tic->get_adjacent_nodes().size() << " adjacent nodes\n";
        for (const auto adj : tic->get_adjacent_nodes()) {
            std::cout << "    adj(" << adj->node->get_id() << ", " << adj->edge_weight << ")\n";
        }
    }
}

auto complex_bipartite_graph::reset() -> void {

    for (auto tic : tic_nodes) { tic->reset(); }
    for (auto tac : tac_nodes) { tac->reset(); }
}

auto complex_bipartite_graph::to_string() const
    -> const std::string {

    std::stringstream str;
    for (const auto tic : tic_nodes) {
        str << tic->to_string() << "\n";
    }

    for (const auto tac : tac_nodes) {
        str << tac->to_string() << "\n";
    }

    return str.str();
}

auto complex_bipartite_graph::get_tic_with_id(int32_t id) const -> std::shared_ptr<tic_node> {

    /* node ids are supposed to be unique */
    for(const auto tic : tic_nodes) {
        if (tic->get_id() == id) {
            return tic;
        }
    }

    std::shared_ptr<tic_node> nobody = 0;
    return nobody;
}

auto complex_bipartite_graph::get_tac_with_id(int32_t id) const -> std::shared_ptr<tac_node> {

    /* node ids are supposed to be unique */
    for(const auto tac : tac_nodes) {
        if (tac->get_id() == id) {
            return tac;
        }
    }

    std::shared_ptr<tac_node> nobody = 0;
    return nobody;
}

auto complex_bipartite_graph::generate_weight_map() -> void {

    for (const auto idxlehmer : index_lehmer_map) {
        const auto idx = idxlehmer.first;
        const auto lehmer = idxlehmer.second;

        reset();

        int32_t tot_weight = 0;
        mwmcm results;

        /* TODO: What if two edges have the same weight?  */
        for (const auto id : lehmer) {
            const auto tic = get_tic_with_id(id);

            /* The vector is sorted */
            for (auto adj_node : tic->get_adjacent_nodes()) {
                /* Picked the highest one */
                if (tic->is_enabled() && adj_node->node->is_enabled()) {
                    tic->disable();
                    adj_node->node->disable();
                    results.add_association(id, adj_node->node->get_id(), adj_node->edge_weight);
                    tot_weight += adj_node->edge_weight;
                }
            }
        }
        
        /* Since we're forced to use lexicographical order... */
        weight_mwmcm_map[results.get_weight()].insert(results.to_string());
    }

    const auto highest_match = weight_mwmcm_map.rbegin();

    std::cout << "highest match" << highest_match->first << "\n";

    std::cout << highest_match->second.size() << "\n";
    for (const auto match : highest_match->second) {
        std::cout << match << "\n";
    }
}

inline size_t factorial(size_t x) {
  return (x == 1 ? x : x * factorial(x - 1));
}

auto complex_bipartite_graph::num_lehmers() -> size_t {
    return factorial(tic_nodes.size());
}

auto complex_bipartite_graph::generate_lehmer_for_idx(size_t idx) -> void {

    std::vector<int32_t> lehmer_ids;
    lehmer_ids.reserve(tic_nodes.size());

    size_t index = idx;

    std::transform(this->tic_nodes.begin(), this->tic_nodes.end(), std::back_inserter(lehmer_ids),
                   [] (std::vector<std::shared_ptr<tic_node> >::value_type& node) {
                       return node->get_id(); });

    std::sort(lehmer_ids.begin(), lehmer_ids.end(), std::less<int32_t>());

    size_t n = lehmer_ids.size();
    uint32_t radix = 1;
    for (uint32_t i=2; i<lehmer_ids.size(); ++i) { radix*= i; }

    auto beg = lehmer_ids.begin();
    for (uint32_t i=0; i<n; ++i) {
        int32_t digit = index / radix;
        std::rotate(beg, beg + digit, beg + digit + 1);
        ++beg;
        index %= radix;
        if (i + 1 != n) {
            radix /= (n - i - 1);
        }
    }

    index_lehmer_map[idx] = lehmer_ids;

    std::cout << "lehmer(" << idx << "): ";
    for (const auto leh : lehmer_ids) {
        std::cout << leh << " ";
    }
    std::cout << "\n";
}
