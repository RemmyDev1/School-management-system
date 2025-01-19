// LibrarySystem.h
#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <math.h>s

using namespace std;

// Structure for students
struct student {
    string fname;
    string lname;
    string Registration;
    string ClassMajor;
    string grade;
    string GPA;
    string accelarated;
    string Borrowing_Book;
    string studentName;
    string newGrade;
};

// Structure for classes
struct Class {
    string S_C_math;
    int I_C_M_Math = 50;
    int I_C_math;
};

extern int notFound;


// Function to display a student
void displayStudent();

#endif // LIBRARY_SYSTEM_H
