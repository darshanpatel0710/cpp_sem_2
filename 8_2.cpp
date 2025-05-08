#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string s;
    cout<<"Enter the string:";
    getline(cin, s);
    stringstream word(s);
    map<string, int> freq;
    string buff;

    while (word >> buff) {
        freq[buff]++;
    }

    for (auto &it : freq) {
        cout << it.first << ": " << it.second << endl;
    }
    cout<<"24CE076_PatelDarshan";
    return 0;
}
