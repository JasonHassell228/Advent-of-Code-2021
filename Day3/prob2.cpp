#include <iostream>
#include <fstream>
using namespace std;

string mostCommonBitsOxy(string lines[], int size, int idx, int flag) {
    int bits = 0;
    int common = 0;
    string newLines[size] = {};

    for (int i=0; i < size; i++) {
        bits += stoi(lines[i].substr(idx, 1));
    }
    bool cond;
    if (!flag) {
        cerr << "GCB: ";
        cout << "GCB: ";
        cond = bits >= ((float)size)/2;
    } else {
        cerr << "LCB: ";
        cout << "LCB: ";
        cond = bits < ((float)size)/2;
    }

    if (cond) {
        cerr << "1";
        cout << "1";
        common = 1;
    } else {
        cerr << "0";
        cout << "0";
        common = 0;
    }
    cerr << ", " << bits << "/" << size << endl;
    cout << ", " << bits << "/" << size << endl;
    flush(cerr);
    int newSz = 0;
    cout << "Newlines: " << endl;
    for (int i=0; i < size; i++) {
        if (stoi(lines[i].substr(idx, 1)) == common) {
            newLines[newSz] = lines[i];
            cout << lines[i] << endl;
            newSz++;
        }
    }
    if (newSz == 1) {
        return newLines[0];
    } else if (newSz > 1) {
        // recurse
        return mostCommonBitsOxy(newLines, newSz, ++idx, flag);
    } else {
        cout << "ERROR no options left?" << endl;
        return "err";
    }
}

int main() {
    ifstream fs;
    string line;
    string filename = "input1";
    int size = 0;
    int i = 0;
    fs.open(filename);
    while (getline(fs, line)) {
        size++;
    }
    string lines[size];
    fs.close();
    fs.open(filename);
    while (getline(fs, line)) {
        lines[i] = line;
        i++;
    }
    cout << "Result: " + mostCommonBitsOxy(lines, size, 0, 0) + ", " + mostCommonBitsOxy(lines, size, 0, 1); // start @ 0
    return 0;
}