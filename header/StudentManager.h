
#ifndef STUDENTMANAGER_H
#define STUDENTMABAGER_H

#include "Student.h"
#include <iostream>
#include <stdexcept>
#include <vector>
class StudentManager {
public:
    void addStudent(const Student& student) {
        students_.push_back(student);
    }
    Student getStudent(const std::string& id) const {
        for (const auto& student : students_) {
            if (student.getId() == id) {
                return student;
            }
        }
        throw std::runtime_error("No student with id " + id);
    }
    void showAllStudents() const {
        for (const auto& student : students_) {
            std::cout << "Name: " << student.getName() << ", Age: " << student.getAge() << std::endl;
        }
    }
    private:
    std::vector<Student> students_;
};
#endif // STUDENTMANAGER_H