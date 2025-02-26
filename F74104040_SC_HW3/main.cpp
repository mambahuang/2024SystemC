#include "List.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Please provide input file name.\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    unsigned int length;
    inputFile >> length;

    List list(length);
    inputFile >> list;

    ofstream resultFile("RESULT");

    // Copy list to 3 other lists
    List list1 = list;
    cout << "List copy to List 1: " << list1 << endl;
    resultFile << "List copy to List 1: " << list1 << "\n";
    List list2(list);
    cout << "List copy to List 2: " << list2 << endl;
    resultFile << "List copy to List 2: " << list2 << "\n";
    List list3;
    list3 = list;
    cout << "List copy to List 3: " << list3 << endl;
    resultFile << "List copy to List 3: " << list3 << "\n";

    // Perform operations and output each result
    List sumList12 = list1 + list2;
    cout << "(Operator+) Sum of List 1 and List 2: " << sumList12 << endl;
    resultFile << "(Operator+) Sum of List 1 and List 2: " << sumList12 << "\n";

    List sumList13 = list1 + list3;
    cout << "(Operator+) Sum of List 1 and List 3: " << sumList13 << endl;
    resultFile << "(Operator+) Sum of List 1 and List 3: " << sumList13 << "\n";

    List sumList23 = list2 + list3;
    cout << "(Operator+) Sum of List 2 and List 3: " << sumList23 << endl;
    resultFile << "(Operator+) Sum of List 2 and List 3: " << sumList23 << "\n";

    ++list1;
    cout << "(Operator++) List 1 after prefix ++: " << list1 << endl;
    resultFile << "(Operator++) List 1 after prefix ++: " << list1 << "\n";

    ++list2;
    cout << "(Operator++) List 2 after prefix ++: " << list2 << endl;
    resultFile << "(Operator++) List 2 after prefix ++: " << list2 << "\n";

    ++list3;
    cout << "(Operator++) List 3 after prefix ++: " << list3 << endl;
    resultFile << "(Operator++) List 3 after prefix ++: " << list3 << "\n";

    list1++;
    cout << "(Operator++(long)) List 1 after postfix ++: " << list1 << endl;
    resultFile << "(Operator++(long)) List 1 after postfix ++: " << list1 << "\n";

    list2++;
    cout << "(Operator++(long)) List 2 after postfix ++: " << list2 << endl;
    resultFile << "(Operator++(long)) List 2 after postfix ++: " << list2 << "\n";

    list3++;
    cout << "(Operator++(long)) List 3 after postfix ++: " << list3 << endl;
    resultFile << "(Operator++(long)) List 3 after postfix ++: " << list3 << "\n";

    list1 += list3;
    cout << "(Operator+=) List 1 after += List 3: " << list1 << endl;
    resultFile << "(Operator+=) List 1 after += List 3: " << list1 << "\n";

    --list1;
    cout << "(Operator--) List 1 after prefix --: " << list1 << endl;
    resultFile << "(Operator--) List 1 after prefix --: " << list1 << "\n";

    --list2;
    cout << "(Operator--) List 2 after prefix --: " << list2 << endl;
    resultFile << "(Operator--) List 2 after prefix --: " << list2 << "\n";
    
    --list3;
    cout << "(Operator--) List 3 after prefix --: " << list3 << endl;
    resultFile << "(Operator--) List 3 after prefix --: " << list3 << "\n";

    list1--;
    cout << "(Operator--(long)) List 1 after postfix --: " << list1 << endl;
    resultFile << "(Operator--(long)) List 1 after postfix --: " << list1 << "\n";

    list2--;
    cout << "(Operator--(long)) List 2 after postfix --: " << list2 << endl;
    resultFile << "(Operator--(long)) List 2 after postfix --: " << list2 << "\n";

    list3--;
    cout << "(Operator--(long)) List 3 after postfix --: " << list3 << endl;
    resultFile << "(Operator--(long)) List 3 after postfix --: " << list3 << "\n";

    return 0;
}

