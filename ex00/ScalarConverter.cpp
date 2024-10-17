/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:43:50 by anarama           #+#    #+#             */
/*   Updated: 2024/10/17 17:50:25 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* EXCEPTIONS */

const char* ScalarConverter::EmptyStringException::what() const throw() {
	return ("Invalid input\nEmpty string found!");
}

const char* ScalarConverter::MultipleCharsException::what() const throw() {
	return ("Invalid input\nMultiple chars found!");
}


/* MEMBER FUNCTIONS */

bool hasChar( std::string str ) {
	int i = 0;
	while (str[i]) {
		if (std::isalpha(str[i]))
			return true;
		i++;
	}
	return false;
}

void	convertChar( char c ) {
	
}

void	convertNum( std::string str ) {
	
}

void ScalarConverter::convert( std::string str ) {
	if (str.empty()) {
		throw ScalarConverter::EmptyStringException();
	}
	if (hasChar(str)) {
		if (str.length() > 1) {
			throw ScalarConverter::MultipleCharsException();
		}
		else {
			convertChar(str[0]);
		}
	}
	else {
		convertNum(str);
	}
}