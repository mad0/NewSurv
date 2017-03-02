#pragma once
#include <SFML\Graphics.hpp>
#include <map>
#include <memory>
#include "Text.h"

class Engine {
private:
	sf::ContextSettings ustawienia;
	sf::RenderWindow window;
	std::map<std::string, std::unique_ptr<Text>> teksty;
public:
	void mainLoop();
	void inputs();
	void update();
	void draw();
	Engine();
	~Engine();
};
