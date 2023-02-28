CSC 212 review project 

SUMMARY
Our program is able to process any course that you have taken and output your grade averages based on the scores you have received.
Each course can be looked at as a collection of different categories of assignments. These categories may include exams, homework, quizzes, in class assignments, etc. Users can provide input to the program, in order to receive specific information about their course grades. This output includes:
- The grade you have received for a specific assignment
- The overall grade of a specified category and all the individual assignment grades that are in that category
- All grades. Including category grades, the individual assignment grades within those categories, and your 
final grade of the course 
- The course grades and the final grade
- Only the final grade 
 
We are able to calculate these based on a text file given by the user. This text file will include all of the categories and how much weight they hold towards the final grade as well as each individual assignment. What makes our program unique is the fact that you can use any course within the program, not just csc 212. It can take in any amount of categories and any amount of assignments and produce an accurate grade.   

COMPILATION INSTRUCTIONS
User must either run the executable as the only command line argument, or have two command line arguments, the first being the executable, and the second being a validly 
formated text file. 
CONFIG 1
gradebook.exe
or
CONFIG 2
gradebook.exe text_file.txt

If the first configuartion is run, the user is asked to input the name of a valid text file and will not continue until the condition is met. The data is then 
automatically collected as long as a text file is provided within either configuration. The user is granted 6 prompts to chose from as for what the program can do,
choices 1-5 being actual meaningful functions that print out to the terminal and write to the original input file, and choice 0 being an exit choice which halts the
program. We tried exception handling where it was important, the file check function. If the file isn't existent, the function will cease to run. 
