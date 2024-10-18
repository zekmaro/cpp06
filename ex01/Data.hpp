/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:06:17 by anarama           #+#    #+#             */
/*   Updated: 2024/10/18 19:08:45 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>
# include <string>

# define DEFAULT_TYPE "none"

class Data {
	private:
		std::string _type;
		
	public:
		Data( void );
		Data( const Data& other );
		Data& operator=( const Data& other );
		~Data( void );

		static Data* deserialize(uintptr_t raw);
};

#endif // DATA_HPP