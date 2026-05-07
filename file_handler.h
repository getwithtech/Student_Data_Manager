#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "student.h"
#include <vector>
#include <string>

class FileHandler {
private:
    std::string filename;

public:
    FileHandler(const std::string& filename);
    
    std::vector<Student> loadStudents();
    void saveStudents(const std::vector<Student>& students);
};

#endif // FILE_HANDLER_H
