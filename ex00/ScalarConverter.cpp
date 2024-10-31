/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:43:50 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 11:08:03 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

#include "ScalarConverter.hpp"

/* EXCEPTIONS */

const char* ScalarConverter::IncorrectFormatException::what() const throw() {
	return "Incorrect input format!";
}

/* MEMBER FUNCTIONS */

void	ToChar( double value ) {
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<int>(value))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "' " << std::endl;
	}
}

void	ToInt( double value ) {
	if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void ToFloat( double value ) {
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    }
}

void ToDouble( double value ) {
    if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::convert( const std::string& str ) {
	if (str.empty()) {
		throw ScalarConverter::IncorrectFormatException();
	}
	double value = 0.0;
	if (str.length() == 1 && std::isalpha(str[0])) {
		value = static_cast<double>(str[0]);
	} else {
		char* end = NULL;
		value = strtod(str.c_str(), &end);
		if (end == str.c_str()) {
			throw ScalarConverter::IncorrectFormatException();
		} else if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
			throw ScalarConverter::IncorrectFormatException();
		}
	}
	ToChar(value);
	ToInt(value);
	ToFloat(value);
	ToDouble(value);
}