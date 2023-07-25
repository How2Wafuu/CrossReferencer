
#include <iostream>
#include <fstream>
#include <string>
#include "tree.h"
#include <vector>
#include <sstream>

using namespace std;

int main() {
    // C++ program to read a text file.
	Tree<string> mytree;
    fstream newFile;
    newFile.open("isne.txt", ios::in); // open a file to perform read operation using file object
    int j = 0; // for
    if (newFile.is_open()) { // checking whether the file is open
        string tp; // variable to store data of file
        while (getline(newFile, tp)) {                        // read data from file object and put it into string.
            string s;   // variable to store token obtained from the original string

            stringstream ss(tp);  // constructing stream from the string
            vector<string> v; // declare the vector to store the words
            while (getline(ss, s, ' ')) {

                // store token string in the vector
                v.push_back(s);
            }
            ++j; // increment the line number
            for (int i = 0; i < v.size(); i++) {
                mytree.insert(v[i],j); // insert the word into the tree
                cout << j << " " << v[i] << endl;

            }

        }
        newFile.close(); // close the file object.
    }
    cout << "------------" << endl;
mytree.inorder();


    return 0;
}
