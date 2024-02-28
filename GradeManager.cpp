// GradeManager.cpp
#include "GradeManager.h"
#include <fstream>
#include <iostream>

void updateMathGrade(const std::string& studentName, const std::string& newGrade) {
    std::ifstream fin("Students.txt");
    std::ofstream fout("Temp.txt");

    if (!fin.is_open()) {
        std::cout << "Could not open file\n";
        return;
    }

    std::string line;
    while (std::getline(fin, line)) {
        if (line == studentName) {
            fout << line << "\n";
            for (int i = 0; i < 7; ++i) {
                std::getline(fin, line);
                fout << line << "\n";
            }
            std::getline(fin, line);
            fout << newGrade << "\n";
        }
        else {
            fout << line << "\n";
        }
    }

    fin.close();
    fout.close();

    remove("Students.txt");
    rename("Temp.txt", "Students.txt");
}

void viewMathGrade(const std::string& studentName) {
    std::ifstream fin("Students.txt");

    if (!fin.is_open()) {
        std::cout << "Could not open file\n";
        return;
    }

    std::string line;
    while (std::getline(fin, line)) {
        if (line == studentName) {
            for (int i = 0; i < 7; ++i) {
                std::getline(fin, line);
            }
            std::getline(fin, line);
            std::cout << "Math Grade: " << line << "\n";
            break;
        }
    }

    fin.close();
}
