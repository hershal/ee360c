/*! Fragment Assembler header for EE360C Lab 3 */

#include "fragment.hpp"
#include "fragment_package.hpp"

#include <vector>

class fragment_assembler {
public:
    fragment_assembler();
    auto add_fragment(fragment* fgmt) -> void;
    auto assemble(const std::string* desired_string) -> fragment_package*;
    auto to_string() const -> const std::string;

private:
    auto begins_with(const std::string* desired, const std::string* fragment) -> size_t;
    auto chop_assemble(const std::string* desired_string,
                       const size_t begin_index,
                       std::vector<fragment*>* recurrence_vector) -> bool;

    auto dfs(std::string* desired_string, fragment_package* pkg) -> bool;

    auto check_assembly(const std::string* desired_string,
                        const std::vector<fragment*>* fragments) const -> bool;

    std::vector<fragment*> fragments;
};

