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

auto complex_bipartite_graph::generate_data_structures() -> void {

    /* Generate structures here */
    std::cout << "generating data structures\n";
}

auto complex_bipartite_graph::mwmcm() -> void {
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

    for (const auto tic : tic_nodes) {
        std::cout << "tic (" << tic->get_id() <<  ")\n";
        std::cout << "calculated " << tic->get_adjacent_nodes().size() << " adjacent nodes\n";
        for (const auto adj : tic->get_adjacent_nodes()) {
            std::cout << "    adj(" << adj->node->get_id() << ")\n";
        }
    }
}

auto complex_bipartite_graph::reset_edges() -> void {
    for (auto tic : tic_nodes) {
        tic->reset_adjacency_enabled();
    }

    for (auto tac : tac_nodes) {
        tac->reset_adjacency_enabled();
    }
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
