//
// Created by 14753 on 2/17/2023.
//

#ifndef REVIEW_PROJECT_GRADEBOOK_H
#define REVIEW_PROJECT_GRADEBOOK_H
#define REVIEW_PROJECT_GRADEBOOK_H
#include <vector>
#include <string>
class Course {
    //basically
    //courses
    //goes down to
    //categories
    //goes down to
    //grades

    //the list of courses should point to their respective list of categories
    //the list of categories should point to their respective list of named grades
private:
    std::string grade_book_name;
    //perhaps add a variable to count the amount of courses, categories per course, grades per category
    int course_count;
    int category_count;
    int grade_count;
    //this will have three main vectors
    std::vector<std::string> course_vector;
    std::vector<std::string> category_vector;
    //TODO should I separate these values in the vector below???
    std::vector<std::pair<std::string, int>> grade_name_vector;
public:
    //TODO- discuss with the group if these functions make sense in the grander scheme of things
    //required
    //course grades will print a single course grade
    //it compiles all the grades in total
    void print_course_grades();
    //category grades will print the grade you get for the category
    //compiles the grades in the category
    void print_category_grades();
    //individual grades will choose a specific grade based on the user's choice
    void print_individual_grades();
    //we can use this function for the print course and category functions
    int calculate_average();
    //function to help print the grades, helps identify the grade, category, course to the name
    //TODO- try to make this so it is destroyed each time it is printed so the user can use it again
    //returns a vector of pairs (which contains a string for the name, and an integer for grade)
    //ALSO NOTE:
    //we could try to make this into a matrix...
    std::vector<std::pair<std::string, int>> print_name_to_grade(/* idk what to put in here, im tired lol*/ );

};

#endif //REVIEW_PROJECT_GRADEBOOK_H
