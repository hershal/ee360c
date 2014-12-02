/*! Assembled Fragments Package implementation for EE360C Lab 3 */

#include "fragment_package.hpp"

/* TODO: REMOVE ME */
#include <stdio.h>
/* END TODO */

fragment_package::fragment_package() {
    /* Nothing to do here */
}

auto fragment_package::push_trace(fragment* fgmt) -> void {
    fragment_trace.push_back(fgmt);
}

auto fragment_package::pop_trace() -> void {
    fragment_trace.pop_back();
}

auto fragment_package::commit_trace() -> void {
    packages.emplace_back(fragment_trace);
    clear_traces();
}

auto fragment_package::get_current_traces() -> std::vector<fragment*>* {
    return &fragment_trace;
}

auto fragment_package::clear_traces() -> void {
    fragment_trace.clear();
}

/* TODO: CONVERT TO STRING GENERATION INSTEAD OF PRINTF'ing */
auto fragment_package::show_trace() -> void {
    for (const auto fgmt : fragment_trace) {
        printf("%s ", fgmt->to_string()->c_str());
    }
}
/* END TODO */

/* TODO: CONVERT TO STRING GENERATION INSTEAD OF PRINTF'ing */
auto fragment_package::show_packages() const -> void {

    printf("%lu\n", packages.size());
    for(const auto pkg : packages) {
        for (const auto fgmt : pkg) {
            printf("%s ", fgmt->to_string()->c_str());
        }
        printf("\n");
    }
}
/* END TODO */
