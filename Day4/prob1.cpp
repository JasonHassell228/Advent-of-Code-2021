#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fs;
    string line;

    fs.open("input1");
    getline(fs, line);
    while (line != "") {
        string num = line.substr(0, line.find(','));
        cout << "|" << num << "|" << "remaining line: " << line << endl;
        int idx = min(line.find(','), line.find('\n'));
        line.erase(0, idx + 1);
        // ^^ kill all of this
    }
    return 0;
}
