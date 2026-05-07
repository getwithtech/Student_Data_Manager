#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    int age;
    std::string major;

public:
    Student();
    Student(int id, const std::string& name, int age, const std::string& major);

    int getId() const;
    std::string getName() const;
    int getAge() const;
    std::string getMajor() const;

    void display() const;
    std::string toCSV() const;
    static Student fromCSV(const std::string& csvLine);
};

#endif // STUDENT_H
