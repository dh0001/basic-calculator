
#include "calculator.h"
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

// helper function to remove spaces in strings.
string remove_spaces (string &s) {
	
	s.erase (remove (s.begin(), s.end(), ' '), s.end());
	
	return (s);
}


int solve_no_space (const string &s) {
	
	istringstream ss;
	
	ss.str(s);
	
	// check if it begins with bracket
	if (ss.peek() == '(') ss.get();
	
	// get first number
	int param1;
	ss >> param1;
	
	if (ss.peek() == -1) return param1;	// check if end of file
	
	
	// get operator
	char op;
	ss >> op;

	
	// check if next parameter is a bracketed expression
	bool in_bracket = false;
	if (ss.peek() == '(') {
		ss.get();	// skip the bracket
		in_bracket = true;
	}
	
	
	// get the next paramater
	int param2;
	ss >> param2;
	
	
	// get the rest of the equation
	string rest;
	getline (ss, rest);
	
	
	if (op == '+') {
		return param1 + solve_no_space (to_string (param2) + rest);
	} 
	else if (op == '-') {
		return param1 - solve_no_space (to_string (param2) + rest);
	} 
	else if (in_bracket){
		
		if (op == '*') {
			return param1 * solve_no_space (to_string (param2) + rest);
		}
		else {
			return param1 / solve_no_space (to_string (param2) + rest);
		}
		
	}
	else if (op == '*') {
		return solve_no_space (to_string (param1 * param2) + rest);
	}
	else {
		return solve_no_space (to_string ((float) param1 / (float) param2) + rest);
	}
}

// wrapper to remove spaces before solving.
int solve_equation (string s) {
	
	return solve_no_space (remove_spaces (s));
}