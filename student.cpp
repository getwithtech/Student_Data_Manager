#include "student.h"
#include <iostream>
#include <sstream>

Student::Student() : id(0), age(0) {}

Student::Student(int id, const std::string& name, int age, const std::string& major)
    : id(id), name(name), age(age), major(major) {}

int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
int Student::getAge() const { return age; }
std::string Student::getMajor() const { return major; }

void Student::display() const {
    std::cout << "ID: " << id << ", Name: " << name 
              << ", Age: " << age << ", Major: " << major << std::endl;
}

std::string Student::toCSV() const {
    return std::to_string(id) + "," + name + "," + std::to_string(age) + "," + major;
}

Student Student::fromCSV(const std::string& csvLine) {
    std::stringstream ss(csvLine);
    std::string token;
    
    int id = 0;
    std::string name;
    int age = 0;
    std::string major;

    if (std::getline(ss, token, ',')) id = std::stoi(token);
    std::getline(ss, name, ',');
    if (std::getline(ss, token, ',')) age = std::stoi(token);
    std::getline(ss, major, ',');

    return Student(id, name, age, major);
}
