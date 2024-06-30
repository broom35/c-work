#ifndef STUDENTSMANAGER_H
#define STUDENTSMANAGER_H
#include "Student.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include<string>
namespace SSM{
   

const std::string filename = "students.txt";
class StudentManager {
public:
    //static StudentManager* Instance;
    ~StudentManager(){
        if(!saveToFile(filename)){
            printf("Failed to save students to file\n");
            throw std::runtime_error("Failed to save students to file");
        }
    }
    void init(){
        if(!loadFromFile(filename)){
            printf("Failed to load students from file\n");
            throw std::runtime_error("Failed to load students from file");
        }
    }
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
    bool isAllowSignUp(std::string accId){
        for (const auto& student : students_) {
            if(student.getId()==accId&&!student.isReg()){
                return true;
            }
        }
        return false;
    }
    void showAllStudents() const {
        for (const auto& student : students_) {
            std::cout << "Name: " << student.getName() << ", Age: " << student.getAge() << std::endl;
        }
    }
    bool saveToFile( const std::string filename) const{
        std::ofstream file(filename);
        if (!file) {
            return false;
        }
        for (const auto& student : students_) {
            file << student.getName() << ' ' << student.getAge() << ' ' << student.getId() << ' '<< student.isReg()<<std::endl;
        }
        return true;
    }
    bool loadFromFile(const std::string filename){
        std::ifstream file(filename);
        if (!file) {
            return false;
        }
        std::string name;
        int age;
        std::string id;
        bool isReg;
        while (file >> name >> age >> id>>isReg) {
            students_.push_back(Student(name, age, id,isReg));
        }
        return true;
    }
private:
    std::vector<Student> students_;
};
}
#endif // STUDENTSMANAGER_H
