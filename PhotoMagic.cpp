/*
*	Author: Patrick Kyoyetrera
*	Assignment PS2b
*	Date: Sunday October 2, 2016
*/
#include "LFSR.hpp"

int main(int argc, char* argv[]) {
	//must have 4 command line arguments to exectue propgram
	if(argc<4) {
		cout<<"Invalid number of arguments"<<endl;
		return -1;
	}
	//createLFSR object with seed and tap position from command ine arguments 
	LFSR lfsr(argv[3],atoi(argv[4]));
	
	//load image to be encrypted 
	sf::Image original;
	if(!original.loadFromFile(argv[1]))
		return -1;
	sf::Texture tex;
	tex.loadFromImage(original);
	sf::Sprite sprite1; //sprite for original image
	sprite1.setTexture(tex);
		
	//call transform function to encrypt image with lfsr
	sf::Image enc_image=transform(lfsr,original);
	sf::Texture tex2;
	tex2.loadFromImage(enc_image);
	sf::Sprite sprite2;
	sprite2.setTexture(tex2);

	//create size of window in relation to size of original image 
	sf::Vector2u sizeOrg=original.getSize();
	sf::RenderWindow window1(sf::VideoMode(sizeOrg.x, sizeOrg.y), "PS2B Original");
	//create size of window in relation to size of encrypted image 
	sf::Vector2u sizeEnc=enc_image.getSize();
	sf::RenderWindow window2(sf::VideoMode(sizeEnc.x, sizeEnc.y), "PS2B Encrypt");
	
	while(window1.isOpen() and window2.isOpen()) {
		sf::Event event;
		while(window1.pollEvent(event)) {
			if(event.type==sf::Event::Closed)
				window1.close();		
		}
		while(window2.pollEvent(event)) {
			if(event.type==sf::Event::Closed) 
				window2.close();
		}
		//display windows 1 & 2
		window1.clear(sf::Color::White);
		window1.draw(sprite1);
		window1.display();
		window2.clear(sf::Color::White);
		window2.draw(sprite2);
		window2.display();
	}
	if(!enc_image.saveToFile(argv[2]))
		return -1;
return 0;
}
