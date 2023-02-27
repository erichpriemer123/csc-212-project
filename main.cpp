#include <iostream>
#include "Gradebook.h"
    std::string fileCheck();
    std::vector<category> dataCollect(std::string);
//std::get<1>indiv_assignments

//Recursive function to make sure the file exists and repeats until a valid file is processed
    std::string fileCheck(){
        std::string fileName;
        std::cin >> fileName;
        std::ifstream file(fileName);
        try {
            if (!file.is_open()) {
                throw std::runtime_error("Unable to open file \"" + fileName + "\", please re-enter file name:\n");
            } else {
                std::cout<<"Gradebook is now being processed using input data of: "+fileName<<std::endl;
                return fileName;
            }
        } catch (std::exception &e){
            fileName = fileCheck();
        }
    }
//Collects data from file and appends them to the appropriate Gradebook object
    std::vector<category> dataCollect(std::string file){
        std::ifstream dataFile(file);
        std::string temp;
        std::vector<std::string> courseList;
        //Pushes back course names to courseList vector, vector if multiple course names
        while (std::getline(dataFile, temp)) {
            //If detects / in line begin next process of data collection
            if (temp[0] == '/') {
                break;
            }
            else {
                courseList.push_back(temp);
            }
        }
        std::string tempCat;
        double tempWeight;
        std::vector<std::pair<std::string, double>> categories;
        //creates a vector that holds a pair representing the category name, and weight in points
        while(std::getline(dataFile, temp)){
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
        for (int i = 0; i<categories.size();i++){
            category object = category(categories[i].first, categories[i].second);
            categoryObjects.push_back(object);
        }
        std::tuple<std::string, double, double> individual;
        std::string cat;
        std::string assignmentName;
        double ptsEarned;
        double ptsPossible;
        while(std::getline(dataFile, temp)) {
            if (temp[0] == '/') {
                dataFile.close();
                break;
            }
            else {
                std::stringstream foo(temp);
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

int main(int argc, char * argv[]) {
    //First configuration of program,  executable is run without any command line arguments
    if (argc==1) {
        std::cout << "Hi welcome to the Gradebook program. You have not input any command line arguments and have just run the executable" << std::endl;
        std::cout << "Please input text file" << std::endl;
        std::cout << "Please type out the name of your input file!" << std::endl;
        std::string file;
        file = fileCheck();
        std::vector<category> categoryObjects = dataCollect(file);
        gradebook grade_book (categoryObjects);
        //Luca's switch statement below line 16---------------------------------------------------------------------------
        int choice = 10;
        while (choice != 0) {
            std::cout << "Please select an integer 1-5: " << std::endl;
            std::cout << "--------Individual----" << std::endl;
            std::cout << "1: returns individual grade based on category name" << std::endl;
            std::cout << "--------Category------" << std::endl;
            std::cout << "2: return all grades from a category and its total" << std::endl;
            std::cout << "--------Course--------" << std::endl;
            std::cout << "3: print all grades from category and the course overall" << std::endl;
            std::cout << "4: print category and course total" << std::endl;
            std::cout << "5: print the overall course grade" << std::endl;
            std::cout << "-------------------------------" << std::endl;
            std::cout << "0: terminate program" << std::endl;
            std::cin >> choice;
            //im going to put the choice variable into a switch statement
            //TODO- make sure the user can put in the choice
            switch (choice) {
                //finding individual grade
                case 1: {
                    std::string category_search;
                    std::cout << "Enter category name:" << std::endl;
                    std::cin >> category_search;
                    //search for particular grade
                    for (int i = 0; i < grade_book.categories.size(); i++) {
                        if (category_search == grade_book.categories[i].category_name) {
                            std::string individual_search;
                            std::cout << "Enter individual grade name:" << std::endl;
                            std::cin >> individual_search;
                            category selected_category = grade_book.categories[i];
                            for (int j = 0; j < selected_category.catIndividuals.size(); j++) {
                                //get<0> is catIndividuals at tuple 0
                                if (individual_search == std::get<0>(selected_category.catIndividuals[j])) {
                                    //runs function
                                    selected_category.print_single_grade(j+1);
                                    break;
                                }

                            }
                            //added break because it was outputting else below
                            break;
                        }

                    }
                }
                    break;

                    //case 2: returns all grades from a category and its total
                case 2: {
                    std::string category_search;
                    std::cout << "Enter category name:" << std::endl;
                    std::cin >> category_search;
                    //search for particular grade
                    for (int i = 0; i < grade_book.categories.size(); i++) {
                        if (category_search == grade_book.categories[i].category_name) {
                            std::cout<< "If statement ran with: "<<grade_book.categories[i].category_name;
                            //category single_category = grade_book.categories[i];
                            //TODO: enter function here
                            grade_book.categories[i].category::category_grade();
                        }
                    }
                    break;
                }
                    //case 3: print all grades from a category and course overall
                case 3: {
                    std::string category_search;
                    std::cout << "Enter category name:" << std::endl;
                    std::cin >> category_search;
                    for (int i = 0; i < categoryObjects.size(); i++) {
                        if (category_search == grade_book.categories[i].category_name) {
                            //TODO: enter category function here

                            //TODO: enter course total function here

                            //TODO: enter all grades function here
                            grade_book.course_grade();

                        } else {
                            std::cout << "Category not included in text file." << std::endl;
                            break;
                        }
                    }
                    break;
                }
                    //case 4: print category and course total
                case 4: {
                    std::string category_search;
                    std::cout << "Enter category name:" << std::endl;
                    std::cin >> category_search;
                    for (int i = 0; i < categoryObjects.size(); i++) {
                        if (category_search == grade_book.categories[i].category_name) {
                            //TODO: enter category function here

                            //TODO: enter course total function here

                        } else {
                            std::cout << "Category not included in text file." << std::endl;
                            break;
                        }
                    }
                    break;
                }
                    //case 5: print the overall course grade
                case 5: {
                    //TODO:enter course grade function here

                    break;
                }

            }

            break;

        }

    }

    //TODO: make output of input file into the inputfile

    return 0;
