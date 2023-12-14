// File name: STL - Map.
// Purpose: Check No. of repeats of a word.
// Author(s): Mostafa Mohamed Anwer
// ID(s): 20221153
// Section: S21
// Date: 07/12/2023
#include <bits/stdc++.h>
using namespace std;

int main() {
    string file_n;
    cout<<"Enter the File name: ";
    cin >> file_n;
    ifstream file(file_n);
    if (!file.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    string line;
    map<string,int>mp;
    while(getline(file,line)) {
        string s = "";
        for (int i = 0; i < line.length(); ++i) {
            char c = tolower(line[i]);
            if (isalnum(c) ||  c == '-') {
                s += c;
            } else {
                if (!s.empty() && !(s.length()==1 && s[0] == '-')) {  //checks if the word is ok or not
                    mp[s]++;
                }
                s = "";
            }
        }
    }
    cout<<"Words that have been repeated: "<<endl;
    for (auto duplicate : mp) {
        cout<<duplicate.first<<": "<<duplicate.second<<endl;
    }
    file.close();
}
