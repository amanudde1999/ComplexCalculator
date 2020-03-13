//------------------------------------------------------
// Names: Amro Amanuddein
// ID: 1572498
// CMPUT275, Winter 2020
// 
// Weekly Exercise 6: STL Concepts
//------------------------------------------------------

#include <utility>
#include <stack>
#include <iostream>

using namespace std;

int main(){
	stack< pair<long long, long long>> input;
	// Give it an initial letter/number so that it can not be given a random  one and not enter the while loop
	char operate = '0';
	char op;
	long long r1,r2;
	// Continue running until you enter S
	while(operate != 'S'){
		// See if you want to: 1. add a pair to the stack, 2. perform a unary operation or 3. perform a binary operation
		cin >> operate;
		// To add a new pair to the stack
		if (operate == 'V'){
			// Input the two numbers where r1 is the real and r2 is the imaginary
			cin >> r1 >> r2;
			pair <long long, long long> exp;
			exp.first = r1;
			exp.second = r2;
			// Add this new pair to the stack
			input.push(exp);
		}
		// For unary operations, enter U
		else if(operate == 'U'){
			cin >> op;
			// c for the conjugation operation
			if (op == 'c'){
				// Take a pair from the top of the stack and store it to perform a conjugation on it
				pair <long long,long long> top_pair = input.top();
				// Final result of operation will be stored here
				pair <long long,long long> new_pair;
				// Remove from the top of the stack
				input.pop();
				long long real = top_pair.first;
				// Conjugation just reverses the sign of the imaginary component, the real component is unchanged
				long long imaginary = -top_pair.second;
				new_pair.first = real;
				new_pair.second = imaginary;
				// Add it back to the top of the stack
				input.push(new_pair);
			}
			// - for negation operation
			else if (op == '-'){
				pair <long long, long long> top_pair = input.top();
				pair <long long, long long> new_pair;
				input.pop();
				// Negation operation reverses the signs of both the imaginary component and the real component
				long long real = -top_pair.first;
				long long imaginary = -top_pair.second;
				new_pair.first = real;
				new_pair.second = imaginary; 
				input.push(new_pair);
			}
		}
		// For binary operations use B
		else if(operate == 'B'){
			cin >> op;
			// - for subtraction (not the same as negation)
			if (op == '-'){
				// For any binary operations, we need two pairs from the stack
				pair<long long,long long> top_pair1 = input.top();
				input.pop();
				pair<long long,long long> top_pair2 = input.top();
				input.pop();
				pair <long long,long long> new_pair;
				long long real1 = top_pair1.first;
				long long imaginary1 = top_pair1.second;
				long long real2 = top_pair2.first;
				long long imaginary2 = top_pair2.second;
				// Subtraction of the real components and imaginary components separately
				// i.e. (a+bi)-(c+di) = (a-c)+i(b-d)
				new_pair.first = real2 - real1;
				new_pair.second = imaginary2 - imaginary1;
				input.push(new_pair);
			}
			else if (op == '+'){
				pair <long long, long long> top_pair1 = input.top();
				input.pop();
				pair<long long,long long> top_pair2 = input.top();
				input.pop();
				pair<long long,long long> new_pair;
				long long real1 = top_pair1.first;
				long long imaginary1 = top_pair1.second;
				long long real2 = top_pair2.first;
				long long imaginary2= top_pair2.second;
				// Addition of the real and imaginary components separately
				// i.e. (a+bi)+(c+di) = (a+c)+i(b+d)
				new_pair.first = real1+real2;
				new_pair.second = imaginary1+imaginary2;
				input.push(new_pair);

			}
			else if (op == '*'){
				pair <long long,long long> top_pair1=input.top();
				input.pop();
				pair <long long,long long> top_pair2=input.top();
				input.pop();
				pair<long long,long long> new_pair;
				long long real1 = top_pair1.first;
				long long imaginary1 = top_pair1.second;
				long long real2 = top_pair2.first;
				long long imaginary2 = top_pair2.second;
				// Multiplication is done as follows: 
				// 	(a+bi)*(c+di) = (a*c)+i(a*d+c*d)+(bi*di)
				// Multiplication of two imaginary components results in a negative sign since (i*i)= -1
				new_pair.first = (real1*real2)+(-(imaginary1*imaginary2));
				new_pair.second = (real1*imaginary2)+(real2*imaginary1);
				input.push(new_pair); 
			}
		}
	}
	pair <long long, long long> output_pair = input.top();
	cout << (output_pair.first) << " " << (output_pair.second) << endl;
	return 0;

}