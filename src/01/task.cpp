#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string line;
  ifstream myfile(argv[1]);

  (void)argc;

  if (myfile.is_open()) {
    int acc = 0;
    int max = 0;
    while (getline(myfile, line)) {
      if (line == "") {
        if (acc > max) {
          max = acc;
        }
        acc = 0;
      } else {
        int val = stoi(line);
        acc = acc + val;
      }
    }
    cout << max;
    myfile.close();
  } else
    goto failure;
  return 0;
failure:
  myfile.close();
  cout << "Unable to open file";
  return 1;
}
