/*
 * helper.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: lowji
 */

#include "helper.h"
#include <sstream>

namespace std {

helper::helper() {
	// TODO Auto-generated constructor stub

}

//method to determine if a string is an integer
bool helper::isInt(string input){
	//Reference: https://stackoverflow.com/questions/20287186/how-to-check-if-the-input-is-a-valid-integer-without-any-other-chars

	int x; //temporary int variable for checking input validity
	char c; //temporary char variable for checking input validity
	istringstream s(input);

	if (!(s >> x)) {
		return false;
	}

	if (s >> c) {
		return false;
	}

	return true;
}

} /* namespace std */
