#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fs;
    string line;
    int prev = 0;
    int curr = 0;
    int total = 0;

    fs.open("input1");
    getline(fs, line); // get first measurment
    prev = stoi(line);
    curr = stoi(line);
    while (getline(fs, line)){
        curr = stoi(line);
        if (curr > prev) {
            total += 1;
        }
        prev = curr;
    }
    cout << "Total increased: " << total << endl;
    return 0;
}
