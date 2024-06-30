#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student {
public:
    Student(const std::string& name, int age, const std::string& id,bool isReg)
        : name_(name), age_(age), id_(id),isRegistered_(isReg) {}

    std::string getName() const { return name_; }
    int getAge() const { return age_; }
    std::string getId() const { return id_; }
    bool isReg()const{return isRegistered_;}
    void setReg(){
        isRegistered_=true;
    }

private:
    std::string name_;
    int age_;
    std::string id_;
    bool isRegistered_;
};
#endif // STUDENT_H
