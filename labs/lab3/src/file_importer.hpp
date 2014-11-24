#ifndef FILE_IMPORTER_H
#define FILE_IMPORTER_H

#include <string>
/* #include "undirected_graph.hpp" */
/* #include "graph_query.hpp" */

class file_importer {
public:
    file_importer(std::string file_input, std::string file_output);
    file_importer(std::string file_input, std::string file_output,
                  bool output_enabled);
    auto generate_graph() -> void;

private:
    std::string file_input;
    std::string file_output;
    bool output_enabled;

    /* undirected_graph graph; */
    enum parsing_state {kPSInit, kPSFragmentParse, kPSQueryParse, kPSDone};
};

#endif  /* FILE_IMPORTER_H */
