#include <iostream>
#include <fstream>
using namespace std;

void getBits(int vals[], int size, string line) {
    for (int i=0; i < size; i++) {
        if (line[i] == '1') {
            vals[i] += 1;
        }
    }
}

int main() {
    ifstream fs;
    string line;
    int lines = 0;

    fs.open("input1");
    getline(fs, line);
    int size = line.length();
    int vals[size] = {};
    int result[size] = {};

    getBits(vals, size, line);
    lines++;

    while (getline(fs, line)){
        getBits(vals, size, line);
        lines++;
    }
    cout << "final: ";
    for (int i=0; i < size; i++) {
        cout << vals[i] << "|";
        if (vals[i] > (lines/2)) {
            result[i] = 1;
        } else if (vals[i] < (lines/2)) {
            result[i] = 0;
        } else {
            cout << "what do" << endl;
        }
    }
    cout << endl << "size: " << lines << endl;
    cout << "gamma rate: ";
    for (int i=0; i < size; i++) {
        cout << result[i];
    }
    return 0;
}
