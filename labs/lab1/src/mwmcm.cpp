/*! MWMCM Results Wrapper Implementation */

#include "mwmcm.hpp"

#include <sstream>

mwmcm::mwmcm() {
    weight = 0;
}

auto mwmcm::add_association(int32_t tic, int32_t tac, int32_t weight) -> void {
    tactic_map[tac] = tic;
    this->weight += weight;
}

auto mwmcm::get_weight() const -> const int32_t {
    return weight;
}

auto mwmcm::to_string() const -> const std::string {

    std::stringstream stb;

    for (const auto tactic : tactic_map) {
        stb << tactic.second << ":" << tactic.first;
        stb << " ";
    }
    return stb.str();
}

auto mwmcm::operator<(mwmcm other) const -> bool {
    /* return weight < other.get_weight(); */

    /* Stupid lexicographical order */
    return to_string() < other.to_string();
}
