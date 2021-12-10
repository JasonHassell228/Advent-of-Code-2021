#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fs;
    string line;
    int x, y, z;
    int total = 0;

    fs.open("input1");
    getline(fs, line);
    x = stoi(line);
    getline(fs, line);
    y = stoi(line);
    getline(fs, line);
    z = stoi(line);
    cout << "first: " << z+y+z << endl;
    while (getline(fs, line)){
        int prev = x+y+z;
        x = y;
        y = z;
        z = stoi(line);
        int curr = x+y+z;
        cout << "prev: " << prev << " | curr: " << curr << endl;
        if (curr > prev) {
            total += 1;
        }
        // prev = curr;
    }
    cout << "Total increased: " << total << endl;
    return 0;
}
