#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include "LibrarySystem.h"
#include "GradeManager.h"
using namespace std;



// Structure for students
struct student
{
    string fname;
    string lname;
    string Registration;
    string ClassMajor;
    string grade;
    int Gpa;
    string GPA;
    string accelarated;
    string studentData;
    string studentName;
    string newGrade;
    string Borrowing_Book;
}studentData;

//Classes
struct classes
{
    string S_C_math;
    int I_C_M_Math = 50;
    int I_C_math;
}Class;

struct teacher
{
    string fst_name;
    string lst_name;
    string qualification;
    string exp;
    string pay;
    string subj;
    string lec;
    string serves;
    string cel_no;

}tech[50];

void getlastLine(string filename)
{
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        fin.seekg(-1, ios_base::end);

        bool keepLooping = true;
        while (keepLooping) {
            char ch;
            fin.get(ch);

            if ((int)fin.tellg() <= 1) {
                fin.seekg(0);
                keepLooping = false;
            }
            else if (ch == '\n') {
                keepLooping = false;
            }
            else {
                fin.seekg(-2, ios_base::cur);
            }
        }

        string lastLine;
        getline(fin, lastLine);
        Class.S_C_math = lastLine;
        Class.I_C_math = stoi(lastLine);


        fin.close();
    }


}

void studentInfo() {

	char choice;
	string find;
	string srch;
	int i = 0, j;

	while (1)
	{

		cout << "\t\t\t Student Information And Data\n\n\n";
		cout << "Enter Your choice: " << endl;
		cout << "1.Create New Entry" << endl;
		cout << "2.Find and Display entry" << endl;
		cout << "3.Jump to  main" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			ofstream f1("Students.txt", ios::app);
			for (i = 0; choice != 'n' && choice != 'N'; i++)
			{
				cout << "Enter First name: ";
				cin >> studentData.fname;
				cout << "Enter Last name: ";
				cin >> studentData.lname;
				cout << "Enter Registration number: ";
				cin >> studentData.Registration;
				cout << "Enter class: ";
				cin >> studentData.ClassMajor;
				cout << "Enter Students Grade: ";
				cin >> studentData.grade;
				cout << "Enter Students Gpa: ";
				cin >> studentData.GPA;
				cout << "Enter True if student is borrowing a book enter False if not: ";
				cin >> studentData.Borrowing_Book;
				studentData.Gpa = stoi(studentData.GPA);
				if (studentData.Gpa >= 3.6)
				{
					studentData.accelarated = "True";
				}
				f1 << studentData.fname << endl << studentData.lname << endl << studentData.Registration << endl << studentData.ClassMajor << endl << studentData.grade << endl << studentData.GPA << endl << studentData.accelarated << endl << studentData.Borrowing_Book << endl;

				cout << "Do you want to countinue Adding student? Y to  continue N to stop: ";
				cin >> choice;
			}

			f1.close();
		}
		continue;

		case '2':
		{
			ifstream f2("Students.txt");
			cout << "Enter First name to be displayed: ";
			cin >> find;
			cout << endl;
			int notFound = 0;
			while (getline(f2, studentData.fname)) {
				if (studentData.fname == find)
				{
					notFound = 1;

					cout << "First Name: " << studentData.fname << endl;
					getline(f2, studentData.lname);
					cout << "Last Name: " << studentData.lname << endl;

					getline(f2, studentData.Registration);
					cout << "Registration No number: " << studentData.Registration << endl;
					getline(f2, studentData.ClassMajor);
					cout << "Class: " << studentData.ClassMajor << endl;
					getline(f2, studentData.grade);
					if (studentData.ClassMajor == "math")
					{
						Class.I_C_math += 1;
					}
					cout << "Grade: " << studentData.grade << endl;
					getline(f2, studentData.GPA);
					cout << "Gpa: " << studentData.GPA << endl;
					getline(f2, studentData.accelarated);
					cout << "Accelarated: " << studentData.accelarated << endl << endl;
				}

			}
			f2.close();
			if (notFound == 0) {

				cout << "No Record Found\n" << endl;
			}
			cout << "Press any key two times to proceed" << endl << endl;
			_getch();
			_getch();

		}
		continue;
		case '3':
		{
			system("cls");
			break;

		}
		}
		break;
	}

}

void teacherInfo()
{

	char choice;
	string find;
	string srch;
	int i = 0, j;

	while (1)
	{
		system("cls");
		cout << "\t\t\tTeachers Info and Data\n\n\n";
		cout << "Enter your choice: " << endl;
		cout << "1.Create new entry\n";
		cout << "2.Find and display\n";
		cout << "3.Jump to main\n";
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			ofstream t1("Teachers.txt", ios::app);
			for (i = 0; choice != 'n' && choice != 'N'; i++)
			{
				if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
				{
					cout << "Enter First name: ";
					cin >> tech[i].fst_name;
					cout << "Enter Last name: ";
					cin >> tech[i].lst_name;
					cout << "Enter qualification: ";
					cin >> tech[i].qualification;
					cout << "Enter experiance(year): ";
					cin >> tech[i].exp;
					cout << "Enter number of year in this School: ";
					cin >> tech[i].serves;
					cout << "Enter Subject whos teach: ";
					cin >> tech[i].subj;
					cout << "Enter Lecture(per Week): ";
					cin >> tech[i].lec;
					cout << "Enter pay: ";
					cin >> tech[i].pay;
					cout << "Enter Phone Number: ";
					cin >> tech[i].cel_no;


					t1 << tech[i].fst_name << endl << tech[i].lst_name << endl << tech[i].qualification << endl << tech[i].exp << endl << tech[i].serves << endl << tech[i].subj << endl << tech[i].lec << endl << tech[i].pay << endl << tech[i].cel_no << endl;

					cout << "Do you want to countinue Adding student? Y to  continue N to stop: ";
					cin >> choice;

				}
			}

			system("cls");

			t1.close();
			break;
		}
		case '2':
		{
			ifstream t2("Teachers.txt");
			cout << "Enter First name to be displayed: ";
			cin >> find;
			cout << endl;
			int notFound = 0;
			while (getline(t2, studentData.fname)) {

				if (tech[j].fst_name == find)
				{
					notFound = 1;
					cout << "First name: " << tech[j].fst_name << endl;
					getline(t2, tech[j].lst_name);
					cout << "Last name: " << tech[j].lst_name << endl;
					getline(t2, tech[j].qualification);
					cout << "Qualification: " << tech[j].qualification << endl;
					getline(t2, tech[j].exp);
					cout << "Experience: " << tech[j].exp << endl;

					getline(t2, tech[j].serves);
					cout << "number of year in this School: " << tech[j].serves << endl;

					getline(t2, tech[j].subj);
					cout << "Subject whos teach: " << tech[j].subj << endl;

					getline(t2, tech[j].lec);
					cout << "Enter Lecture(per Week): " << tech[j].lec << endl;
					getline(t2, tech[j].pay);
					cout << "pay: " << tech[j].pay << endl;

					getline(t2, tech[j].cel_no);
					cout << "Phone Number: " << tech[j].cel_no << endl << endl;
				}

			}
			t2.close();
			if (notFound == 0) {

				cout << "No Record Found" << endl;
			}
			cout << "Press any key two times to proceed";
			_getch();
			_getch();

		}
		continue;
		case '3':
		{
			break;
			system("cls");
		}
		}
		break;
	}
}


int main()
{
	char choice;
	string find;
	string srch;
	int i = 0, j;
	while (1)
	{
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
		cout << "\n\n\t\t\tSCHOOL MANAGEMENT PROGRAM\n\n";
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
		cout << "\n\n\t\t\tMAIN SCREEN\n\n";
		cout << "Enter your choice: " << endl;
		cout << "1.Students information" << endl;
		cout << "2.Teacher information" << endl;
		cout << "3.Check amount of people in a class" << endl;
		cout << "4.Add or Look For Students Borrowing books" << endl;
		cout << "5.Exit program" << endl;
		
		cin >> choice;
		


		system("cls");

		switch (choice)
		{
		case '1':
		{
			studentInfo();
			continue;
		}
		case '2':
		{
			teacherInfo();
			continue;
		}
		case '3':
		{
			ifstream c2("Class.txt");

			getlastLine("Class.txt");
			cout << "Math Class: " << Class.S_C_math << "/" << Class.I_C_M_Math << endl;
			cout << "Press any key two times to proceed" << endl;
			_getch();
			_getch();
			continue;
		}

		case '4':
		{
			displayStudent();
			continue;
		}

		case '5':
		{
			break;
		}
		}
		break;
	}
}
