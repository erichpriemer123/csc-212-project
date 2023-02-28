//
// Created by Cody on 2/27/2023.
//
#include "Gradebook.h"
//-----------------course_constructors------------------------------------//
category::category(const std::string catName, const double weight) {
    category_name = catName;
    catWeight = weight;
    std::vector<std::tuple<std::string, double, double>> indivAssignments;
}
std::string category::return_string() {
    return category_name;
}
//------------------course-calculation-methods-----------------------------//
double category::single_grade(int index) {
    index = index - 1;
    double grade = std::get<1>(catIndividuals[index]);
    double grade_weight = std::get<2>(catIndividuals[index]);
    double final = (grade / grade_weight) * 100;
    return final;
}
double category::category_grade() {
    double sum = 0;
    for (int i = 0; i < catIndividuals.size(); i++) {
        sum += std::get<1>(catIndividuals[i]);
    }
    double category_grade = (sum / catWeight) * 100;

    return category_grade;
}
double category::category_sum() {
    double sum = 0;
    for (int i = 0; i < catIndividuals.size(); i++) {
        sum += std::get<1>(catIndividuals[i]);
    }
    return sum;
}
//-----------------------------------------print methods----------------------------------------------------------------------//
void category::print_single_grade(int index, std::string file){
    std::fstream openFile;
    openFile.open(file, std::ios::app);
    std::string grade_name = std::get<0>(catIndividuals[index-1]);
    double final = single_grade(index);
    std::cout << "Grade for " << grade_name << ": " << final << "%" << "\n";
    openFile<<"Grade for " << grade_name << ": " << final << "%" << std::endl;
}
void category::print_category_grade(std::string file) {
    std::fstream openFile;
    openFile.open(file, std::ios::app);
    double final = category_grade();
    openFile << "Grade for " << category_name << ": " << final << "%" << std::endl;
    std::cout << "Grade for " << category_name << ": " << final << "%" << "\n";
}
//combination of last two methods
void category::print_all_grades(std::string file) {
    //prints out category overall grade
    print_category_grade(file);
    //prints out all grades from a category
    for (int i = 0; i < catIndividuals.size(); i++) {
        print_single_grade(i+1, file);
    }
}

//----------------------grade_book_methods---------------------------------------//

//----------------constructors-----------------//
gradebook::gradebook(std::vector<category> categoryObjects) {

    //sets
    this->categories = categoryObjects;
    double sum = 0;
    double sum2 = 0;

    for (int i = 0; i < categories.size(); i++) {
        sum += categories[i].catWeight;
        sum2 += categories[i].category_sum();
    }
    total_points_earned = sum2;
    total_possible_points = sum;
}
//--------grade_calculation---------------------//
double gradebook::course_grade() {
    double final_grade = (total_points_earned / total_possible_points) * 100;
    return final_grade;
}

//--print functions----------------------------------------------------------//
//prints only the course overall--------------//
void gradebook::print_course_grade(std::string file) {
    std::fstream openFile;
    openFile.open(file, std::ios::app);
    openFile << "Your final grade is: " << course_grade() << std::endl;
    std::cout << "Your final grade is: " << course_grade() << "\n";
}
//prints only category totals and course overall//
void gradebook::print_cat_course_grades() {
    print_course_grade(file);
    for (int i = 0; i < categories.size(); i++) {
        categories[i].print_category_grade(file);
    }
}
//prints all grades within their respective categories and a course overall
void gradebook::print_all() {
    print_course_grade(file);
    for (int i = 0; i < categories.size(); i++) {
        std::cout << "-------------------------------------" << "\n";
        categories[i].print_all_grades(file);
    }
}