#include "file_importer.hpp"

#include <iostream>
#include <fstream>
#include <exception>

file_importer::file_importer(std::string file_input, std::string file_output) {

    this->file_input = file_input;
    this->file_output = file_output;
}

auto file_importer::generate_graphs() -> void {

    /* Generate structures here */
    std::cout << "importing file: " << this->file_input << "\n";

    std::ifstream fin;
    fin.open(this->file_input);

    parsing_state pstate = kPSInstances;

    /* Parse the current file */
    std::string line;
    uint32_t num_instances = 0;
    uint32_t num_tics = 0;
    uint32_t num_tacs = 0;

    uint32_t current_instance = 0;
    uint32_t current_tic = 0;
    uint32_t current_tac = 0;

    while (fin) {
        std::getline(fin, line);

        std::size_t pos = 0;
        std::vector<std::string> toks;

        /* Parse the current line and break it up into elements
           separated by a space so that we can determine what the line is */
        while ((pos = line.find(" "))) {
            toks.emplace_back(line.substr(0, pos));
            line.erase(0, pos + 1);
            if (pos == std::string::npos) { break; }
        }

        try {
            if ((toks.size() == 1) && (pstate == kPSInstances)) {
                /* Num instances */
                num_instances = std::stoi(toks[0]);
                current_instance = 0;

                pstate = kPSNumTicTac;

            } else if (toks.size() == 2) {
                if (pstate == kPSNumTicTac) {
                    /* Num Tics/Tacs */
                    num_tics = stoi(toks[0]);
                    num_tacs = stoi(toks[1]);
                    current_tic = 0;
                    current_tac = 0;
                    graphs.emplace_back(num_tics, num_tacs);
                    pstate = kPSTics;

                } else if (pstate == kPSTacs) {
                    /* Tac node */
                    const int32_t id = stoi(toks[0]);
                    const int32_t weight = stoi(toks[1]);
                    graphs[current_instance].add_tac(id, weight);

                    ++current_tac;

                    if (current_tac == num_tacs) {
                        pstate = kPSNumTicTac;
                        ++current_instance;
                    }

                } else {
                    std::cout << "Specification error!\n"
                              << "Tried to get num tic/tacs or a tac but failed.\n";
                    exit(1);
                }
            } else if ((toks.size() == 4) && (pstate == kPSTics)) {
                /* Tic node */
                const int32_t id = stoi(toks[0]);
                const int32_t min = stoi(toks[1]);
                const int32_t max = stoi(toks[2]);
                const int32_t weight = stoi(toks[3]);

                graphs[current_instance].add_tic(id, weight, min, max);

                ++current_tic;
                if (current_tic == num_tics) {
                    pstate = kPSTacs;
                }

            } else {
                if (num_instances == current_instance) {
                    /* Reached end of parsing */
                    std::cout << "done parsing\n";
                } else {
                    std::cout << "Unknown specification error!\n"
                              << "Everything fell through. Some information:\n"
                              << "current_instance/num_instances: "
                              << current_instance << "/" << num_instances << "\n"
                              << "current_tic/num_tics: "
                              << current_tic << "/" << num_tics << "\n"
                              << "current_tac/num_tacs: "
                              << current_tac << "/" << num_tacs << "\n";
                }

            }
        } catch (std::exception e) {
            std::cout << e.what() << "\n";
            exit(1);
        }

    }

    std::ofstream fout;
    fout.open(file_output);
    for (auto i=0; i<graphs.size(); ++i) {
        std::cout << "instance: " << i << "\n";
        std::cout << graphs[i].to_string() << "\n";
        const auto mwmcms = graphs[i].find_mwmcms();

        std::cout << "writing output\n";

        const auto highest_cardinality_match = mwmcms.rbegin();
        const auto highest_weight_match = highest_cardinality_match->second.rbegin();
        fout << highest_weight_match->second.size() << "\n";
        for (const auto match : highest_weight_match->second) {
            fout << match.to_string() << "\n";
        }
    }
    fout.close();
}
