#include <iostream>
#include "boost/program_options.hpp"

#include "program_options.hpp"

namespace po = boost::program_options;

program_options::program_options(int ac, char** av) {
    process_options(ac, av);
}

auto program_options::process_options(int ac, char** av) -> void {
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("compression", po::value<int>(), "set compression level");
    
    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);    

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return;
    }

    if (vm.count("compression")) {
        std::cout << "Compression level was set to " 
             << vm["compression"].as<int>() << ".\n";
    } else {
        std::cout << "Compression level was not set.\n";
    }
}
