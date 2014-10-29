/*! Node header for EE360C Lab 1 */

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <memory>

class node {
public:
    typedef struct adjacent_node {
        int32_t edge_weight;
        std::shared_ptr<node> nref;
        bool enabled;
    } adjacent_node;

    node(size_t id);
    auto reset() -> void;

    auto add_adjacent_node(std::shared_ptr<node> node, uint32_t edge_weight) -> void;
    auto sort_adjacent_nodes() -> void;

    auto get_adjacent_nodes() const
        -> const std::vector<std::shared_ptr<adjacent_node> >;
    auto get_id() const -> const int32_t;
    auto is_enabled(int32_t id) const -> const bool;
    auto disable(int32_t id) -> void;
    auto to_string() const -> const std::string;

private:
    std::vector<std::shared_ptr<adjacent_node> > adjacent_nodes;
    int32_t id;
};

#endif  /* NODE_H */
