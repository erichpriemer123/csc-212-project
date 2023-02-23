#include <iostream>
#include <vector>
#include <string>
#include <tuple>

class course {
	private:
		std::vector<double> assignments{};
		std::vector<double> labs{};
		std::vector<double> projects{};
		double exam;
	public: 
		course();
		
		//add grades to vector 
		void add_assignment();
		void add_lab();
		void add__projects();
		void add_exam();

		//





};