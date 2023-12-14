//-----------------------------------------------------------
// File name: A3_SheetPb1_20221015.cpp                      |
// Purpose:   Training on using files , virtual functions   |
// Author:    Osama Refaat Sayed Ali                        |
// ID:        20221015                                      |
// Section:   21                                            |
// Date:      5 Dec 2023                                    |
//-----------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

//---------------------------------------------------------

class LabelGenerator {
protected:
    string prefix;
    int initial_index;
    int counter;

public:
    LabelGenerator(string prefix_, int initial_index_);
    virtual string next_label();
};

//---------------------------------------------------------

class FileLabelGenerator : public LabelGenerator {
protected:
    string filename;
    ifstream input;

public:
    FileLabelGenerator(string prefix_, int initial_index_, string filename_);
    ~FileLabelGenerator();
    string next_label() override;
};

//---------------------------------------------------------

LabelGenerator::LabelGenerator(string prefix_, int initial_index_)
        : prefix(prefix_), initial_index(initial_index_), counter(initial_index_) {} // initialize Using initialization list
                                                          //assigning the initial index as the beginning of the counter
//---------------------------------------------------------

string LabelGenerator::next_label() {
    return prefix + to_string(counter++); // post increment to count o=in correct way from the initial index
}

//---------------------------------------------------------

FileLabelGenerator::FileLabelGenerator(string prefix_, int initial_index_, string filename_)
        : LabelGenerator(prefix_, initial_index_), filename(filename_) {  // initialize Using initialization list
    input.open(filename);
    if (!input.is_open()) {
        cout << "FAIL TO OPEN FILE !"; // warning Message if we fail to open the file
        exit(EXIT_FAILURE);  // Exit from the program
    }
}

//---------------------------------------------------------

FileLabelGenerator::~FileLabelGenerator() {
    input.close();
}

//---------------------------------------------------------

string FileLabelGenerator::next_label() {
    string parent_label = LabelGenerator::next_label(); // Taking the label title from the base class
    string file_label;

    if (getline(input, file_label)) {
        return parent_label + " " + file_label; // Taking the content beside the title from the file
    }else {
        input.clear();
        input.seekg(0, std::ios::beg); // like "returning the cursor to the beginning of the page"
        getline(input, file_label);
        return parent_label + " " + file_label; // Taking the content beside the title from the file
    }
}

//---------------------------------------------------------

int main() {
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);

    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.next_label() << " ";
    }

    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.next_label() << " ";
    }

    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.next_label() << " ";
    }
    cout << endl;

    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++) {
        cout << figureLabels.next_label() << endl;
    }
        return 0 ;
}

