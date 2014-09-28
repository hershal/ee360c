/*! Tic node implementation for EE360C Lab 1 */

#include "tic_node.hpp"

#include <sstream>

tic_node::tic_node(int32_t id,
                   int32_t min, int32_t max,
                   int32_t weight) :
    tac_node(id, weight) {

    this->min = min;
    this->max = max;
}

auto tic_node::get_min() const
    -> const int32_t { return this->min; }

auto tic_node::get_max() const
    -> const int32_t { return this->max; }

auto tic_node::to_string() const
    -> const std::string {

    std::stringstream str;
    str << "tic " <<
        << "id: " << this->get_id() << "\t"
        << "weight: " << this->get_weight() << "\t"
        << "min: " << this->get_min() << "\t"
        << "max: " << this->get_max();

    return str.str();
}
