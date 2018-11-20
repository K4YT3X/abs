/*
Name: abs
Dev: K4YT3X
Date Created: November 19, 2018
Last Modified: November 19, 2018

Licensed under the GNU General Public License Version 3 (GNU GPL v3),
    available at: https://www.gnu.org/licenses/gpl-3.0.txt
(C) 2018 K4YT3X

 Description: This program returns the absolute path of a file or directory.

 Version 1.0.0
 */

#include <iostream>
#include <cstring>
#include <sys/stat.h>

inline bool exists (const std::string& name)
{
    // Check if file or directory exists
    // by PherricOxide@stackoverflow.com
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

int main(int argc, char *argv[])
{
    // if no arguments given
    if (argc < 2) {
        std::cerr << "abs: missing target file" << std::endl;
        std::cerr << "usage: abs file [...]" << std::endl;
        std::cerr << "Try 'abs --help' for more information" << std::endl;
        return 1;
    // if help argument specified
    } else if (strcmp(argv[1], "-h") == 0 | strcmp(argv[1], "--help") == 0) {
        std::cout << "usage: abs file [...]" << std::endl;
        std::cout << "prints the full absolute path of the file" << std::endl;
        return 0;
    }

    // if file or directory exists
    if (exists(argv[1])) {
        // get full path
        char *full_path = realpath(argv[1], NULL);
        std::cout << full_path << std::endl;
        free(full_path);
    // if doesn't exist
    } else {
        std::cerr << "abs: file doesn't exist" << std::endl;
        return 1;
    }
    return 0;
}