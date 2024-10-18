/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:00:46 by anarama           #+#    #+#             */
/*   Updated: 2024/10/18 19:48:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
#include <typeinfo>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "AH! Its was class A refernce. No way!" << std::endl;
		return ;
	} catch (std::bad_cast& e) {
		std::cout << "Something went terribly wrong..." << std::endl;
	}
    try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "AH! Its was class B refernce. No way!" << std::endl;
		return ;
	} catch (std::bad_cast& e) {
		std::cout << "Something went terribly wrong..." << std::endl;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "AH! Its was class C refernce. No way!" << std::endl;
		return ;
	} catch (std::bad_cast& e) {
		std::cout << "Something went terribly wrong..." << std::endl;
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
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			std::cout << "Something went terribly wrong..." << std::endl;
			return NULL;
	}
}

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	Base* ptr = generate();
	if (ptr == NULL) {
		return 1;
	}
	identify(ptr);
	identify(*ptr);

	delete ptr;
	return 0;
}