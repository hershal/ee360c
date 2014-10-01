/*! MWMCM Results Wrapper Implementation */

#include "mwmcm.hpp"

#include <sstream>

mwmcm::mwmcm() {
    this->weight = 0;
    this->cardinality = 0;
}

auto mwmcm::add_association(int32_t tic, int32_t tac, int32_t weight) -> void {
    tactic_map[tac] = tic;
    tictac_map[tic] = tac;
    this->weight += weight;
    ++this->cardinality;
}

auto mwmcm::get_tictac_map() const 
    -> const std::map<int32_t, int32_t> {
    return tictac_map;
}

auto mwmcm::get_tactic_map() const 
    -> const std::map<int32_t, int32_t> {
    return tactic_map;
}

auto mwmcm::get_weight() const -> const int32_t {
    return weight;
}

auto mwmcm::get_cardinality() const -> const size_t {
    return cardinality;
}

auto mwmcm::to_string() const -> const std::string {

    std::stringstream stb;

    for (const auto tactic : tactic_map) {
        stb << tactic.second << ":" << tactic.first;
        stb << " ";
    }
    return stb.str();
}
