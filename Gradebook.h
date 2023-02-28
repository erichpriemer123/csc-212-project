//
// Created by Cody on 2/27/2023.
//
#ifndef GRADEBOOK_FINAL_GRADEBOOK_H
#define GRADEBOOK_FINAL_GRADEBOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <tuple>

class category {
public:
    //"Name of object" as object names cant be customized in runtime
    std::string category_name;
    double catWeight;
    std::string file;
    //every object created by the Gradebook class stores individual assignments,
    // the total points earned for the assignment, and the total points possible
    std::vector<std::tuple<std::string, double, double>> catIndividuals;
    //Gradebook object constructor
    category(const std::string catName, const double weight);
    std::string return_string();
    //calculation methods--------------------------------------------------------
    //calculates individual grade of single item
    double single_grade(int index);
    //calculates overall grade of this category
    double category_grade();
    //returns the total amount of points that your have earned within the course
    //used for find course overall grade
    double category_sum();
    //print methods-------------------------------------------------------------
    //prints individual grade
    void print_single_grade(int index, std::string file);
    //prints overall grade of this category
    void print_category_grade(std::string file);
    //print all category grades and category total
    void print_all_grades(std::string file);
};
class gradebook {

public:
    std::string file;
    std::vector<category> categories;
    double total_points_earned;
    double total_possible_points;
    //gradebook constructor
    //sets course total by adding up catweight of each
    gradebook(std::vector<category> categoryObjects);
    //calculates final grade
    double course_grade();
    //prints out all category totals and course overall
    void print_course_grade(std::string file);
    void print_cat_course_grades();
    void print_all();
};
#endif //GRADEBOOK_FINAL_GRADEBOOK_H
