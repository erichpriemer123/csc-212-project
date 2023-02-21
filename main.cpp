#include <iostream>
#include "Gradebook.h"

std::string Choice();
std::string fileCheck();
void dataCollect(std::string);

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
            dataCollect(file);
        } else {

            }

    }
    return 0;
}

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

void dataCollect(std::string file) {
    std::ifstream dataFile(file);
    std::string courseName;
    std::vector<std::string> courseList;
    //Pushes back course names to courseList vector
    while (std::getline(dataFile, courseName)){
        courseList.push_back(courseName);
        //If detects blank line begin next process of data collection
        if (courseName.size() == 0) {
            break;
        }
    }
    std::vector<std::pair<std::string, double>> Categories;
    std::string line;
    int i =  0;
    while (dataFile){
        //creates a linestream object of current line
        std::getline(dataFile, line, ' ');
        std::stringstream ss(line);
        //string object for ss to append to
        std::string Cat;
        double Points;
        ss>>Cat;
        ss>>Points;
        std::cout<<Cat;
        std::cout<<Points;
        if(Cat.empty()){
            break;
        }
        }
}



