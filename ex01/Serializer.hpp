/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:01:58 by anarama           #+#    #+#             */
/*   Updated: 2024/10/18 18:59:57 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

# include "Data.hpp"

class Serializer {
	private:
		Serializer( void );
		Serializer( const Serializer& other );
		Serializer& operator=( const Serializer& other );
		~Serializer( void );
	public:
		static uintptr_t serialize(Data* ptr);
};

#endif // SERIALIZER_HPP