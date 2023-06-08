// Advent of Code 2022
// Day 2: Rock Paper Scissors
// https://adventofcode.com/2022/day/2

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>

enum Choice : uint8_t { ROCK = 1, PAPER = 2, SCISSORS = 3 };
enum Outcome { LOSE, DRAW, WIN };

Choice mapCharToChoice(const char &input) {
  static std::unordered_map<char, Choice> stringToChoice{
      {'A', Choice::ROCK}, {'B', Choice::PAPER}, {'C', Choice::SCISSORS},
      {'X', Choice::ROCK}, {'Y', Choice::PAPER}, {'Z', Choice::SCISSORS},
  };

  auto it = stringToChoice.find(input);
  if (it != stringToChoice.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid input string for Choice ");
  }
}

Outcome mapCharToOutcome(const char &input) {
  static std::unordered_map<char, Outcome> stringToOutcome{
      {'X', Outcome::LOSE},
      {'Y', Outcome::DRAW},
      {'Z', Outcome::WIN},
  };

  auto it = stringToOutcome.find(input);
  if (it != stringToOutcome.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid input string for Choice ");
  }
}

Choice loses(const Choice &input) {
  static std::unordered_map<Choice, Choice> choiceToChoice{
      {Choice::ROCK, Choice::SCISSORS},
      {Choice::SCISSORS, Choice::PAPER},
      {Choice::PAPER, Choice::ROCK},
  };

  auto it = choiceToChoice.find(input);
  if (it != choiceToChoice.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid input Choice for Choice");
  }
}

Choice beats(const Choice &input) {
  static std::unordered_map<Choice, Choice> choiceToChoice{
      {Choice::ROCK, Choice::PAPER},
      {Choice::SCISSORS, Choice::ROCK},
      {Choice::PAPER, Choice::SCISSORS},
  };

  auto it = choiceToChoice.find(input);
  if (it != choiceToChoice.end()) {
    return it->second;
  } else {
    throw std::invalid_argument("Invalid input Choice for Choice");
  }
}

int8_t score(const Choice &p1, const Choice &p2) {
  int8_t score;
  if (p1 == p2) {
    score = 3; // Tie
  } else if ((p1 == Choice::ROCK && p2 == Choice::SCISSORS) ||
             (p1 == Choice::SCISSORS && p2 == Choice::PAPER) ||
             (p1 == Choice::PAPER && p2 == Choice::ROCK)) {
    score = 6;
  } else {
    score = 0;
  }

  return p1 + score;
}

uint8_t riggedScore(const Choice &p, const Outcome &o) {
  if (o == Outcome::LOSE) {
    return loses(p);
  } else if (o == Outcome::DRAW) {
    return p + 3;
  } else {
    return beats(p) + 6;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return EXIT_FAILURE;
  }
  std::string line;
  std::ifstream myfile(argv[1]);

  if (myfile.is_open()) {
    int part1 = 0;
    int part2 = 0;
    while (getline(myfile, line)) {
      Choice elf = mapCharToChoice(line[0]);
      Choice me = mapCharToChoice(line[2]);
      Outcome o = mapCharToOutcome(line[2]);
      int8_t res1 = score(me, elf);
      int8_t res2 = riggedScore(elf, o);
      part1 += res1;
      part2 += res2;
    }
    std::cout << part1 << "\n";
    std::cout << part2;
    myfile.close();
  }
  return 0;
}
