//-----------------------------------------------------------
// File name: A3_SheetPb4_20221015.cpp                      |
// Purpose:   Training on using Templates                   |
// Author:    Osama Refaat Sayed Ali                        |
// ID:        20221015                                      |
// Section:   21                                            |
// Date:      5 Dec 2023                                    |
//-----------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//---------------------------------------------------------------------------

template<class t>
class set {
private :
    vector<t>Set ;
public:
    void insert (const t& item) ;
    void Erase (const t& item);
    bool Find(const t& item);
    int Size ();
    typename vector<t>::iterator begin() ;
    typename vector<t>::iterator end() ;
    t* dynamic_array();
};

//---------------------------------------------------------------------------

template<class t >
void set<t> :: insert(const t& item)
{
    auto it = find(Set.begin(), Set.end(), item); // Check if the element already exist or not
    if (it != Set.end())
        cout<<"Unable to insert as it is an existing item ! \n"; // print warning if it exists
    else {
        Set.push_back(item); // insert it if it is unique
        sort(Set.begin(),Set.end());
    }
}

//---------------------------------------------------------------------------

template<class t >
void set<t> :: Erase(const t& item)
{
    auto it = find(Set.begin(), Set.end(), item); // Check if the element already exist or not
    if (it != Set.end()) {
        Set.erase(it); // if it exists , so erase it .
        sort(Set.begin(),Set.end());
    }
    else
        cout<<"item is not found in the set already \n"; // if it does not exist , so print message to inform
}

//---------------------------------------------------------------------------

template<class t >
bool set<t> ::Find(const t &item)
{
    auto it = find(Set.begin(), Set.end(), item);  // Check if the element already exist or not
    if (it != Set.end())
        return true ;  // return true if it exist
    else
        return false; // return false if not
}

//---------------------------------------------------------------------------

template<class t >
int set<t> ::Size()
{
    return Set.size(); // return size of the vector representing the set
}

//---------------------------------------------------------------------------
template<class t >
typename vector<t>::iterator set<t> :: begin()
{
    return Set.begin();
}


template<class t >
typename vector<t>::iterator set<t> :: end()
{
    return Set.end();
}

//---------------------------------------------------------------------------

template<class T>
T* set<T>::dynamic_array()  {
    sort(Set.begin(), Set.end());
    T* arr = new T[Set.size()]; // NEW Dynamic Array
    copy(Set.begin(), Set.end(), arr); // copy elements of the STL to the new dynamic array
    return arr;
}

//---------------------------------------------------------------------------

int main() {
    set<int> mySet;

    mySet.insert(5);
    mySet.insert(3);
    mySet.insert(8);
    mySet.insert(3); // Repeated , should print a warning

    // Testing display
    cout << "Set elements after insertions: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Testing Size
    cout << "Size of the set: " << mySet.Size() << endl;

    // Testing Find
    cout << "Is 5 in the set? " << (mySet.Find(5) ? "Yes" : "No") << endl;
    cout << "Is 10 in the set? " << (mySet.Find(10) ? "Yes" : "No") << endl;

    // Testing Erase
    mySet.Erase(3);
    mySet.Erase(10); // 10 not in the set, should print a message

    // Testing display after Erase
    cout << "Set elements after Erase: ";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Testing dynamic_array
    int* dynamicArr = mySet.dynamic_array();
    cout << "Dynamic array elements: ";
    for (int i = 0; i < mySet.Size(); ++i) {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;

    // Avoid Memory Leak
    delete[] dynamicArr;
//---------------------------------------------------------------------------

cout<<"\n--------------------------------------------------- \n\n";

    set<string> mystringSet;

    mystringSet.insert("cat");
    mystringSet.insert("dog");
    mystringSet.insert("bike");
    mystringSet.insert("cat"); // Repeated , should print a warning

    // Testing display
    cout << "Set elements after insertions: ";
    for (auto it = mystringSet.begin(); it != mystringSet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Testing Size
    cout << "Size of the set: " << mystringSet.Size() << endl;

    // Testing Find
    cout << "Is cat in the set? " << (mystringSet.Find("cat") ? "Yes" : "No") << endl;
    cout << "Is ball in the set? " << (mystringSet.Find("ball") ? "Yes" : "No") << endl;

    // Testing Erase
    mystringSet.Erase("cat");
    mystringSet.Erase("zoo"); // zoo not in the set, should print a message

    // Testing display after Erase
    cout << "Set elements after Erase: ";
    for (auto it = mystringSet.begin(); it != mystringSet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Testing dynamic_array
    string* dynamicArray = mystringSet.dynamic_array();
    cout << "Dynamic array elements: ";
    for (int i = 0; i < mystringSet.Size(); ++i) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    // Avoid Memory Leak
    delete[] dynamicArray;

    return 0;
}
