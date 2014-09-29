/*! MWMCM Results Wrapper Header */

#ifndef MWMCM_WRAPPER_H
#define MWMCM_WRAPPER_H

#include "tac_node.hpp"
#include "tic_node.hpp"

#include <map>

class mwmcm {
public:
    mwmcm();
    auto add_association(int32_t tic, int32_t tac, int32_t weight) -> void;
    auto get_weight() const -> const int32_t;
    auto to_string() const -> const std::string;
    auto operator<(mwmcm other) const -> bool;
private:
    /* NOTE: The order here is REVERSED! */
    std::map<int32_t, int32_t> tactic_map;
    int32_t weight;
};

#endif  /* MWMCM_WRAPPER_H */
