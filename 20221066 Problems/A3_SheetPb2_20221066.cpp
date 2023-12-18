// File name: problem 2
// Purpose:
// Author(s):Ziad tawfik
// ID(s): 20221066
// Section: s22
// Date: 12 / 9 / 2023
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
# include <fstream>
# define endl '\n'
class String_set{
public:
    deque <string> v1  ;

    String_set(){

    }
    String_set(string file_name) {
        ifstream file(file_name);
        string w, c;

        if (file.is_open()) {

            while (file >> w) {
                c = "";
                for (int i = 0; i < w.size(); i++) {
                    if (ispunct(w[i]))
                        continue;
                    else
                        c += tolower(w[i]);
                }

                v1.push_back(c);
            }
        }
    }
    String_set( string x  , int n)  {

        string m = "" ;
        for (int i = 0; i < x.size(); i++) {
            if (ispunct(x[i]))
                continue;
            else {
                if (x[i] == ' ') {
                    v1.push_back(m);
                    m = "" ;
                }
                else
                    m += tolower(x[i]);
            }
        }
        v1.push_back(m);
    }
    void add_string(){
        string s ;
        string m = "" ;
        cout << "Enter the string that you want to add it . " << endl;
        getline(cin , s) ;
        for (int i = 0 ; i < s.size() ; i++)
        {
            if (ispunct(s[i]))
                continue;
            else {
                if (isspace(s[i])) {
                    v1.push_back(m);
                    m = "";

                }
                else
                    m += tolower(s[i]);
            }
        }
        v1.push_back(m) ;
    }
    void remove_string(){
        string s ;
        string m = "" ;
        cout << "Enter the string that you want to remove it . " << endl;
        getline(cin  , s) ;
        deque <string> d ;
        for (int i = 0 ; i < s.size() ; i++)
        {
            if (ispunct(s[i]))
                continue;
            else {
                if (isspace(s[i])) {
                    d.push_back(m);
                    m = "";

                }
                else
                    m += tolower(s[i]);
            }
        }
        d.push_back(m) ;
        for (int c = 0 ;  c < d.size()  ; c++)
        {for (int x = 0 ; x < v1.size() ;x++)
            {
                if (d[c] == v1[x])
                    v1.erase(v1.begin()+x) ;
            }

        }


    }
    void clear(){
        v1.clear() ;
        cout << "After clear the set become empty " << endl;
    }
    int count(){
        return v1.size() ;
    }
    void print(){
        cout << "'after printing'"  << endl ;
        for (auto i : v1)
            cout << i << ' ' << endl ;
    }
    String_set operator +(String_set s)
    {
        String_set s3 = *this ;
        for (int u = 0 ; u < s.v1.size() ; u++)
        {
            s3.v1.push_back(s.v1[u]) ;
        }
        return s3 ;
    }
    String_set operator *(String_set s){
        String_set s3  ;
        for (const auto& elem : v1) {
            if (find(s.v1.begin(), s.v1.end(), elem) != s.v1.end()) {
                s3.v1.push_back(elem);
            }
        }

        return s3;
    }
    double get_similarity(String_set s) {

        int count = 0;
        for (auto elem: v1) {
            if (find(s.v1.begin(), s.v1.end(), elem) != s.v1.end()) {
                count++;
            }
        }
        if ((count == v1.size() )  && (v1.size() == s.v1.size()))
            return 1;
        else if (count == 0)
            return 0;
        else {
            double d1 = sqrt(v1.size());
            double d2 = sqrt(s.v1.size());
            if (d1 == 0 || d2 == 0)
                return 0;
            else {
                double n =  (count) / (d1 * d2) ;
                return  n ;

            }
        }
    }

};

int main() {
    string z ;
    // cout << "Add a string that you want to add it to file :" << endl ;
    //getline(cin , z) ;
    string fi1 ("test.txt")  ;

    string fi2 ("test2.txt");
    String_set s (fi1) ;
    String_set s4 (fi2) , s5 ;
    //String_set s (z , 1);

    s.add_string() ; // the parameter in the function ;
    s4.add_string() ;
    s.print() ;
    s.remove_string() ;// the parameter in the function ;
    s.print() ;
    // s.clear();

    cout << "number of words : " << s.count() << endl  ;
    s5 = s * s4 ;
    if (s5.v1.empty())
        cout << "No intersection ." << endl ;
    else {
        cout << "The intersection in :" << endl;
        for (auto x: s5.v1) {
            cout << x << " ";
        }
        cout << endl;
    }
    s5 = s + s4 ;
    cout << "after union become : " << endl ;
    for (auto x : s5.v1 )
    {
        cout << x << " " ;
    }
    cout << endl ;
    cout << s.get_similarity(s4) << endl ;
    return 0;
}