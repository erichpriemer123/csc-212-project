//
// Created by Cody on 2/23/2023.
//

#include "Gradebook.h"

Gradebook::Gradebook (const std::string catName, const double weight){
    Category = catName;
    catWeight=weight;
    std::vector<std::tuple<std::string,double,double>> indivAssignments;
}

std::string Gradebook::return_string(){
    return Category;
}


