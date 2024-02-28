// LibrarySystem.cpp
#include "LibrarySystem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;
extern student studentData;
int notFound = 0;

void displayStudent() {
    ifstream f2("Students.txt");
    cout << "\t\t\tLibrary System Information\n\n\n" << endl;
    cout << "1.Add A Student To The Borrowing Book List" << endl;
    cout << "2.look for students Borrowing book" << endl;
    cout << "Enter First name to be displayed: ";
    string find;
    cin >> find;
    cout << endl;

    while (!f2.eof()) {
        getline(f2, studentData.fname);

        if (studentData.fname == find && studentData.Borrowing_Book == "true") {
            notFound = 1;
            cout << "First Name: " << studentData.fname << endl;
            getline(f2, studentData.lname);
            cout << "Last Name: " << studentData.lname << endl;
            getline(f2, studentData.Registration);
            cout << "Registration No number: " << studentData.Registration << endl;
            getline(f2, studentData.ClassMajor);
            cout << "Class: " << studentData.ClassMajor << endl;
            getline(f2, studentData.grade);
            cout << "Grade: " << studentData.grade << endl;
            getline(f2, studentData.GPA);
            cout << "Gpa: " << studentData.GPA << endl;
            getline(f2, studentData.accelarated);
            cout << "Accelarated: " << studentData.accelarated << endl << endl;
        }
    }
    f2.close();
    if (notFound == 0) {
        cout << "No Record Found" << endl;
    }
    cout << "Press any key two times to proceed" << endl << endl;
    _getch();
    _getch();
}
