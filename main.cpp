#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Gradebook.cpp"
int main(int argc, char* argv[]) {
    //gradebook object created
    GradeBook course;
    //this makes a variable that grabs the argument from commandline
    std::string file_name(argv[1]);
    //create input file stream (takes in file_name)
    std::ifstream input_file_stream(file_name);
    //takes in a string which will be used to grab a line in the txt file
    std::string txt_line;
    std::getline(input_file_stream, txt_line);
    //this grabs the first getline and updates the course_name
    course.name_course(txt_line);
    //string stream created
    std::istringstream s_stream(txt_line);

    //main while loop for the rest of the lines in txt
    //this will put the data from the file into their respective vectors
    //TODO-working with stringstream: we need to grab the last two variables on the line, perhaps making a dummy variable for the first...
    while(std::getline(input_file_stream, txt_line)){
        if(txt_line[0] == 'A'){
            //this should string stream the next 2 values of the line

        }
        if(txt_line[0] == 'L'){

        }
        if(txt_line[0] == 'P'){

        }

    }
    int choice;
    while(choice != '0'){
        std::cout << "Please select an integer 1-5: ";
        std::cout << "--------Individual----" << std::endl;
        std::cout << "1: returns individual grade based on category name" << std::endl;
        std::cout << "--------Category------" << std::endl;
        std::cout << "2: return all grades from a category and its total" << std::endl;
        std::cout << "--------Course--------" << std::endl;
        std::cout << "3: print all grades from category and the course overall" << std::endl;
        std::cout << "4: print category and course total" << std::endl ;
        std::cout << "5: print the overall course grade" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "0: terminate program" << std::endl;
        //im going to put the choice variable into a switch statement
        //TODO- put in the functions according to what the option needs
        switch(choice) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 0:
                std::cout << "program terminated, goodbye" << std::endl;
                return 0;
            default:
                std::cout << "invalid integer, please try again" << std::endl;
        }

    }





}
