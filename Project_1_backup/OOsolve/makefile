# Comment lines
# General makefile for c++ - choose PROG = name of given program
# Here we define compiler option, libraries and the target 
CPPflags=c++ -O3
# Here we define the library functions needed 
LIB = -larmadillo -llapack -lblas
# Here we define the name of the executable
PROG=tridiagsolver
${PROG} : 	main.o tridiagsolver.o thomassolver.o
		${CPPflags} main.o tridiagsolver.o thomassolver.o	${LIB} -o ${PROG}
main.o : 				main.cpp
					${CPPflags} -c main.cpp
tridiagsolver.o : 		tridiagsolver.cpp
					${CPPflags} -c tridiagsolver.cpp
thomassolver.o : 			thomassolver.cpp
					${CPPflags} -c thomassolver.cpp

			

