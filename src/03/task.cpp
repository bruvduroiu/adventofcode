// Advent of Code 2022
// Day 3: Rucksack Reorganization
// https://adventofcode.com/2022/day/3

#include <algorithm>
#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>

uint64_t priority(const char &item) {
  if (std::isupper(item)) {
    return item - 'A' + 27;
  }
  return item - 'a' + 1;
}

char duplicate(std::string line) {
  const char c = *std::find_first_of(
      std::begin(line), std::next(std::begin(line), line.size() / 2),
      std::next(std::begin(line), line.size() / 2), std::end(line));
  return c;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }
  std::string line;
  std::ifstream file(argv[1]);

  int part1 = 0;
  int part2 = 0;
  std::array<int, 58> cnt; // 29 chars per lower-/uppercase set
  while (std::getline(file, line)) {
    // PART 1
    char d = duplicate(line);
    part1 += priority(d);
    // PART 2
    // Deduplicate in case rucksack has 2 items of same type
    std::sort(std::begin(line), std::end(line));
    line.erase(std::unique(std::begin(line), std::end(line)), std::end(line));
    for (const char c : line) {
      cnt[c - 'A'] += 1;
      if (cnt[c - 'A'] == 3) {
        part2 += priority(c);
        std::fill(std::begin(cnt), std::end(cnt), 0);
        break;
      }
    }
  }
  std::cout << part1 << "\n";
  std::cout << part2 << "\n";
  return 0;
}
