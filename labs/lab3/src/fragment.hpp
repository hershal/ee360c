/*! Fragment header for EE360C Lab 3 */

#ifndef FRAGMENT_H
#define FRAGMENT_H

#include <string>

class fragment {
public:
    fragment(std::string payload);

    auto is_enabled() const -> const bool;
    auto disable() -> void;
    auto reset() -> void;
    auto to_string() const -> const std::string*;

private:
    std::string payload;
    bool enabled;
};

#endif  /* FRAGMENT_H */
