/*! Fragment Assembler implementation for EE360C Lab 3 */

#include "fragment_assembler.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

fragment_assembler::fragment_assembler() {
    /* Nothing to do here */
}


auto fragment_assembler::add_fragment(fragment* fgmt) -> void {
    fragments.push_back(fgmt);
}

auto fragment_assembler::assemble(const std::string* desired_string)
    -> fragment_package* {

    fragment_package* pkg = new fragment_package();

    /* for (const auto fgmt : fragments) { */
        bfs(desired_string, pkg);
    /* } */

    return pkg;
}

auto fragment_assembler::chop_assemble
    (const std::string* desired_string,
     const size_t begin_index,
     std::vector<fragment*>* recurrence_vector) -> bool {



    return false;
}

auto fragment_assembler::begins_with
(const std::string* desired, const std::string* fragment_string) -> size_t {

    if (desired->find(*fragment_string) == 0) {
        return fragment_string->size();
    } else {
        return 0;
    }
}


auto fragment_assembler::to_string() const -> const std::string {

    std::stringstream stb;

    for (const auto fgmt : fragments) {
        stb << fgmt->to_string() << "\n";
    }

    return stb.str();
}

auto fragment_assembler::bfs
    (const std::string* desired_string, fragment_package* pkg) -> void {

    /* Copy */
    std::vector<fragment*> possible_fragments = fragments;

    /* First pass */
    for (auto fgmt : possible_fragments) {
        if (desired_string->find(*(fgmt->to_string())) == 0) {
            pkg->push_trace(0, fgmt);
        }
    }

    std::cout << pkg->show_traces() << "\n";

    std::vector<fragment*> level;

    for (auto fgmt : *(pkg->get_current_traces())) {
        const auto adj_vec =
            pkg->get_adjacent_fragments(desired_string, possible_fragments, fgmt);

        for (auto adj_fgmt : adj_vec) {
            /* Don't know what to do here... */
            /* pkg-> */
        }
    }
}

auto print_recurrence_vector(std::vector<fragment*> recurrence_vector)
    -> const std::string {

    std::stringstream stb;

    for (const auto fgmt : recurrence_vector) {
        stb << fgmt->to_string()->c_str() << " ";
    }

    return stb.str();
}

auto fragment_assembler::check_assembly
(const std::string* desired_string,
 const std::vector<fragment*>* fragments) const -> bool {

    std::string concat = "";

    for (const auto fgmt : *fragments) {
        concat += *(fgmt->to_string());
    }

    if (desired_string->compare(concat) == 0) {
        return true;
    }
    return false;
}

auto fragment_assembler::reset_fragments() -> void {
    for (auto fgmt : fragments) {
        fgmt->reset();
    }
}
