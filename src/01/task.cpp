// Advent of Code 2022
// Day 1: Calorie Counting
// https://adventofcode.com/2022/day/1

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    return EXIT_FAILURE;
  }

  std::string line;
  std::ifstream myfile(argv[1]);

  (void)argc;

  if (myfile.is_open()) {
    int acc = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    while (getline(myfile, line)) {
      if (line.empty()) {
        if (acc > max1) {
          max3 = max2;
          max2 = max1;
          max1 = acc;
        } else if (acc > max2) {
          max3 = max2;
          max2 = acc;
        } else if (acc > max3) {
          max3 = acc;
        }
        acc = 0;
      } else {
        acc += std::stoull(line);
      }
    }
    std::cout << "PART 1: " << max1 << std::endl;
    std::cout << "PART 2: " << max1 + max2 + max3 << std::endl;
    myfile.close();
  } else
    goto failure;
  return 0;
failure:
  myfile.close();
  std::cout << "Unable to open file";
  return 1;
}
