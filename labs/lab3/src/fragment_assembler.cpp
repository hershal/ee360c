/*! Fragment Assembler implementation for EE360C Lab 3 */

#include "fragment_assembler.hpp"

#include <string>
#include <sstream>

fragment_assembler::fragment_assembler() {
    /* Nothing to do here */
}

auto fragment_assembler::assemble(const std::string* desired_string)
    -> fragment_package* {

    for (const auto fgmt : fragments) {
        if(begins_with(desired_string, fgmt->to_string())) {
            fgmt->disable();
        }
    }
    return 0;
}

auto fragment_assembler::chop_assemble
    (const std::string* desired_string,
     const size_t begin_index,
     std::vector<fragment*>* recurrence_vector) -> bool {

    /* STUB */
    return false;
}

/* Because I'm lazy and didn't want to create a completely full
 * "desired-string" class */
auto fragment_assembler::begins_with
    (const std::string* desired, const std::string* fragment) -> size_t {

    if (desired->find(*fragment) == 0) {
        return fragment->size();
    } else {
        return 0;
    }
}

auto fragment_assembler::add_fragment(fragment* fgmt) -> void {
    fragments.push_back(fgmt);
}

auto fragment_assembler::to_string() const -> const std::string {

    std::stringstream stb;

    for (const auto fgmt : fragments) {
        stb << fgmt->to_string() << "\n";
    }

    return stb.str();
}

auto fragment_assembler::dfs
    (std::string* desired_string, fragment_package* pkg) -> bool {

    if (check_assembly(desired_string, pkg->get_current_traces())) {
        /* Found */
        return true;
    } else {
        /* auto adj_nodes = nodes[curr_dev_id]->get_adjacent_nodes(); */

        for (const auto fgmt : fragments) {
            if (fgmt->is_enabled()) {

                /* Disable the connection */
                fgmt->disable();

                pkg->push_trace(fgmt);
                /* std::cout << "    pushing: i: " << curr_dev_id */
                /*           << " j: " << an->nref->get_id() */
                /*           << " w: " << an->edge_weight << "\n"; */

                if (dfs(desired_string, pkg)) {
                    return true;
                } else {
                    pkg->pop_trace();
                }

                /* Not found, then backtrack */
                /* std::cout << "    backtracking: " << curr_dev_id << "\n"; */
            }
        }
    }
    return false;
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
