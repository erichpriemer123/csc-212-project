//
// Created by Cody on 2/16/2023.
//

#ifndef GRADEBOOK_GRADEBOOK_H
#define GRADEBOOK_GRADEBOOK_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>
#include <tuple>

class Gradebook {

private:
    //Every gradebook object that's created has a name
    std::string CourseName;
    //Each course has its own grade categories
    //Vector will store the name of the category, and the points per category attainable
    std::vector<std::pair<std::string, double>> Categories;
    //Create a vector with the respective name of the category type which
    //stores at every point: The assignment name, points obtained, and the maximum points possible per assignment
    std::vector<std::tuple<std::string, double, double>> AssignmentsInCategory;

public:
    //constructs gradebook of coursename
    Gradebook(const std::string CourseName, const std::vector<std::pair<std::string, double>> Categories, const std::vector<std::tuple<std::string, double, double>> AssignmentsInCategory);
};


#endif //GRADEBOOK_GRADEBOOK_H
