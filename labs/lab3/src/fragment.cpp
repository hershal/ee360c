/*! Fragment implementation for EE360C Lab 3 */

#include "fragment.hpp"

/* REMOVE ME */
#include <stdio.h>

fragment::fragment(std::string payload) {
    this->payload = payload;
    this->enabled = true;

    printf("Fragment Added: %s\n", payload);
}

auto fragment::is_enabled() const -> const bool {
    return enabled;
}

auto fragment::disable() -> void {
    this->enabled = false;
}

auto fragment::reset() -> void {
    this->enabled = true;
}

auto fragment::to_string() const -> const std::string {
    return payload;
}
