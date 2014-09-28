#ifndef TIC_NODE_H
#define TIC_NODE_H

#include "tac_node.hpp"
#include <set>

class tic_node : public tac_node {
public:
    tic_node(int32_t id, int32_t weight, int32_t min, int32_t max);
    auto get_min() const -> const int32_t;
    auto get_max() const -> const int32_t;

private:
    int32_t min;
    int32_t max;
}

#endif  /* TAC_NODE_H */
