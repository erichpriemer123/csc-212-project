//
// Created by Cody on 2/23/2023.
//

#ifndef REGRADEBOOK_GRADEBOOK_H
#define REGRADEBOOK_GRADEBOOK_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <tuple>

class Gradebook {
    public:
    //"Name of object" as object names cant be customized in runtime
    std::string Category;
    double catWeight;
    //every object created by the Gradebook class stores individual assignments,
    // the total points earned for the assignment, and the total points possible
    std::vector<std::tuple<std::string, double, double>> catIndividuals;

    //Gradebook object constructor
    Gradebook(const std::string catName, const double weight);

    std::string return_string();
    
     //find individual grade
    void single_grade(int index);

    //prints overall grade of this category 
    void category_grade();

    //print all category grades and category total 
    void all_grades();


};


#endif //REGRADEBOOK_GRADEBOOK_H
