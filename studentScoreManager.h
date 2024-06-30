#ifndef STUDENTSCOREMANAGER_H
#define STUDENTSCOREMANAGER_H
#include "studentscore.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include<string>
namespace SCM{
    class StudentScoreManager {
    public:
        ~StudentScoreManager(){
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
        void addStudent(const StudentScore& student) {
            students_.push_back(student);
        }
        StudentScore getStudent(const std::string& id) const {
            for (const auto& student : students_) {
                if (student.getId() == id) {
                    return student;
                }
            }
            throw std::runtime_error("No student with id " + id);
        }
        
        void showAllStudents() const {
            for (const auto& student : students_) {
                std::cout << "Id: " << student.getId() << std::endl;
                student.showAllScores();
            }
        }
        bool saveToFile( const std::string filename) const{
            std::ofstream file(filename);
            if (!file) {
                return false;
            }
            for (const auto& student : students_) {
                file << student.getId() << ' ' << student.getScore("Math") << ' ' << student.getScore("C++") << ' '<< student.getScore("Physics")<<std::endl;
            }
            return true;
        }
        bool loadFromFile( const std::string filename){
            std::ifstream file(filename);
            if (!file) {
                return false;
            }
            std::string id;
            double math, cpp, physics;
            while (file >> id >> math >> cpp >> physics) {
                StudentScore student(id);
                student.setScore("Math", math);
                student.setScore("C++", cpp);
                student.setScore("Physics", physics);
                students_.push_back(student);
            }
            // id = 582303431;
            // math =81;
            // cpp=82;
            // physics=83;
            // StudentScore student(id);
            //     student.setScore("Math", math);
            //     student.setScore("C++", cpp);
            //     student.setScore("Physics", physics);
            //     students_.push_back(student);
            return true;
        }
        private:
            std::vector<StudentScore> students_;
            const std::string filename = "studentscores.txt";
    };

}
#endif // STUDENTSCOREMANAGER_H
