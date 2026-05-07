#include "file_handler.h"
#include <fstream>
#include <iostream>

FileHandler::FileHandler(const std::string& filename) : filename(filename) {}

std::vector<Student> FileHandler::loadStudents() {
    std::vector<Student> students;
    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                students.push_back(Student::fromCSV(line));
            }
        }
        file.close();
    }
    
    return students;
}

void FileHandler::saveStudents(const std::vector<Student>& students) {
    std::ofstream file(filename);
    
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.toCSV() << "\n";
        }
        file.close();
    } else {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
    }
}
