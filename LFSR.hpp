/*
 * LFSR.hpp
 *  Author: Patrick Kyoyetera
 *  Date: Sunday October 01, 2016\
 *  Assignment: Assignment PS2 part b
 *  Description: Linear Feedback Shift Register implementation and photo
 * 					encryption 				
 */

#ifndef LFSR_HPP
#define LFSR_HPP


#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

template <typename T>
std::string to_string(T value) {
	std::ostringstream os ;
	os << value ;
	return os.str();
}

class LFSR {
	public:
		LFSR(std::string seed, int tap);
		~LFSR();
		int step();
		int generate(int k);
		friend std::ostream& operator<< (std::ostream &out, LFSR &lfsr);
	//protected:
		std::string _seed;
		int _tap;
};
//return excusive or op for 2 ints
int exclus(int,int);

sf::Image transform(LFSR& _lfsr,sf::Image& _image);

#endif
