/*! Fragment Assembler implementation for EE360C Lab 3 */

#include "fragment_assembler.hpp"

#include <cstdio>

fragment_assembler::fragment_assembler() {
    results_vec = new std::vector<std::vector<std::string> >();
}

fragment_assembler::~fragment_assembler() {
    for (auto vec : *results_vec) {
        vec.clear();
    }
    results_vec->clear();
    delete results_vec;
}

auto fragment_assembler::add_fragment(const std::string fgmt) -> void {
    fragments.insert(fgmt);
}

auto fragment_assembler::assemble(const std::string* desired_string)
    -> std::vector<std::vector<std::string> >* {

    std::vector<std::string> fragment_strings;

    std::vector<std::string> empty_vector;

    poor_mans_bfs(*desired_string, empty_vector, results_vec);

    /* DEBUG */
    /* printf("%lu\n", results_vec->size()); */
    /* for (const auto strvec : *results_vec) { */
    /*     for (const auto str : strvec) { */
    /*         printf("%s ", str.c_str()); */
    /*     } */
    /*     printf("\n"); */
    /* } */
    /* END DEBUG */

    return results_vec;
}

auto fragment_assembler::begins_with
(const std::string* desired, const std::string* fragment_string) -> size_t {

    if (desired->find(*fragment_string) == 0) {
        return fragment_string->size();
    } else {
        return 0;
    }
}

auto fragment_assembler::poor_mans_bfs
    (std::string desired_string,
     std::vector<std::string> current_strings,
     std::vector<std::vector<std::string> >* results) -> bool {

    if (desired_string.size() == 0) {

        /* DEBUG */
        /* printf("found: "); */
        /* for (const auto str : current_strings) { */
        /*     printf("%s ", str.c_str()); */
        /* } */
        /* printf("\n"); */
        /* END DEBUG */

        results->push_back(current_strings);

        return 1;
    }

    for (const auto str : fragments) {
        size_t chop = begins_with(&desired_string, &str);
        if (chop) {
            
            /* DEBUG */
            /* printf("chop: %s %lu %s: ", desired_string.c_str(), chop, str.c_str()); */
            /* for (const auto str : current_strings) { */
            /*     printf("%s ", str.c_str()); */
            /* } */
            /* printf("\n"); */
            /* END DEBUG */

            current_strings.push_back(str);
            std::string substr = desired_string.substr(chop, desired_string.size());
            if (poor_mans_bfs(substr, current_strings, results)) {

                /* DEBUG */
                /* printf("found, clearing: "); */
                /*  */
                /* for (const auto str : current_strings) { */
                /*     printf("%s ", str.c_str()); */
                /* } */
                /* printf("\n"); */
                /* END DEBUG */
            }
            current_strings.pop_back();
        }
    }
    return 0;
}
