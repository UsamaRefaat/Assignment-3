// File name: problem 5
// Purpose:
// Author(s):Ziad tawfik
// ID(s): 20221066
// Section: s22
// Date: 12 / 9 / 2023
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

class Task_Manager {
private:
    map<string,pair<pair<long long , pair<string , long long>>,int>> byname;
    map<long long,pair<pair<long long ,pair<string , long long>>,string>> bymem;
    map<long long,pair<pair<string ,pair<string ,long long>>,int >> bypid;

public:
    void loadformOS();
    void sortbyName();
    void sortbyPID();
    void sortbyMemory();

};



void Task_Manager::loadformOS() {
    system("tasklist > myOS.txt");
    ifstream MyOS("myOS.txt");
    if (MyOS.is_open()) {
        string line;
        getline(MyOS, line);
        getline(MyOS, line);
        getline(MyOS, line);
        while (getline(MyOS, line)) {
            string name , PID , session_name , mem , sesstion_number ;

            for (int i = 0; i < 26; ++i) {
                name += line[i];
            }

            for (int i = 26; i < 35 ; ++i) {
                if (!isblank(line[i]))
                    PID += line[i];
            }

            for (int i = 64; i < 75; ++i) {
                if (!isblank(line[i]) && !ispunct(line[i]))
                    mem += line[i];
            }

            for (int i = 35; i < 45 ; ++i) {
                session_name += line[i];
            }
            sesstion_number = line[62];
            pair<long long, pair<string, long long>> inner_pair(stoi(mem),make_pair(session_name, stoi(PID)));
            pair<pair<long long, pair<string, long long>>, int> value(inner_pair, stoi(sesstion_number));
            byname.insert({name,value});
            pair<long long,  pair< string, long long>> inner_pair1 (stoi(PID),  make_pair(name, stoi(sesstion_number)));
            pair< pair<long long,  pair< string, long long>>, string> value1(inner_pair, session_name);
            bymem.insert({stoi(mem), value1});
            pair<string, pair<string, long long>> inner_pair2(name, make_pair(session_name, stoi(mem)));
            pair<pair<string, pair<string, long long>>, int>value2(inner_pair2, stoi(sesstion_number));
            bypid.insert({stoi(PID),value2});

        }
    } else {
        cout << "There is an error in opening the file!\n";
    }
}

void Task_Manager::sortbyName() {
    for(auto i : byname) {
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << "The Name: " << i.first << " The PID: " << i.second.first.second.second << " The session Name: " << i.second.first.second.first
             << " session#: " << i.second.second << " The memory Usage: " << i.second.first.first << " KB\n";
    }
}

void Task_Manager::sortbyPID() {
    for(auto i : bypid){
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << "The Name: " << i.second.first.first << " The PID: " << i.first << " The session Name: " << i.second.first.second.first
             << " session#: " << i.second.second << " The memory Usage: " << i.second.first.second.second<< " KB\n";
    }
}

void Task_Manager::sortbyMemory() {
    for(auto i : bymem){
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << "The Name: " << i.second.first.second.first << " The PID:  " << i.second.first.first << " The session Name:  " << i.second.second
             << " session#: " << i.second.first.second.second << "  The memory Usage:  " << i.first << "KB\n";
    }
}




int main() {
    Task_Manager tm;
    tm.loadformOS();
    tm.sortbyName();

    return 0;
}

