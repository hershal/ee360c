/*! Tic node implementation for EE360C Lab 1 */

#include "tic_node.hpp"

tic_node::tic_node(int32_t id, int32_t weight,
                   int32_t min, int32_t max) :
    tac_node(id, weight) {

    this->min = min;
    this->max = max;
}

auto tic_node::get_min() const
    -> const int32_t { return this->min; }

auto tic_node::get_max() const
    -> const int32_t { return this->max; }
