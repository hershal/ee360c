/*! Program Options Parser Header for EE360C Lab 1 */
/* This class has exit-powers */

#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <map>

class program_options {
public:
    program_options(int32_t ac, char** av);
    auto process_options(int32_t ac, char** av) -> void;
    auto get_input_output_file_map() const
        -> const std::map<std::string, std::string>;
private:
    auto replace_file_extension
    (std::string file, std::string output_dir, std::string extension) const
        -> const std::string;

    int32_t ac;
    char** av;

    std::map<std::string, std::string> input_output_file_map;
};

#endif // PROGRAM_OPTIONS_H
