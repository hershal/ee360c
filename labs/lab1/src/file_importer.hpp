#ifndef FILE_IMPORTER_H
#define FILE_IMPORTER_H

#include <string>
#include "complex_bipartite_graph.hpp"

class file_importer {
public:
    file_importer(std::string file_input, std::string file_output);
    auto generate_graphs() -> void;

private:
    std::string file_input;
    std::string file_output;
    std::vector<complex_bipartite_graph> graphs;
    enum parsing_state {kPSInstances, kPSNumTicTac, kPSTics, kPSTacs};
};

#endif  /* FILE_IMPORTER_H */
