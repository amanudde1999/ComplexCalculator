# ComplexCalculator
Complex number calculator that uses postfix notation.


Intro to Postfix Notation:
-------------------------
	(10+10)*(7-3) = 20*4 = 80
	Postfix Notation: 10 10 + 7 3 - * = 80
	This will store 10 and the other 10 and add them
	Then store 7 and 3 and subtract them
	The result of these two computations will be multiplied.

This calculator can perform: subtraction, multiplication, addition, conjugation and negation.

Running Instructions:
----------------------

Open the terminal and go to the directory containing the Makefile and complex_postfix.cpp and type the "make" command and press enter. This will create a target object called "calc".
To run the complex_postfix.cpp file, enter "./calc" and press enter in the command terminal.
To add a pair to the stack use the following format:

- "V r1 r2" , where r1 is the real number and r2 is the imaginary number
- "B op", where op is any binary operator: addition/subtraction/multiplication
- "U op", where op is any unary operator: conjugation/negation
-  S will end the program and output the result of all the arithmetic.
