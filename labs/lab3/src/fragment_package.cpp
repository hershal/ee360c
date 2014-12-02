/*! Assembled Fragments Package implementation for EE360C Lab 3 */

#include "fragment_package.hpp"

#include <sstream>
#include <iostream>

fragment_package::fragment_package() {
    /* Nothing to do here */
}

auto fragment_package::push_trace(fragment* base, fragment* fgmt) -> void {
    if (base == 0) {
        fragment_trace.push_back(fgmt);
    } else {
        base->add_out_fragment(fgmt);
        fgmt->add_in_fragment(base);
    }
}

auto fragment_package::pop_trace() -> fragment* {

    /* DEPRECATED */

    /* if (fragment_trace.size() == 0) { return 0; } */
    /*  */
    /* fragment* fgmt_trace_removed = fragment_trace.back(); */
    /* fragment_trace.pop_back(); */
    /* return fgmt_trace_removed; */

    return 0;
}

auto fragment_package::get_adjacent_fragments
    (const std::string* desired_string, std::vector<fragment*> possible_fragments,
     fragment* fgmt) const -> const std::vector<fragment*> {

    std::vector<fragment*> adjacent_fragments;

    std::string base_assembled = *(fgmt->out_string());
    for (const auto fgmt : possible_fragments) {
        if (fgmt->is_enabled()
            && (desired_string->find(base_assembled + *(fgmt->to_string())) == 0)) {

            adjacent_fragments.push_back(fgmt);
        }
    }

    return adjacent_fragments;
}

auto fragment_package::commit_trace() -> void {

    /* DEPRECATED */

    /* if (fragment_trace.size() > 0) { */
    /*     packages.emplace_back(fragment_trace); */
    /*     clear_traces(); */
    /* } */
}

auto fragment_package::get_current_traces() -> std::vector<fragment*>* {
    return &fragment_trace;
}

auto fragment_package::clear_traces() -> void {
    fragment_trace.clear();
}

auto fragment_package::show_traces() const -> const std::string {

    std::stringstream stb;

    stb << fragment_trace.size() << "\n";
    for (const auto fgmt : fragment_trace) {
        stb << fgmt->out_string()->c_str() << "\n";
    }

    return stb.str();
}

auto fragment_package::show_packages() const -> const std::string {

    /* DEPRECATED */

    std::stringstream stb;
    /* stb << packages.size() << "\n"; */
    /* for(const auto pkg : packages) { */
    /*     for (const auto fgmt : pkg) { */
    /*         stb << fgmt->to_string()->c_str() << " "; */
    /*     } */
    /*     stb << "\n"; */
    /* } */

    return stb.str();
}
