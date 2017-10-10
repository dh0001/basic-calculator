
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
	
	if (ss.peek() == '(') ss.get();
	
	int param1;
	ss >> param1;
	
	if (ss.peek() == -1 or ss.peek() == ')') return param1;
	
	int param2;
	char op;

	ss >> op;
	ss >> param2;
	
	string rest;
	
	getline (ss, rest);
	
	if (op == '+') {
		return param1 + solve_no_space (to_string (param2) + rest);
	}
	else if (op == '-') {
		return param1 - solve_no_space (to_string (param2) + rest);
	}
	else if (op == '*') {
		return solve_no_space (to_string (param1 * param2) + rest);
	}
	else {
		return solve_no_space (to_string (param1 / param2) + rest);
	}
}

// wrapper to remove spaces before solving.
int solve_equation (string s) {
	
	return solve_no_space (remove_spaces (s));
}