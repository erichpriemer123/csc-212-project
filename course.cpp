#include "course.h"
#include<iostream>
#include<vector>
#include<numeric>

gradebook::gradebook() {
}

//--------------------------------------------------------------------------
//These functions allow users to add grades to there respective vectors or variable 
void gradebook::add_assignment(double grade) {
	this->assignments.push_back(grade);
}

void gradebook::add_lab(double grade) {
	this->labs.push_back(grade);
}

void gradebook::add_project(double grade) {
	this->project.push_back(grade);
}

void gradebook::add_exam(double grade) {
	this->exam.push_back(grade);
}

//--------------------------------------------------------------------------
//These functions allow users to get grades from there respective categories 
double gradebook::get_assignment(int index) {
	return this->assignments[index - 1];
}

double gradebook::get_lab(int index) {
	return this->labs[index - 1];
}

double gradebook::get_project(int index) {
	return this->project[index - 1];
}

double gradebook::get_exam() {
	return this->exam[0]; 
}


//-----------------------------------------------------------------------------\
//These functions allow users to get the amount of total points that you can get in a certain categories 
double gradebook::get_assignment_worth() {
	return this->assignment_worth;
}
double gradebook::get_lab_worth() {
	return this->lab_worth;
}
double gradebook::get_project1_worth() {
	return this->project1_worth;
}
double gradebook::get_project2_worth() {
	return this->project2_worth;
}
double gradebook::get_exam_worth() {
	return this->exam_worth;
}



//--------------------------------------------------------------------------
//find percentage grade of single assignment of any type (assignment, lab, project 1 & 2, exam)
double gradebook::single_grade(double grade, double total) {
	double percentage_grade = (grade / total) * 100;
	return percentage_grade;
}

//--------------------------------------------------------------------------
//Find percentage grade of a category 
//only capable of 
double gradebook::category_grade(std::vector<double> category, double category_worth) {
	double sum = 0;
	double total = category_worth * category.size();
	for (auto i : category) {
		sum += i;
	}

	double category_percentage = (sum / total) * 100;

	return category_percentage;
}




//--------------------------------------------------------------------------
//find percentage grade of course
double gradebook::course_grade() {

	//find the total points that the student earned 
	double total_points; 

	double total_assignment_points = accumulate(assignments.begin(), assignments.end(), 0);
	double total_lab_points = accumulate(labs.begin(), labs.end(), 0);
	double total_project_points = accumulate(project.begin(), project.end(), 0);
	double total_exam_points = exam;

	total_points = total_assignment_points + total_lab_points + total_project_points + total_exam_points;


	//Find the maximum amount of points that the student could of earned at anytime 
	double maximum_points; 

	double max_assignment_points = assignments.size() * assignment_worth;
	double max_lab_points = labs.size() * lab_worth;
	double max_project_points = 0;
	if (project.size() == 1) {
		max_project_points = project1_worth;
	}
	else if (project.size() == 2) {
		max_project_points = project1_worth + project2_worth;
	}

	if(exam)
	double max_exam_points = exam_worth;
}