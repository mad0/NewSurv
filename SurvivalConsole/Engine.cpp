#include "Engine.h"

Engine::Engine() {
	ustawienia.antialiasingLevel = 8;
	window.create(sf::VideoMode(1280, 720), "Console Survive", sf::Style::Default, ustawienia);
	window.setFramerateLimit(40);
	window.setVerticalSyncEnabled(true);
	std::string tekst1 = "Obudzilem sie w jakiejs ciemnej piwnicy, z przodu widze korytarz\nCo robic?";
	std::string tekst2 = "Chyba pojde do przodu, moze cos znajde...";
	teksty.insert(std::make_pair("t1", std::unique_ptr<Text>(new Text(tekst1, "FBI.ttf", sf::Vector2f(50, 100)))));
	//teksty.insert(std::make_pair("t2", std::unique_ptr<Text>(new Text(tekst2, "FBI.ttf", pos))));
}

Engine::~Engine() {

}

void Engine::mainLoop() {
	while (window.isOpen())
	{
		inputs();
		window.clear();
		draw();
		window.display();
	}
}

void Engine::inputs() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			window.close();
		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space));
		int a = 2;
	}
}

void Engine::update() {

}

void Engine::draw() {
	teksty["t1"]->FadeOut();
	teksty["t1"]->draw(window);
	//teksty["t2"]->draw(window);
}
