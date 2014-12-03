#include "file_importer.hpp"
#include "fragment_assembler.hpp"

#include <cstdio>
#include <fstream>
#include <exception>
#include <vector>

file_importer::file_importer(std::string file_input, std::string file_output) {
    file_importer(file_input, file_output, true);
}

file_importer::file_importer(std::string file_input, std::string file_output,
                             bool output_enabled) {

    this->output_enabled = output_enabled;
    this->file_input = file_input;
    this->file_output = file_output;
}

auto file_importer::generate_graph() -> void {

    /* Generate structures here */
    /* std::cout << "importing file: " << this->file_input << "\n"; */

    std::ifstream fin;
    fin.open(this->file_input);

    parsing_state pstate = kPSInit;

    /* Parse the current file */
    std::string line;
    size_t num_fragments = 0;
    size_t current_fragment = 0;

    fragment_assembler assembler = fragment_assembler();
    std::string desired_string;

    while (fin) {
        std::getline(fin, line);

        std::size_t pos = 0;
        std::vector<std::string> tokens;

        /* Parse the current line and break it up into elements
           separated by a space so that we can determine what the line is */
        while ((pos = line.find(" "))) {
            tokens.emplace_back(line.substr(0, pos));
            line.erase(0, pos + 1);
            if (pos == std::string::npos) { break; }
        }

        try {
            /* Init: input the number of fragments */
            if (pstate == kPSInit) {
                num_fragments = stoi(tokens[0]);

                pstate = num_fragments==0 ? kPSQueryParse : kPSFragmentParse;

            } else if ((tokens.size() == 1) && (pstate == kPSFragmentParse)) {
                const std::string fragment_string = tokens[0];

                assembler.add_fragment(fragment_string);
                ++current_fragment;

                if (current_fragment == num_fragments) {
                    pstate = kPSQueryParse;
                }
            } else if ((tokens.size() == 1) && (pstate == kPSQueryParse)) {
                desired_string = tokens[0];
                pstate = kPSDone;
            } else {
                if ((current_fragment == num_fragments)
                    && (pstate == kPSDone)) {

                    /* printf("done parsing\n"); */
                } else {
                    printf("Unknown specification error!\n");
                    printf("Everything fell through!\n");
                    exit(1);
                }
            }
        } catch (std::exception e) {
            /* std::cout << e.what() << "\n"; */
            printf("%s", e.what());
            exit(1);
        }
    }

    /* Testing out fprintf to see if it's faster */

    /* std::ofstream fout; */
    FILE* fout;

    if (output_enabled) {
        /* fout.open(file_output); */
        fout = fopen(file_output.c_str(), "w");
    }

    const auto pkg = assembler.assemble(&desired_string);

    if (output_enabled) {
        fprintf(fout, "%lu\n", pkg->size());
        for (const auto strvec : *pkg) {
            for (const auto str : strvec) {
                fprintf(fout, "%s ", str.c_str());
            }
            fprintf(fout, "\n");
        }
        /* fout.close(); */
        fclose(fout);
    }
}
