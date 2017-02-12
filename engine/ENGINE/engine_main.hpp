#pragma once

#include <SFML\Graphics.hpp>

namespace engine
{
	extern std::string build;

	void draw_text(sf::RenderWindow &window, sf::Text &text, const std::string string, const sf::Vector2f &pos, const sf::Vector2f &scale);

	void draw_text(sf::RenderWindow &window, sf::Text &text, const std::string string, const sf::Vector2f &pos);

	std::string getTime();

	std::string getObjectCoords(sf::Sprite &object);
}

#include "logger.hpp"
