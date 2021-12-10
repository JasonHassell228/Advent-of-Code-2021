#include <iostream>
#include <fstream>
using namespace std;

int getInt(string line) {
    return stoi(line.substr(line.find(' '), line.length()));
}

void addDirection(string line, int *x, int *y, int *aim) {
    string dir = line.substr(0, line.find(' '));
    int magnitude = getInt(line);
    if (dir.compare("forward") == 0) {
        cout << "forward, ";
        *x += magnitude;
        *y += *aim * magnitude;
    } else if (dir.compare("down") == 0) {
        cout << "down, ";
        *aim += magnitude;
    } else if (dir.compare("up") == 0) {
        cout << "up, ";
        *aim -= magnitude;
    } else {
        cout << "NANI!?!?!" << endl;
    }
}

int main() {
    ifstream fs;
    string line;
    int x = 0;
    int y = 0;
    int aim = 0;

    fs.open("input1");

    getline(fs, line); // get first measurment
    do {
        addDirection(line, &x, &y, &aim);
        cout << "pos: " << x << ", " << y << " | " << getInt(line) << endl;
    } while (getline(fs, line));
    cout << "Final: " << x*y << endl;
    return 0;
}
