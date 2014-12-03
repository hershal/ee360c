/*! Fragment Assembler header for EE360C Lab 3 */

#include <string>
#include <vector>
#include <set>

class fragment_assembler {
public:
    fragment_assembler();
    ~fragment_assembler();
    auto add_fragment(const std::string fgmt) -> void;
    auto assemble(const std::string* desired_string) 
        -> std::vector<std::vector<std::string> >*;

    auto to_string() const -> const std::string;

private:
    auto begins_with(const std::string* desired,
                     const std::string* fragment_string) 
        -> size_t;
    auto poor_mans_bfs(std::string desired_string,
                       std::vector<std::string> current_strings,
                       std::vector<std::vector<std::string> >* results) 
        -> bool;

    std::set<std::string> fragments;
    std::vector<std::vector<std::string> >* results_vec;
};

