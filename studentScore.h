#ifndef STUDENTSCORE_H
#define STUDENTSCORE_H
#include <iostream>
#include <stdexcept>
#include<string>   
#include<map>
#include<fstream>
#include<vector>
class StudentScore {
public:
    StudentScore(const std::string& id) : id_(id) {}
    void setScore(const std::string& subject, double score) {
        scores_[subject] = score;
    }
    double getScore(const std::string& subject) const {
        auto it = scores_.find(subject);
        if (it == scores_.end()) {
            throw std::runtime_error("No score for subject " + subject);
        }
        return it->second;
    }
    std::string getId() const {
        return id_;
    }
    void showAllScores() const {
        for (const auto& score : scores_) {
            std::cout << "Subject: " << score.first << ", Score: " << score.second << std::endl;
        }
    }
    std::vector<std::string> AllScores() const {
        std::vector<std::string> subcores;
        for (const auto& score : scores_) {
            subcores.push_back(score.first+":"+std::to_string(score.second));
        }
        return subcores;
    }
    bool saveToFile( const std::string filename) const{
        std::ofstream file(filename);
        if (!file) {
            return false;
        }
        for (const auto& score : scores_) {
            file << id_ << ' ' << score.first << ' ' << score.second << std::endl;
        }
        return true;
    }
    bool loadFromFile( const std::string filename){
        std::ifstream file(filename);
        if (!file) {
            return false;
        }
        std::string subject;
        double score;
        while (file >> subject >> score) {
            scores_[subject] = score;
        }
        return true;
    }
    
private:
    std::map<std::string, double> scores_;
    std::string id_;
};
#endif // STUDENTSCORE_H
