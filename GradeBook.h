//
// Created by 14753 on 2/17/2023.
//

#ifndef REVIEW_PROJECT_GRADEBOOK_H
#define REVIEW_PROJECT_GRADEBOOK_H
#define REVIEW_PROJECT_GRADEBOOK_H
#include <vector>
#include <string>
class GradeBook {


    //basically
    //courses
    //goes down to
    //categories
    //goes down to
    //grades

    //the list of courses should point to their respective list of categories
    //the list of categories should point to their respective list of named grades
private:
    std::string course_name;
    //vector holds variable grade(double) variable
    //there are three main category vectors
    std::vector<std::pair<double,double>> assignments;
    std::vector<std::pair<double,double>> labs;
    std::vector<std::pair<double,double>> projects;
    double exam;
public:
    GradeBook();

    //add grades to vector
    void add_assignment(double grade, double total);
    void add_lab(double grade, double total);
    void add_projects(double grade, double total);
    void add_exam(double grade, double total);
    //calculates average of a category for a vector
    double calc_category_average(std::vector<std::pair<double,double>>);
    //grab grade function returns double
    double calc_course_average(std::vector<std::pair<double,double>>);
    double grab_grade(std::vector<std::pair<double,double>>);
};

#endif //REVIEW_PROJECT_GRADEBOOK_H
