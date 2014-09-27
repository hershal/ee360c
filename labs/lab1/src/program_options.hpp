#ifndef PROGRAM_OPTIONS_H
#define PROGRAM_OPTIONS_H

#include <vector>

class program_options {
public:
    program_options(int ac, char** av);
    auto get_input_files() ->  std::vector<std::string>;
    auto get_output_files() -> std::vector<std::string>;
private:
    auto process_options(int ac, char** av) -> void;
    auto file_does_exist(std::string path) -> bool;
    auto trim_file_extension(std::string* extension) -> void;

    std::vector<std::string> input_files;
    std::vector<std::string> output_files;

    const static char* kPOInputFileCmdline;
    const static char* kPOIntputFileDesc;
    const static char* kPOHelpCmdline;
    const static char* kPOHelpDesc;
};

#endif // PROGRAM_OPTIONS_H
