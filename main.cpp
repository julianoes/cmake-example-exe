#include <example-lib/example-lib.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Invalid argument, please supply times." << std::endl;
        return 1;
    }
    example_lib::hello_lib(std::stoi(argv[1]));
    return 0;
}
