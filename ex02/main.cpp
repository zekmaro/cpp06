/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:00:46 by anarama           #+#    #+#             */
/*   Updated: 2024/11/01 12:50:02 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "AH! Its was class A reference. No way!" << std::endl;
		return ;
	} catch (std::exception& e) {
		std::cout << "Nope its not A refernce..." << std::endl;
	}
    try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "AH! Its was class B reference. No way!" << std::endl;
		return ;
	} catch (std::exception& e) {
		std::cout << "Nope its not B refernce..." << std::endl;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "AH! Its was class C reference. No way!" << std::endl;
		return ;
	} catch (std::exception& e) {
		std::cout << "Nope its not C refernce..." << std::endl;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "AH! Its was class A pointer. No way!" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "AH! Its was class B pointer. No way!" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "AH! Its was class C pointer. No way!" << std::endl;
	}
	else {
		std::cout << "Hmmm... Thats strange... We didnt find him." << std::endl;
	}
}

Base* generate( void ) {
	int randomNumber = rand() % 3;
	
	switch (randomNumber) {
		case 0:
			std::cout << "A was created!" << std::endl;
			return new A();
		case 1:
			std::cout << "B was created!" << std::endl;
			return new B();
		case 2:
			std::cout << "C was created!" << std::endl;
			return new C();
		default:
			std::cout << "Math is not mathing..." << std::endl;
			return NULL;
	}
}

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	Base* ptr = generate();
	if (ptr == NULL) {
		std::cout << "Maybe coding is not for me?" << std::endl;
		return 1;
	}
	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}