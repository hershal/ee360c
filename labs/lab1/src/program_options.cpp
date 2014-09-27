#include <iostream>
#include "boost/program_options.hpp"
#include <iostream>
#include <fstream>
#include <iterator>

#include "program_options.hpp"

template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " ")); 
    return os;
}

namespace po = boost::program_options;

const char* program_options::kPOInputFileCmdline = "input-file,i";
const char* program_options::kPOIntputFileDesc = "input file(s)";
const char* program_options::kPOHelpCmdline = "help,h";
const char* program_options::kPOHelpDesc = "produce this help message";

program_options::program_options(int ac, char** av) {


    process_options(ac, av);
}

auto program_options::process_options(int ac, char** av) -> void {
    po::options_description desc("Allowed options");
    desc.add_options()
        ("input-file,i", po::value<std::vector<std::string> >(), "input files")
        ("help", "help description");
    
    /* Add the "input-file" flag as the implicit option */
    po::positional_options_description p;
    p.add("input-file", -1);

    po::variables_map vm;
    po::store(po::command_line_parser(ac, av).options(desc).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return;
    }

    if (vm.count("input-file")) {
        input_files = vm["input-file"].as< std::vector<std::string> >();
    } else {
        std::cout << desc << "\n";
    }
}
