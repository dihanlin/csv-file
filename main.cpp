//
//  main.cpp
//  Stats
//
//  Created by Dihan Lin on 2021/10/16.
//This program will import data from stats students and remove outliers, after doing so, the program will print out the remaining data.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

//This function will read the CSV file and delete certain data.
void delete_record()
{
    //Open file pointers.
    fstream fin, fout;
    
    //Open an existing file.
    fin.open("oldData.csv", ios::in);
    
    //Create a new file to store non-deleted data.
    fout.open("newData.csv", ios::out);
    
    int rollnum, roll1, marks, count = 0, i;
        char sub;
        int index, new_marks;
        string line, word;
        vector<string> row;
      
        // Get the roll number
        // to decide the data to be deleted
        cout << "Enter the roll number "
             << "of the record to be deleted: ";
        cin >> rollnum;
      
    
    // Check if this record exists
        // If exists, leave it and
        // add all other data to the new file
        while (!fin.eof())
        {
      
            row.clear();
            getline(fin, line);
            stringstream s (line);
      
            while (getline(s, word,','))
            {
                row.push_back(word);
            }
      
            int row_size = row.size();
            roll1 = stoi(row[0]);
      
            // writing all records,
            // except the record to be deleted,
            // into the new file 'newData.csv'
            // using fout pointer
            if (roll1 != rollnum)
            {
                if (!fin.eof()) {
                    for (i = 0; i < row_size - 1; i++) {
                        fout << row[i] << ", ";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            }
            else {
                count = 1;
            }
            if (fin.eof())
                break;
        }
    
        if (count == 1)
            cout << "Record deleted\n";
        else
            cout << "Record not found\n";
      
        // Close the pointers
        fin.close();
        fout.close();
      
        // removing the existing file
        remove("oldData.csv");
      
        // renaming the new file with the existing file name
        rename("newData.csv", "oldData.csv");
    }
    
//Main function.
int main ()
{
    delete_record();
    cout<<"The delete record function has been called successfully.";
    return 0;
}

