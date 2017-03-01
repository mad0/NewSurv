#include <iostream>
#include "Menu.h"
#include <SFML\Graphics.hpp>
#include <string>

class Tekst {
private:
	sf::Text text;
	sf::Font font;
	const std::string& czcionka;
	const std::string& data;
	sf::Vector2f poz;
public:
	Tekst(const std::string& data, const std::string& czcionka, sf::Vector2f poz) : data(data), czcionka(czcionka), poz(poz) {
		font.loadFromFile(czcionka);
		text.setFont(font);
		text.setString(data);
		text.setPosition(poz);
		text.setFillColor(sf::Color(195, 195, 195, 255));
		text.setCharacterSize(50);
	};

	void draw(sf::RenderWindow &okno) {
		okno.draw(text);
	};

	~Tekst() {

	};
};

int main() {
	sf::ContextSettings ustawienia;
	ustawienia.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Console Survive", sf::Style::Default, ustawienia);
	window.setFramerateLimit(30);
	sf::Vector2f pos = sf::Vector2f(50, 50);
	std::string tekst1 = "Obudzilem sie w jakiejs ciemnej piwnicy, z przodu widze korytarz\nCo robic?";
	window.setVerticalSyncEnabled(true);
	Tekst jeden(tekst1, "FBI.ttf", pos);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		window.clear();
		jeden.draw(window);
		window.display();
	}


	return 0;
};
