#include <iostream>
#include <fstream>
using namespace std;

int getInt(string line) {
    return stoi(line.substr(line.find(' '), line.length()));
}

void addDirection(string line, int *x, int *y) {
    string dir = line.substr(0, line.find(' '));
    int magnitude = getInt(line);
    if (dir.compare("forward") == 0) {
        cout << "forward, ";
        *x += magnitude;
    } else if (dir.compare("down") == 0) {
        cout << "down, ";
        *y += magnitude;
    } else if (dir.compare("up") == 0) {
        cout << "up, ";
        *y -= magnitude;
    } else {
        cout << "NANI!?!?!" << endl;
    }
}

int main() {
    ifstream fs;
    string line;
    int x = 0;
    int y = 0;

    fs.open("input1");
    getline(fs, line); // get first measurment
    addDirection(line, &x, &y);
    cout << "pos: " << x << ", " << y << " | " << getInt(line) << endl;

    while (getline(fs, line)){
        addDirection(line, &x, &y);
        cout << "pos: " << x << ", " << y << " | " << getInt(line) << endl;
    }
    cout << "Final: " << x*y << endl;
    return 0;
}
