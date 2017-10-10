
#include "calculator.h"
#include <algorithm>
#include <sstream>

using namespace std;

// helper function to remove spaces in strings.
string remove_spaces (string &s) {
	
	s.erase (remove (s.begin(), s.end(), ' '), s.end());
	
	return (s);
}


int solve_no_space (const string &s) {
	
	stringstream ss;
	
	ss.str(s);
	
	if (ss.peek() == '(') ss.get();
	
	int param1;
	int param2;
	char op;
	
	ss >> param1;
	ss >> op;
	ss >> param2;
	
	if (op == '+') {
		ss << param2;
		return param1 + solve_no_space (ss.str());
	}
	else if (op == '-') {
		ss << param2;
		return param1 - solve_no_space (ss.str());
	}
	else if (op == '*') {
		ss << (param1 * param2);
		return solve_no_space (ss.str());
	}
	else {
		ss << (param1 / param2);
		return solve_no_space (ss.str());
	}
}

// wrapper to remove spaces before solving.
int solve_equation (string s) {
	
	return solve_no_space (remove_spaces (s));
}