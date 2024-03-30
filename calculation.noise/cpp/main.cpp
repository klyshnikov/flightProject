#include <iostream>
#include "arguments.parser/ArgumentsParser.h"
#include "image.generator/SvgGenerator.h"

using namespace calculation;
int main(int argc, char** argv) {

    ArgumentsParser argumentsParser;
    if (!argumentsParser.parseArguments(argc, argv)) {
        std::cout << "Wrong arguments\n"
                  << argv[0] << " <path_to_sheremetievo_history_directory> table\n"
                  << " or \n"
                  << argv[0] << " <path_to_sheremetievo_history_directory> table <hour>\n"
                  << " or \n"
                  << argv[0] << " <path_to_sheremetievo_history_directory> sector <x> <y>\n"
                  << " or \n"
                  << argv[0] << " <path_to_sheremetievo_history_directory> sector <latitude> <longitude>\n"
                  << " or \n"
                  << argv[0] << " <path_to_sheremetievo_history_directory> map <directory to save pictures>";
    }
}
