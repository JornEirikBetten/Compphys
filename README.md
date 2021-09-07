# Computational Physics

This repository will contain projects and other related objects to the course
Computational physics - FYS4150, taken at the University of Oslo. 


Project_1 specifics for running programs: 
Enter Project_1 folder 
Problem 2: \\
1(compile): c++ -c prob2.cpp 
            c++ prob2.o -o prob2 
2(python) : python3 read.py 
Problem 11: 
            c++ -c LUdecomp.cpp
            c++ LUdecomp.o -larmadillo -o LU 
            ./LU N
Rest of problems: 
1 Enter OOsolve folder
2          make
3          ./tridiagsolver N algorithm ("general" or "special") 
