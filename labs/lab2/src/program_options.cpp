/*! Program Options Parser for EE360C Lab 2 */
/* This class has exit-powers */

#include "boost/program_options.hpp"
#include <boost/filesystem.hpp>

#include <vector>
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

    std::vector<std::string> input_files;
    std::string output_dir;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("input-file,i", po::value<std::vector<std::string> >(), "input file(s)")
        ("output-dir,o", po::value<std::string>(), "output directory")
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

    if (vm.count("output-dir")) {
        output_dir = vm["output-dir"].as<std::string>();
        std::cout << "outputting files to: " << output_dir << "\n";
    } else {
        output_dir = "";
    }

    /* Signal an error if a file is not found */
    for (const auto file : input_files) {
        if (!boost::filesystem::exists(file)) {
            std::cout << "File not found: " << file << "\n";
            exit(1);
        }
        std::string replaced_ext = replace_file_extension(file, output_dir, ".out");
        input_output_file_map[file] = replaced_ext;
    }
}

auto program_options::replace_file_extension(
    std::string file, std::string output_dir, std::string extension) const
    -> const std::string {

    size_t last_slash = file.find_last_of("/");

    /* no last slash, check from beginning instead */
    if (last_slash == std::string::npos) {
        last_slash = 0;
    }

    std::string dirname_substr = output_dir == "" ? file.substr(0, last_slash) : output_dir;
    std::string basename_substr = file.substr(last_slash);

    size_t last_dot = basename_substr.find_last_of(".");
    basename_substr = basename_substr.substr(0, last_dot);
    basename_substr.append(".out");

    return dirname_substr.append(basename_substr);
}

auto program_options::get_input_output_file_map() const
    -> const std::map<std::string, std::string> {

    return input_output_file_map;
}
