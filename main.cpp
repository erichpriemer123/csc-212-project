#include <iostream>
#include "Gradebook.h"
std::string Choice();
std::string fileCheck();
std::vector<category> dataCollect(std::string);


//Collects data from file and appends them to the appropriate Gradebook object
std::vector<category> dataCollect(std::string file) {
    std::ifstream dataFile(file);
    std::string temp;
    std::vector<std::string> courseList;
    //Pushes back course names to courseList vector, vector if multiple course names
    while (std::getline(dataFile, temp)) {
        if (temp[0] == '/') {
            break;
        }
        else {
            courseList.push_back(temp);
            //If detects / in line begin next process of data collection
        }
    }
    std::string tempCat;
    double tempWeight;
    std::vector<std::pair<std::string, double>> categories;
    //creates a vector that holds a pair representing the category name, and weight in points
    while (std::getline(dataFile, temp)) {
        if (temp[0] == '/') {
            break;
        }
        else {
            std::stringstream foo(temp);
            foo >> tempCat;
            foo >> tempWeight;
            categories.push_back(std::make_pair(tempCat, tempWeight));
        }
    }
    //Creates categories.size() amount of Gradebook objects to store individual
    //Assignment data in a vector containing a tuple
    std::vector<category> categoryObjects;
    for (int i = 0; i < categories.size(); i++) {
        category object = category(categories[i].first, categories[i].second);
        categoryObjects.push_back(object);
    }
    std::tuple<std::string, double, double> individual;
    std::string cat;
    std::string assignmentName;
    double ptsEarned;
    double ptsPossible;
    while (std::getline(dataFile, temp)) {
        std::stringstream foo(temp);
        if (temp[0] == '/') {
            dataFile.close();
            break;
        }
        else {
            foo >> cat;
            foo >> assignmentName;
            foo >> ptsEarned;
            foo >> ptsPossible;
            individual = make_tuple(assignmentName, ptsEarned, ptsPossible);
            for (int i = 0; i < categoryObjects.size(); i++) {
                if (cat == categoryObjects[i].return_string()) {
                    categoryObjects[i].catIndividuals.push_back(individual);
                }
            }
        }   
       
    }
    return categoryObjects;
}

//Recursive function to make sure user input is appropriate and bounds checked
std::string Choice() {
    std::string choice;
    std::cin >> choice;
    if (choice == "Input" || choice == "Manual") {
        return choice;
    }
    else
    {
        std::cout << "Invalid entry, please retry" << std::endl;
        std::cout << R"(Please type "Input" for file to scan or "Manual" for manual entry option)" << std::endl;
        choice = Choice();
    }
}

//Recursive function to make sure the file exists and repeats until a valid file is processed
std::string fileCheck() {
    std::string fileName;
    std::cin >> fileName;
    std::ifstream file(fileName);
    try {
        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file \"" + fileName + "\", please re-enter file name:\n");
        }
        else {
            std::cout << "Gradebook is now being processed using input data of: " + fileName << std::endl;
            return fileName;
        }
    }
    catch (std::exception& e) {
        fileName = fileCheck();
    }
}




int main(int argc, char* argv[]) {
    //First configuration of program,  executable is run without any command line arguments
   
            std::cout << "Please type out the name of your input file!" << std::endl;
            std::string file;
            file = fileCheck();
            std::vector<category> categoryObjects = dataCollect(file);
            gradebook grade_book(categoryObjects);

            //category print methods
            // call on individual categories
            // example
            //no zeros can be passed into singel grade
            grade_book.categories[0].print_single_grade(1);

            //prints individual grade
            void print_single_grade(int index);

            //prints overall grade of this category 
            void print_category_grade();

            //print all category grades and category total 
            void print_all_grades();
           

            //gradebook print methods---------------------------------------------
            // call on gradebook
            // example
            grade_book.print_all();

            //prints course grade
            void print_course_grade();

            //prints category and course grades
            void print_cat_course_grades();

            //prints all grades
            void print_all();






    




    return 0;
}


