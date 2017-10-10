
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
	
	return 1;
}

// wrapper to remove spaces before solving.
int solve_equation (string s) {
	
	return solve_no_space (remove_spaces (s));
}