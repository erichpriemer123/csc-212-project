#include <iostream>
#include "Gradebook.h"
std::string fileCheck();
std::vector<category> dataCollect(std::string);
void Gradebook_Funcs(std::vector<category> categories, std::string file);

void Gradebook_Funcs(std::vector<category> categories, std::string file) {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\nPlease select an integer 1-5: " << std::endl;
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
        switch (choice) {
            case 0: {
                break;
            }
                //finding individual grade
            case 1: {
                std::string category_search;
                std::cout << "Enter category name:" << std::endl;
                std::cin >> category_search;
                //search for particular grade
                for (int i = 0; i < categories.size(); i++) {
                    if (category_search == categories[i].category_name) {
                        std::string individual_search;
                        std::cout << "Enter individual grade name:" << std::endl;
                        std::cin >> individual_search;
                        category selected_category = categories[i];
                        for (int j = 0; j < selected_category.catIndividuals.size(); j++) {
                            //get<0> is catIndividuals at tuple 0
                            if (individual_search == std::get<0>(selected_category.catIndividuals[j])) {
                                //runs function
                                selected_category.print_single_grade(j + 1);
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
                std::cout << "Enter category name: " << std::endl;
                std::cin >> category_search;
                //search for particular grade
                for (int i = 0; i < categories.size(); i++) {
                    if (category_search == categories[i].category_name) {
                        //TODO: enter function here
                        categories[i].print_category_grade();
                    }
                }
                break;
            }
                //case 3: print all grades from a category and course overall
            case 3: {
                std::string category_search;
                std::cout << "Enter category name: " << std::endl;
                std::cin >> category_search;
                for (int i = 0; i < categories.size(); i++) {
                    if (category_search == categories[i].category_name) {
                        categories[i].print_all_grades();
                    }
                }
                break;
            }
                //case 4: print category and course total
            case 4: {
                std::string category_search;
                std::cout << "Enter category name: " << std::endl;
                std::cin >> category_search;
                for (int i = 0; i < categories.size(); i++) {
                    if (category_search == categories[i].category_name) {
                        categories[i].print_category_grade();
                        gradebook gradebook(categories);
                        gradebook.print_course_grade();
                    }
                }
                break;
            }
                //case 5: print the overall course grade
            case 5: {
                gradebook gradebook(categories);
                gradebook.print_course_grade();
                break;
            }
        }
    }
}



//Collects data from file and appends them to the appropriate category class object
std::vector<category> dataCollect(std::string file) {
    std::ifstream dataFile(file); //opens file
    std::cout << "Gradebook is now being processed using input data of: " + file << std::endl;
    std::string temp; //temporary string to hold data of line
    std::vector<std::string> courseList; // could be a string but originally was designed with the intent of multiple courses in the same instance of program
    //Pushes back course names to courseList vector, vector if multiple course names
    while (std::getline(dataFile, temp)) {
        //if text file line only contains '/', break and continue to next process
        if (temp[0] == '/') {
            break;
        }
        else {
            courseList.push_back(temp);
        }
    }
    //vars that get updated in the while loop to have string stream appended to them
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
            //makes live pair using the two temp variables to push back into category vector
            categories.push_back(std::make_pair(tempCat, tempWeight));
        }
    }
    //Creates categories.size() amount of 'category' objects to store individual
    //assignment data in a vector containing a tuple
    std::vector<category> categoryObjects;
    for (int i = 0; i < categories.size(); i++) {
        //since objects cannot be created with incremental, 'obj1', 'obj2', (custom variable names during runtime)
        // the best I could do is rewrite over a single object creation and update the parameters using the categories vector
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
            foo >> cat;//doesn't get stored, used to find what category object to append to however
            foo >> assignmentName;// tuple <0>
            foo >> ptsEarned;// tuple <1>
            foo >> ptsPossible;// tuple <2>
            individual = make_tuple(assignmentName, ptsEarned, ptsPossible);
            //runs through category vector to find if "cat" matches the category name variable stored in the objectVector at index i
            //if matches, add the tuple, "individual" to the respective category object stores in categoryObjects vector
            for (int i = 0; i < categoryObjects.size(); i++) {
                if (cat == categoryObjects[i].return_string()) {
                    categoryObjects[i].catIndividuals.push_back(individual);
                }
            }
        }

    }
    //returns a vector storing objects of the category class
    return categoryObjects;
}

/* No longer in use as we decided manual entry mode would be too tedious to bug check, as we
   would be entering about 5 catgeories and 40 assignments and grades and max grads by hand,, not efficient of our time.

Recursive function to make sure user input is appropriate and bounds checked
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
*/

//Recursive function to make sure the file exists and repeats until a valid file is processed
std::string fileCheck() {
    std::string fileName;
    std::cin >> fileName;
    std::ifstream file(fileName);
    //researched exception handling, in this case throws a runtime error and once caught, reruns function until condition satisfied
    try {
        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file \"" + fileName + "\", please re-enter file name:\n");
        }
        else {
            return fileName;
        }
    }
    catch (std::exception& e) {
        fileName = fileCheck();
    }
}

int main(int argc, char * argv[]) {
    //First configuration of program, executable is run without any command line arguments
    if (argc==1) {
        std::cout<< "Hi welcome to the Gradebook program. You have not input any command line arguments and have just run the executable"<< std::endl;
        std::cout<<"Please type out the name of your input file!"<<std::endl;
        std::string file = fileCheck();
        std::vector<category> categoryObjects = dataCollect(file);
        gradebook grade_book (categoryObjects);
        Gradebook_Funcs(grade_book.categories, file);
        std::cout<<"Outputs have been added to the input file: "<<file;
    } else {
        //Second configuration of program, executable is run with one command line arguments being the name of the input file
        //assumes person running the program knows the file exists and is spelled properly*
        std::string file = argv[1];
        std::vector<category> categoryObjects = dataCollect(file);
        gradebook grade_book (categoryObjects);
        Gradebook_Funcs(grade_book.categories, file);
        std::cout<<"Outputs have been added to the input file: "<<file;
    }
    return 0;
}

