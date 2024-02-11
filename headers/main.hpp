#include <SFML/Graphics.hpp>

class Label : public sf::Text { 
public:
  Label(std::string text = "Text",
        sf::Vector2f position = sf::Vector2f(0.f, 0.f))
      : sf::Text() {
    this->setString(text);
    this->setCharacterSize(24);
    this->setFillColor(sf::Color::White);
    this->setPosition(position);
  };
};