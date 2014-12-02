/*! Fragment implementation for EE360C Lab 3 */

#include "fragment.hpp"

/* REMOVE ME */
#include <stdio.h>

fragment::fragment(std::string payload) {
    this->payload = payload;
    this->enabled = true;
    this->has_changed = true;
    printf("Fragment Added: %s\n", payload.c_str());
}

auto fragment::add_out_fragment(fragment* fgmt) -> void {
    out_fragments.push_back(fgmt);
    this->has_changed = 1;
}

auto fragment::add_in_fragment(fragment* fgmt) -> void {
    in_fragments.push_back(fgmt);
    this->has_changed = 1;
}

auto fragment::is_enabled() const -> const bool {
    return enabled;
}

auto fragment::disable() -> void {
    this->enabled = false;
}

auto fragment::reset() -> void {
    this->enabled = true;
    this->has_changed = 1;
    in_fragments.clear();
    out_fragments.clear();
}

auto fragment::out_string() -> const std::string* {

    /* Regenerate the concatenation string */
    if (has_changed) {
        std::string conc = "";

        for (const auto fgmt : in_fragments) {
            conc += *(fgmt->to_string());
            conc += " ";
        }
        conc += payload;
        conc += " ";
        for (const auto fgmt : out_fragments) {
            conc += *(fgmt->to_string());
            conc += " ";
        }

        this->conc_string_cached = conc;
        this->has_changed = 0;
    }

    return &conc_string_cached;
}

auto fragment::to_string() const -> const std::string* {
    return &payload;
}
