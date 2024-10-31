/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:06:14 by anarama           #+#    #+#             */
/*   Updated: 2024/10/31 11:20:41 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "Data.hpp"

Data::Data( void ) : _type(DEFAULT_TYPE) {}
Data::Data( const Data& other ) : _type(other._type) {}
Data& Data::operator=( const Data& other ) {
	if (this != &other) {
		this->_type = other._type; 
	}
	return *this;
}
Data::~Data( void ) {}

Data* Data::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}