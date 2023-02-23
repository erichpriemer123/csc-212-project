#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
class gradebook {
	private:
		//ASSIGNMENT DATA-------------------------------------
		std::vector<double> assignments{};
		double assignment_worth = 50;

		//LAB DATA--------------------------------------------
		std::vector<double> labs{};
		double lab_worth = 20;

		//PROJECT DATA--------------------------------------
		std::vector<double> project;
		double project1_worth = 150;
		double project2_worth = 350;

		//EXAM DATA-------------------------------------------
		double exam;
		double exam_worth = 100;

	public: 
		gradebook();
		
		//add grades to vector 
		void add_assignment(double grade);
		void add_lab(double grade);
		void add_project(double grade);
		void add_exam(double grade);

		//get grades from vectors 
		double get_assignment(int index);
		double get_lab(int index);
		double get_project(int index);
		double get_exam();

		//get grade worth based on category 
		double get_assignment_worth();
		double get_lab_worth();
		double get_project1_worth();
		double get_project2_worth();
		double get_exam_worth();

		//find grade for single assignment
		double single_grade(double grade, double total);

		//find grade for assignment categatergoy 
		double category_grade(std::vector<double> category, double category_worth);


		//find grade for course 
		double course_grade();

};