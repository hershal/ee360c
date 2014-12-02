/*! Fragment header for EE360C Lab 3 */

#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <string>
#include <vector>

class fragment {
public:
    fragment(std::string payload);

    auto add_in_fragment(fragment* fgmt) -> void;
    auto add_out_fragment(fragment* fgmt) -> void;

    auto is_enabled() const -> const bool;
    auto disable() -> void;
    auto reset() -> void;
    auto to_string() const -> const std::string*;
    auto out_string() -> const std::string*;

private:
    std::string payload;
    bool enabled;
    std::vector<fragment*> in_fragments;
    std::vector<fragment*> out_fragments;
    std::string conc_string_cached;
    bool has_changed;
};

#endif  /* FRAGMENT_H */
