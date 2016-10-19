/*
* Author: Patrick Koyetera
* Assignment: PS2a
**/

#include "LFSR.hpp"

LFSR::LFSR(std::string seed, int tap) : _seed(seed),_tap(tap) {  }

int LFSR::step() {
	//store result of XOR op in shift bit, to be inserted at end
	int shift_bit=exclus(_seed.at(0),_seed.at((_seed.size()-1-_tap)));

	//erase first bit and concat with shift bit
	this->_seed.erase(0,1);
	this->_seed=this->_seed+to_string(shift_bit);

	return shift_bit;	
}
//XOR
int exclus(int a,int b) {
	if(a xor b)
		return 1;
	return 0;
}
//returns last 5 bits of the step function after doubling it k steps and adding /the bit
int LFSR::generate(int k) {
	int R=0;
	for(int i=0;i<k;i++) {  
		R=(R*2)+this->step();
	}
	return R;
}
//overloaded output operator 
std::ostream& operator<< (std::ostream& out, LFSR& lfsr) {  
	out<<lfsr._seed<<" ";
	return out;
}

sf::Image transform(LFSR& _lfsr,sf::Image& _image) {
	sf::Image image=_image;
	sf::Vector2u size=image.getSize();

	sf::Color p;	
	for(int x=0;x<size.x;x++) {
		for(int y=0;y<size.y;y++) {
			p=image.getPixel(x,y);
			p.r=p.r xor _lfsr.generate(8);
			p.g=p.g xor _lfsr.generate(8);
			p.b=p.b xor _lfsr.generate(8);
			image.setPixel(x,y,p);
		}
	}
	return image;
}


LFSR::~LFSR() {  }
