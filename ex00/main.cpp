/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:43:38 by anarama           #+#    #+#             */
/*   Updated: 2024/10/18 17:37:56 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	(void) argv;
	if (argc != 2) {
		std::cout << "Inccorect argument amount!" << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(argv[1]);
	} catch ( const ScalarConverter::IncorrectFormatException& e ) {
		std::cout << "IncorrectFormatException: " << e.what() << std::endl;
	}
	return 0;
}