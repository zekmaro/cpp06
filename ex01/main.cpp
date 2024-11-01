/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:02:05 by anarama           #+#    #+#             */
/*   Updated: 2024/11/01 12:50:34 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
	Data a;
	
	std::cout << "address of a: " << &a << std::endl;
	uintptr_t b = Serializer::serialize(&a);

	std::cout << "value of b: " << b << std::endl;
	std::cout << "Address of b: " << &b << std::endl;

	Data *ptr = Data::deserialize(b);

	std::cout << "Value of ptr pointer: " << ptr << std::endl;
	
}
