/*! Assembled Fragments Package implementation for EE360C Lab 3 */

#include "fragment_package.hpp"

#include <sstream>
#include <iostream>

fragment_package::fragment_package() {
    /* Nothing to do here */
}

auto fragment_package::push_trace(fragment* fgmt) -> void {
    fragment_trace.push_back(fgmt);
}

auto fragment_package::pop_trace() -> fragment* {

    if (fragment_trace.size() == 0) { return 0; }

    fragment* fgmt_trace_removed = fragment_trace.back();
    fragment_trace.pop_back();
    return fgmt_trace_removed;

}

auto fragment_package::commit_trace() -> void {
    if (fragment_trace.size() > 0) {
        packages.emplace_back(fragment_trace);
        clear_traces();
    }
}

auto fragment_package::get_current_traces() -> std::vector<fragment*>* {
    return &fragment_trace;
}

auto fragment_package::clear_traces() -> void {
    fragment_trace.clear();
}

auto fragment_package::show_trace() const -> const std::string {

    if (fragment_trace.size() == 0) { return ""; }

    std::stringstream stb;

    for (const auto fgmt : fragment_trace) {
        stb << fgmt->to_string()->c_str() << " ";
    }

    return stb.str();
}

auto fragment_package::show_packages() const -> const std::string {

    std::stringstream stb;
    stb << packages.size() << "\n";
    for(const auto pkg : packages) {
        for (const auto fgmt : pkg) {
            stb << fgmt->to_string()->c_str() << " ";
        }
        stb << "\n";
    }

    return stb.str();
}
