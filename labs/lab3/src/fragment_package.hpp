/*! Assembled Fragments Package header for EE360C Lab 3 */

#include "fragment.hpp"

#include <vector>

class fragment_package {
public:
    fragment_package();

    auto push_trace(fragment* fgmt) -> void;
    auto pop_trace() -> void;
    auto commit_trace() -> void;
    auto show_trace() -> void;
    auto show_packages() const -> void;
    auto get_current_traces() -> std::vector<fragment*>*;
    auto clear_traces() -> void;
private:
    std::vector<std::vector<fragment*> > packages;
    std::vector<fragment*> fragment_trace;
};
