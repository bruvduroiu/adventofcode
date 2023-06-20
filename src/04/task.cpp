// Advent of Code 2022
// Day 4: Camp Cleanup
// https://adventofcode.com/2022/day/4

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

const int START_ELF_ONE = 0;
const int START_ELF_TWO = 2;
const int END_ELF_ONE = 1;
const int END_ELF_TWO = 3;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }
  std::string line;
  std::ifstream file(argv[1]);
  int part1 = 0;
  int part2 = 0;

  while (std::getline(file, line)) {
    // For each line in the file
    int i = 0;
    int sections[4];
    std::istringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) {
      // For each substring delimited by ','
      std::istringstream ss2(token);
      std::string token2;
      while (std::getline(ss2, token2, '-')) {
        // For each substring delimited by '-'
        sections[i] = std::stoi(token2);
        i++;
      }
    }
    if ((sections[START_ELF_ONE] >= sections[START_ELF_TWO] &&
         sections[END_ELF_ONE] <= sections[END_ELF_TWO]) ||
        (sections[START_ELF_ONE] <= sections[START_ELF_TWO] &&
         sections[END_ELF_ONE] >= sections[END_ELF_TWO])) {
      part1 += 1;
    }

    if ((sections[START_ELF_ONE] <= sections[START_ELF_TWO] &&
         sections[END_ELF_ONE] >= sections[START_ELF_TWO]) ||
        (sections[START_ELF_ONE] >= sections[START_ELF_TWO] &&
         sections[START_ELF_ONE] <= sections[END_ELF_TWO])) {
      part2 += 1;
    }
  }
  std::cout << part1 << "\n";
  std::cout << part2 << "\n";
  return 0;
}
