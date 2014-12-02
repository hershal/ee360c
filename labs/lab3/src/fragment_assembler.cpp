/*! Fragment Assembler implementation for EE360C Lab 3 */

#include "fragment_assembler.hpp"

#include <string>
#include <sstream>
#include <iostream>

fragment_assembler::fragment_assembler() {
    /* Nothing to do here */
}

auto fragment_assembler::assemble(const std::string* desired_string)
    -> fragment_package* {

    fragment_package* pkg = new fragment_package();

    /* for (const auto fgmt : fragments) { */
        dfs(desired_string, pkg, fragments);
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
(const std::string* desired, const std::string* fragment) -> size_t {

    if (desired->find(*fragment) == 0) {
        return fragment->size();
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

auto fragment_assembler::add_fragment(fragment* fgmt) -> void {
    fragments.push_back(fgmt);
}

auto print_recurrence_vector(std::vector<fragment*> recurrence_vector)
    -> const std::string {

    std::stringstream stb;

    for (const auto fgmt : recurrence_vector) {
        stb << fgmt->to_string()->c_str() << " ";
    }

    return stb.str();
}

auto fragment_assembler::dfs
    (const std::string* desired_string,
     fragment_package* pkg,
     std::vector<fragment*> recurrence_vector) -> bool {

    if (check_assembly(desired_string, pkg->get_current_traces())) {
        /* Found */
        std::cout << "    found: " << pkg->show_trace() << "\n";
        std::cout << "        vec: " << print_recurrence_vector(recurrence_vector) << "\n";
        pkg->commit_trace();
        return true;
    } else {
        /* auto adj_nodes = nodes[curr_dev_id]->get_adjacent_nodes(); */

        for (auto it = recurrence_vector.begin(); it != recurrence_vector.end(); ++it) {

            auto fgmt = (*it);

            pkg->push_trace(fgmt);
            it = recurrence_vector.erase(it);
            std::cout << "    pushing: trace: " << fgmt->to_string()->c_str()
                      << ": " << pkg->show_trace() << "\n";
            std::cout << "        vec: " << print_recurrence_vector(recurrence_vector) << "\n";

            if (dfs(desired_string, pkg, recurrence_vector)) {
                /* pkg->commit_trace(); */
                /* reset_fragments(); */
                
                /* return true; */
            } else {
                auto p = pkg->pop_trace();

                if (p) {
                    recurrence_vector.insert(recurrence_vector.begin(), p);
                }
                /* Not found, then backtrack */
                std::cout << "    backtracking: " << fgmt->to_string()->c_str()
                          << ": " << pkg->show_trace() << "\n";
                std::cout << "        vec: " << print_recurrence_vector(recurrence_vector) << "\n";
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

auto fragment_assembler::reset_fragments() -> void {
    for (auto fgmt : fragments) {
        fgmt->reset();
    }
}
