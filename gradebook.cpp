//
// Created by Cody on 2/23/2023.
//

#include "Gradebook.h"
//-----------------course_constructors------------------------------------//
category::category() {
    category_name;
    catWeight;
    catIndividuals;
}
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
void category::print_single_grade(int index){

    std::string grade_name = std::get<0>(catIndividuals[index-1]);
    double final = single_grade(index);

    std::cout << "Grade for " << grade_name << ":" << final << "%" << "\n";
}

void category::print_category_grade() {
    double final = category_grade();
    std::cout << "Grade for " << category_name << ":" << final << "%" << "\n";
}


//combination of last two methods
void category::print_all_grades() {
    //prints out category overall grade 
    print_category_grade();
    //prints out all grades from a category 
    for (int i = 0; i < catIndividuals.size(); i++) {
        print_single_grade(i+1);
    }
    

}




//----------------------grade_book_methods---------------------------------------//

//----------------constructors-----------------//
gradebook::gradebook() {
    categories;
    total_possible_points;
}

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
void gradebook::print_course_grade() {
    std::cout << "Your final grade is: " << course_grade() << "\n";
}

//prints only category totals and course overall//
void gradebook::print_cat_course_grades() {
    print_course_grade();
    for (int i = 0; i < categories.size(); i++) {
        categories[i].print_category_grade();
    }

}



//prints all grades within their respective categories and a course overall
void gradebook::print_all() {
    print_course_grade();
    for (int i = 0; i < categories.size(); i++) {
        std::cout << "-------------------------------------" << "\n";
        categories[i].print_all_grades();
    }

}