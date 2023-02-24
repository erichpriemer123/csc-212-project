#include <iostream>
#include "Gradebook.h"
std::string Choice();
std::string fileCheck();
std::vector<Gradebook> dataCollect(std::string);

int main(int argc, char * argv[]) {
    //First configuration of program,  executable is run without any command line arguments
    if (argc==1) {
        std::cout<< "Hi welcome to the Gradebook program. You have not input any command line arguments and have just run the executable"<< std::endl;
        std::cout << "Would you like to type the name of an input file or run the program manually?" << std::endl;
        std::cout << R"(Please type "Input" for file to scan or "Manual" for manual entry option)" << std::endl;
        std::string choice = Choice();

        if (choice=="Input"){
            std::cout<<"Please type out the name of your input file!"<<std::endl;
            std::string file;
            file = fileCheck();
            std::vector<Gradebook> categoryObjects = dataCollect(file);

        } else {

        }

    }
    return 0;
}
//Recursive function to make sure user input is appropriate and bounds checked
std::string Choice(){
    std::string choice;
    std::cin >> choice;
    if (choice=="Input"||choice=="Manual") {
        return choice;
    }
    else
    {
        std::cout<<"Invalid entry, please retry"<<std::endl;
        std::cout << R"(Please type "Input" for file to scan or "Manual" for manual entry option)" << std::endl;
        choice = Choice();
    }
}
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
std::vector<Gradebook> dataCollect(std::string file) {
    std::ifstream dataFile(file);
    std::string temp;
    std::vector<std::string> courseList;
    //Pushes back course names to courseList vector, vector if multiple course names
    while (std::getline(dataFile, temp)) {
        courseList.push_back(temp);
        //If detects / in line begin next process of data collection
        if (temp[0] == '/') {
            break;
        }
    }
    std::string tempCat;
    double tempWeight;
    std::vector<std::pair<std::string, double>> categories;
    //creates a vector that holds a pair representing the category name, and weight in points
    while(std::getline(dataFile, temp)){
        std::stringstream foo(temp);
        foo >> tempCat;
        foo >> tempWeight;
        categories.push_back(std::make_pair(tempCat,tempWeight));
        if (temp[0] == '/') {
            break;
        }
    }
    //Creates categories.size() amount of Gradebook objects to store individual
    //Assignment data in a vector containing a tuple
    std::vector<Gradebook> categoryObjects;
    for (int i = 0; i<categories.size();i++){
        Gradebook object = Gradebook(categories[i].first, categories[i].second);
        categoryObjects.push_back(object);
    }
    std::tuple<std::string, double, double> individual;
    std::string cat;
    std::string assignmentName;
    double ptsEarned;
    double ptsPossible;
    while(std::getline(dataFile, temp)) {
        std::stringstream foo(temp);
        foo >> cat;
        foo >> assignmentName;
        foo >> ptsEarned;
        foo >> ptsPossible;
        individual = make_tuple(assignmentName, ptsEarned, ptsPossible);
        for (int i = 0; i < categoryObjects.size();i++){
            if (cat==categoryObjects[i].return_string()){
                categoryObjects[i].catIndividuals.push_back(individual);
            }
        }
        if (temp[0] == '/') {
            dataFile.close();
            break;
        }
    }
    return categoryObjects;
    }