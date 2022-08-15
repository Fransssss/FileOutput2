// Author: Fransiskus Agapa
// 8/15/22
// Practices make improvement - Have Fun !

// =================
// User create a file and input data into the file, and display the data in the file
// =================

#include "fstream"         // deal with file - file output
#include <iostream>
#include "string"

using std::cout;
using std::endl;
using std::ofstream;       // file output
using std::ifstream;       // file input
using std::string;
using std::cin;
using std::getline;

int main()
{
    cout << "\n== File Output ==" << endl;
    cout << "1. Create a file" << endl;
    cout << "2. Input data into the file" << endl;
    cout << "3. Open the file" << endl;
    cout << "e. Exit" << endl;
    cout << "choice: ";
    string choice;
    ofstream onFS;                         // output file stream
    ifstream inFS;                         // input file stream
    string title;                          // defined here because it should be seen for choice 1 (create) and 2 (open)
    cin >> choice;

    while(choice != "e" and choice != "E")
    {
        if(choice == "1")
        {
            cout << "\n= Create a file =" << endl;
            cout << "Input filename: ";
            cin >> title;
            title += ".txt";                // file extension as .txt
            onFS.open(title);            // try to open, if not exist then It's going to be created, it exists then its going to be opened
            if(onFS.is_open())
            {
                cout << "\n[ File " << title << " created ]" << endl;
                onFS.close();              // if the file created/opened then it has later to be closed, so it can be accessed later
            }
            else
            {
                cout << "\n[ File cannot be created / opened ]" << endl;
            }
        }

        else if(choice == "2")
        {
            if(title.size() == 0)           // if file is not created
            {
                cout << "\n[ File has not been created ]" << endl;
            }
            else
            {
                cout << "\n= Update data into the file =" << endl;
                inFS.open("DataInput.txt");               // open file source
                onFS.open(title);                         // open file destination
                if(inFS.is_open() and onFS.is_open())
                {
                    string line;
                    while(!inFS.eof())        // while there is data in file
                    {
                        getline(inFS, line);
                        onFS << line << endl;  // put line to new file
                    }
                    cout << "\n[ Data updated ]" << endl;
                    inFS.close();             // close file
                    onFS.close();             // close file
                }
                else
                {
                    cout << "\n[ File cannot be opened ]" << endl;
                }
            }
        }

        else if(choice == "3")
        {
            if(title.size() == 0)      // if file is not created
            {
                cout << "\n[ File has not been created ]" << endl;
            }
            else
            {
                cout << "\n= Open the file =\n" << endl;
                inFS.open(title);
                if(inFS.is_open())
                {
                    string line;
                    while(!inFS.eof() and !inFS.fail())
                    {
                        getline(inFS, line);
                        cout << line << endl;
                    }
                    inFS.close();
                }
                else
                {
                    cout << "\n[ File cannot be opened ]" << endl;
                }
            }
        }

        else
        {
            cout << "\n[ Invalid choice ]" << endl;
        }

        cout << "\n== File Output ==" << endl;
        cout << "1. Create a file" << endl;
        cout << "2. Input data into the file" << endl;
        cout << "3. Open the file" << endl;
        cout << "e. Exit" << endl;
        cout << "choice: ";
        cin >> choice;
    }

    if(choice == "e" or choice == "E")
    {
        cout << "\n== Exit Program ==" << endl;
    }

    return 0;
}
