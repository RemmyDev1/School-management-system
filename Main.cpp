#include "LibrarySystem.h"
#include "GradeManager.h"
#include <pqxx/pqxx>
using namespace std;

pqxx::connection conn("");



// Structure for student data
struct Student {
	string firstName;
	string lastName;
	string registration;
	string classMajor;
	string grade;
	int gpa;
	bool accelerated;
	bool borrowingBook;
};

// Structure for teacher data
struct Teacher {
	string fst_name;
	string lst_name;
	string qualification;
	string exp;
	string serves;
	string subj;
	string lec;
	string pay;
	string cel_no;
};

// Function to add a student to the database
void addStudentToDatabase(pqxx::connection& conn, const Student& student) {
	pqxx::work W(conn);
	string query = "INSERT INTO students (fname, lname, registration, class_major, grade, gpa, accelerated, borrowing_book) "
		"VALUES (" +
		W.quote(student.firstName) + ", " +
		W.quote(student.lastName) + ", " +
		W.quote(student.registration) + ", " +
		W.quote(student.classMajor) + ", " +
		W.quote(student.grade) + ", " +
		to_string(student.gpa) + ", " +
		(student.accelerated ? "TRUE" : "FALSE") + ", " +
		(student.borrowingBook ? "TRUE" : "FALSE") + ")";
	W.exec(query);
	W.commit();
	cout << "Student added to the database successfully.\n";
}

// Function to display student details from the database
void displayStudentFromDatabase(pqxx::connection& conn, const string& firstName) {
	pqxx::work W(conn);
	pqxx::result R = W.exec("SELECT * FROM students WHERE fname = " + W.quote(firstName));

	if (R.empty()) {
		cout << "No record found.\n";
	}
	else {
		for (const auto& row : R) {
			cout << "First Name: " << row["fname"].c_str() << endl;
			cout << "Last Name: " << row["lname"].c_str() << endl;
			cout << "Registration: " << row["registration"].c_str() << endl;
			cout << "Class: " << row["class_major"].c_str() << endl;
			cout << "Grade: " << row["grade"].c_str() << endl;
			cout << "GPA: " << row["gpa"].as<int>() << endl;
			cout << "Accelerated: " << (row["accelerated"].as<bool>() ? "Yes" : "No") << endl;
			cout << "Borrowing Book: " << (row["borrowing_book"].as<bool>() ? "Yes" : "No") << endl;
		}
	}
}

// Student information menu
void studentInfo() {
	char choice;
	Student student;

	while (true) {
		cout << "\n\n\tStudent Information Menu\n";
		cout << "1. Add New Student\n";
		cout << "2. Find and Display Student\n";
		cout << "3. Back to Main Menu\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == '1') {
			cout << "Enter First Name: ";
			cin >> student.firstName;
			cout << "Enter Last Name: ";
			cin >> student.lastName;
			cout << "Enter Registration Number: ";
			cin >> student.registration;
			cout << "Enter Class Major: ";
			cin >> student.classMajor;
			cout << "Enter Grade: ";
			cin >> student.grade;
			cout << "Enter GPA: ";
			cin >> student.gpa;
			cout << "Is Accelerated (1 for Yes, 0 for No): ";
			cin >> student.accelerated;
			cout << "Is Borrowing Book (1 for Yes, 0 for No): ";
			cin >> student.borrowingBook;

			addStudentToDatabase(conn, student);
		}
		else if (choice == '2') {
			string firstName;
			cout << "Enter First Name to Search: ";
			cin >> firstName;
			displayStudentFromDatabase(conn, firstName);
		}
		else if (choice == '3') {
			break;
		}
		else {
			cout << "Invalid choice! Try again.\n";
		}
	}
}

void createTeacherEntry();
void findTeacher();
void teacherMenu();

void teacherInfo() {
	char choice;

	while (true) {
		system("cls");
		cout << "\t\t\tTeachers Info and Data\n\n";
		cout << "Enter your choice: \n";
		cout << "1. Create new entry\n";
		cout << "2. Find and display\n";
		cout << "3. Back to main menu\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case '1':
			createTeacherEntry();
			break;
		case '2':
			findTeacher();
			break;
		case '3':
			return;
		default:
			cout << "Invalid choice. Please try again.\n";
			system("pause");
		}
	}
}

void createTeacherEntry() {
	system("cls");
	cout << "\t\t\tCreate New Teacher Entry\n\n";

	ofstream t1("Teachers.txt", ios::app);

	Teacher teacher;
	char choice;

	do {
		cout << "Enter First Name: ";
		cin >> teacher.fst_name;
		cout << "Enter Last Name: ";
		cin >> teacher.lst_name;
		cout << "Enter Qualification: ";
		cin >> teacher.qualification;
		cout << "Enter Years of Experience: ";
		cin >> teacher.exp;
		cout << "Enter Years in School: ";
		cin >> teacher.serves;
		cout << "Enter Subject Taught: ";
		cin >> teacher.subj;
		cout << "Enter Lectures per Week: ";
		cin >> teacher.lec;
		cout << "Enter Pay: ";
		cin >> teacher.pay;
		cout << "Enter Phone Number: ";
		cin >> teacher.cel_no;

		// Save to file
		t1 << teacher.fst_name << endl
			<< teacher.lst_name << endl
			<< teacher.qualification << endl
			<< teacher.exp << endl
			<< teacher.serves << endl
			<< teacher.subj << endl
			<< teacher.lec << endl
			<< teacher.pay << endl
			<< teacher.cel_no << endl;

		cout << "Do you want to continue adding teachers? (Y/N): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');

	t1.close();
	cout << "\nTeacher entries added successfully.\n";
	system("pause");
}

void findTeacher() {
	system("cls");
	cout << "\t\t\tFind Teacher Information\n\n";

	ifstream t2("Teachers.txt");
	if (!t2) {
		cout << "Error: Could not open file.\n";
		system("pause");
		return;
	}

	string find;
	cout << "Enter First Name to search: ";
	cin >> find;

	string line;
	int notFound = 1;
	while (getline(t2, line)) {
		if (line == find) {
			notFound = 0;
			Teacher teacher;

			teacher.fst_name = line;
			getline(t2, teacher.lst_name);
			getline(t2, teacher.qualification);
			getline(t2, teacher.exp);
			getline(t2, teacher.serves);
			getline(t2, teacher.subj);
			getline(t2, teacher.lec);
			getline(t2, teacher.pay);
			getline(t2, teacher.cel_no);

			cout << "\n--- Teacher Information ---\n";
			cout << "First Name: " << teacher.fst_name << endl;
			cout << "Last Name: " << teacher.lst_name << endl;
			cout << "Qualification: " << teacher.qualification << endl;
			cout << "Experience (Years): " << teacher.exp << endl;
			cout << "Years in School: " << teacher.serves << endl;
			cout << "Subject Taught: " << teacher.subj << endl;
			cout << "Lectures per Week: " << teacher.lec << endl;
			cout << "Pay: " << teacher.pay << endl;
			cout << "Phone Number: " << teacher.cel_no << endl;
			break;
		}
	}

	t2.close();

	if (notFound) {
		cout << "\nNo record found for the given name.\n";
	}

	cout << "Press any key to return to the menu.";
	_getch();
}


int main()
{
	pqxx::connection conn("postgresql://Kariem:<kUkTLW0aqssz4Xd3-3SJXg>@street-wizard-7289.j77.aws-us-east-1.cockroachlabs.cloud:26257/School_Management_System?sslmode=verify-full");
	pqxx::nontransaction work(conn);

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
