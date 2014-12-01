/*! Fragment Assembler header for EE360C Lab 3 */

#include "fragment.hpp"

#include <set>

class fragment_assembler {
public:
    auto fragment_assembler();
    auto assemble(std::string desired_string) const -> const ;
private:
    std::set<fragment> fragments;
};

