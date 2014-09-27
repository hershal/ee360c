#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <vector>

class program_options {
public:
    program_options(int32_t ac, char** av);
    auto process_options(int32_t ac, char** av) -> void;
    auto get_input_files() const ->  const std::vector<std::string>;
    auto get_output_files() const -> const std::vector<std::string>;
private:
    auto trim_file_extension(std::string* extension) -> void;

    int32_t ac;
    char** av;

    std::vector<std::string> input_files;
    std::vector<std::string> output_files;
};

#endif // PROGRAM_OPTIONS_H
