/*! Tac Node header for EE360C Lab 1 */

#ifndef TAC_NODE_H
#define TAC_NODE_H

#include <vector>
#include <memory>

typedef struct adjacent_node {
    int32_t edge_weight;
    void* node;
    bool enabled;
} adjacent_node;

class tac_node {
public:
    tac_node(int32_t id, int32_t weight);
    auto reset_adjacency_enabled() -> void;

    auto add_adjacent_node(tac_node* node) -> void;

    auto get_adjacent_nodes() const
        -> const std::vector<std::shared_ptr<adjacent_node> >;
    auto get_weight() const -> const int32_t;
    auto get_id() const -> const int32_t;
    auto to_string() const -> const std::string;

private:
    std::vector<std::shared_ptr<adjacent_node> > adjacent_nodes;
    int32_t id;
    int32_t weight;
};

#endif  /* TAC_NODE_H */
