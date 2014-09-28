#ifndef TAC_NODE_H
#define TAC_NODE_H

#include <set>

typedef struct {
    int32_t edge_weight;
    tac_node* node;
} adjacent_node;

class tac_node {
public:
    tac_node(int32_t id, int32_t weight);
    auto add_adjacent_node(tac_node node) -> void;

    auto get_adjacent_nodes() const -> const std::set<adjacent_node>;
    auto get_weight() const -> const int32_t;
    auto get_id() const -> const int32_t;

private:
    std::set<adjacent_node> adjacent_nodes;
    int32_t id;
    int32_t weight;
}

#endif  /* TAC_NODE_H */
