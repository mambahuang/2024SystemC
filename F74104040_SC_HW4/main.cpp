#include "List.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <double_file> <string_file>" << endl;
        return 1;
    }

    ifstream doubleFile(argv[1]);
    ifstream stringFile(argv[2]);

    if (!doubleFile) {
        cerr << "Error: Unable to open double file." << endl;
        return 1;
    }

    if (!stringFile) {
        cerr << "Error: Unable to open string file." << endl;
        return 1;
    }

    // Initialize lists
    List<double> doubleList;
    List<string> stringList;

    // Read from the files into the respective lists
    doubleFile >> doubleList;
    stringFile >> stringList;

    // Close the files
    doubleFile.close();
    stringFile.close();

    List<double> doubleList1(doubleList); // Copy constructor
    List<string> stringList1(stringList); // Second string list
    stringList1 = stringList; // Assignment operator

    // Output lists
    cout << "List after reading from file:" << endl;
    cout << "Double List: " << doubleList << endl;
    cout << "String List: " << stringList << endl;
    cout << endl;
    cout << "List after copy constructor and assignment operator:" << endl;
    cout << "Double List 1: " << doubleList1 << endl;
    cout << "String List 1: " << stringList1 << endl;
    cout << endl;

    // Compare lists
    cout << "Comparing lists:" << endl;
    cout << "Double Lists are " << (doubleList == doubleList1 ? "equal" : "not equal") << endl;
    cout << "String Lists are " << (stringList == stringList1 ? "equal" : "not equal") << endl;
    cout << endl;

    // Set elements
    cout << "Setting elements..." << endl;
    doubleList1.setElement(0, 123.456);
    stringList1.setElement(0, "Modified");

    // Print Lists
    cout << "Modified Lists:" << endl;
    cout << "Modified Double List: " << doubleList1 << endl;
    cout << "Modified String List: " << stringList1 << endl;

    return 0;
}

