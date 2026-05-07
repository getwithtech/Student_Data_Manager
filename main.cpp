#include <iostream>
#include <vector>
#include "student.h"
#include "file_handler.h"

void displayMenu() {
    std::cout << "\n--- Student Data Manager ---\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. View All Students\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    FileHandler fileHandler("data.txt");
    std::vector<Student> students = fileHandler.loadStudents();
    
    int choice;
    do {
        displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        
        if (choice == 1) {
            int id, age;
            std::string name, major;
            
            std::cout << "Enter ID: ";
            std::cin >> id;
            std::cin.ignore(); // clear newline
            
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            
            std::cout << "Enter Age: ";
            std::cin >> age;
            std::cin.ignore();
            
            std::cout << "Enter Major: ";
            std::getline(std::cin, major);
            
            students.push_back(Student(id, name, age, major));
            fileHandler.saveStudents(students);
            std::cout << "Student added and saved successfully!\n";
        } else if (choice == 2) {
            std::cout << "\n--- Student List ---\n";
            if (students.empty()) {
                std::cout << "No students found.\n";
            } else {
                for (const auto& student : students) {
                    student.display();
                }
            }
        }
    } while (choice != 3);
    
    std::cout << "Exiting...\n";
    return 0;
}
