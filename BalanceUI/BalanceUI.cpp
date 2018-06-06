// BalanceUI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include "../BalanceLib/Game_manager.h"
#include "../BalanceLib/PID.h"
#include <chrono>
#include <math.h>

int main()
{
	// Create the main window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	const int height = 400;
	const int width = 600;
	sf::RenderWindow window(sf::VideoMode(width, height), "Balance", sf::Style::Default, settings);

	window.setFramerateLimit(60);
	int x = -200;
	int dx = -3;
	const int y = -100;
	const float radius = 10;

	double bx = 0;
	double by = 0;

	sf::Vector2f rect_size(400, 5);
	sf::Vector2f rect_size2(5, 30);

	sf::CircleShape circle{ radius };
	sf::RectangleShape rectangle;
	rectangle.setSize(rect_size);
	sf::RectangleShape rectangle2;
	rectangle2.setSize(rect_size2);

	circle.setOrigin(sf::Vector2f(circle.getRadius(), -circle.getRadius()));
	rectangle.setOrigin(sf::Vector2f(rectangle.getSize().x/2, rectangle.getSize().y / 2));
	rectangle.setPosition((window.getSize().x/2), window.getSize().y/2);
	rectangle2.setOrigin(sf::Vector2f(rectangle2.getSize().x / 2, rectangle2.getSize().y / 2));
	rectangle2.setPosition((window.getSize().x / 2), window.getSize().y / 2-50);
	

	PID controller{ 0.644864, 0, 0.668323, 1, -1 };
	Game_manager mgr{ controller };
	mgr.push_ball(0.5);

	// Start the game loop
	while (window.isOpen())
	{ 
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the string
		
		rectangle.setRotation(mgr.rocker().get_angle()* (180/ 3.14159265358979323846));

		bx = mgr.ball().position*cos(mgr.rocker().get_angle());
		by = mgr.ball().position*sin(mgr.rocker().get_angle());

		circle.setPosition(bx*200 + window.getSize().x/2, by*200 + window.getSize().y / 2 -circle.getRadius()*3-3);
		mgr.update(std::chrono::microseconds(16667));

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Left)
			{
				mgr.push_ball(-0.5);
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				mgr.push_ball(+0.5);
			}
		}
		event.type = sf::Event::MouseWheelMoved;//weil der alte Eventtype gespeichert wird

		window.draw(circle);
		window.draw(rectangle);
		window.draw(rectangle2);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}

