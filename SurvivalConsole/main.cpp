#include <iostream>
#include "Menu.h"
#include <SFML\Graphics.hpp>
#include <string>
#include <map>
#include <memory>

class Engine {
private:
	sf::RenderWindow &okno;
public:
	void input() {
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
				okno.close();
		}
	};

	Engine(sf::RenderWindow &okno) :okno(okno) {}
	~Engine() {}

};

class Tekst {
private:
	sf::Text text;
	sf::Font font;
	const std::string& czcionka;
	const std::string& data;
	sf::Vector2f poz;
public:
	Tekst(const std::string& data, const std::string& czcionka, sf::Vector2f poz) : data(data), czcionka(czcionka), poz(poz) {
		std::cout << "Tworze obiekt klasy Tekst...\n";
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
		std::cout << "Usuwam obiekt klasy Tekst...\n";
	};
};

int main() {
	sf::ContextSettings ustawienia;
	ustawienia.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Console Survive", sf::Style::Default, ustawienia);
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);

	sf::Vector2f pos = sf::Vector2f(50, 100);
	std::string tekst1 = "Obudzilem sie w jakiejs ciemnej piwnicy, z przodu widze korytarz\nCo robic?";
	sf::Vector2f pos2 = sf::Vector2f(50, 200);
	std::string tekst2 = "Chyba pojde do przodu, moze cos znajde...";

	
	std::map<std::string, std::unique_ptr<Tekst>> teksty;
	teksty.insert(std::make_pair("t1", std::unique_ptr<Tekst>(new Tekst(tekst1, "FBI.ttf", pos))));
	teksty.insert(std::make_pair("t2", std::unique_ptr<Tekst>(new Tekst(tekst2, "FBI.ttf", pos2))));
	Engine engine(window);

	while (window.isOpen())
	{
		engine.input();
		window.clear();
		teksty["t1"]->draw(window);
		teksty["t2"]->draw(window);
		window.display();
	}

	std::cout << "EXIT...\n";
	return 0;
};
