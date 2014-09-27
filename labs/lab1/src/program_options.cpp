/*! Program Options Parser for EE360C Lab 1 */
/* This class has exit-powers */

#include "boost/program_options.hpp"
#include <boost/filesystem.hpp>

#include <iostream>
#include <fstream>
#include <iterator>

#include "program_options.hpp"

namespace po = boost::program_options;

/*! Prints a vector to an ostream */
template<class T>
auto operator<<(std::ostream& os, const std::vector<T>& v)
    -> std::ostream& {

    copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
    return os;
}

program_options::program_options(int32_t ac, char** av) {

    process_options(ac, av);
}

auto program_options::process_options(int32_t ac, char** av) -> void {

    po::options_description desc("Allowed options");
    desc.add_options()
        ("input-file,i", po::value<std::vector<std::string> >(), "input file(s)")
        ("help,h", "produce this help message");

    /* Add the "input-file" flag as the implicit option */
    po::positional_options_description p;
    p.add("input-file", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        exit(0);
    }

    if (vm.count("input-file")) {
        input_files = vm["input-file"].as< std::vector<std::string> >();
    } else {
        std::cout << desc << "\n";
        exit(1);
    }

    /* Signal an error if a file is not found */
    for (const auto file : input_files) {
        if (!boost::filesystem::exists(file)) {
            std::cout << "File not found: " << file << "\n";
            exit(1);
        }
    }
}

auto program_options::get_input_files() const -> const std::vector<std::string> {
    return input_files;
}
