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

void Gradebook::single_grade(int index){
    std::string grade_name = std::get<0>(catIndividuals[index]);
    double grade = std::get<1>(catIndividuals[index]);
    double grade_weight = std::get<2>(catIndividuals[index]);
    double final = (grade / grade_weight) * 100; 
    
    std::cout << "Grade for " << grade_name << ":" << final << "%" << "\n";
}

void Gradebook::category_grade() {
    double sum;
    for (int i = 0; i < catIndividuals.size(); i++) {
        sum += std::get<1>(catIndividuals[i]);
    }
    double category_grade = (sum / catWeight) * 100; 
    std::cout << "Grade for " << Category << ":" << category_grade << "%" << "\n";
}

void Gradebook::all_grades() {
    //prints out all grades from a category 
    for (int i = 0; i < catIndividuals.size(); i++) {
        single_grade(i);
    }
    //prints out category overall grade 
    category_grade();

}


