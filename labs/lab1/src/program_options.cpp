#include <iostream>
#include "boost/program_options.hpp"

#include "program_options.hpp"

namespace po = boost::program_options;

auto program_options::process_options() -> void {
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("compression", po::value<int>(), "set compression level");
    std::cout << "process options\n";
}
