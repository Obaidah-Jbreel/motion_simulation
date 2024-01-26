// canon.hpp
#ifndef CANON_HPP
#define CANON_HPP

#include "SFML/System/Clock.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

class CanonBall : public sf::CircleShape {
public:

  sf::Vector2f apex;
  sf::Vector2f velocity;
  sf::Vector2f initPosition; 
  sf::Vector2f finalPosition;

  sf::Clock time;

  bool isMoving = false; 
  bool isFired = false; 

  void fire(float angle, float velocity);

  CanonBall();
  CanonBall(float radius, u_long pointCount = 30.f);

  static void updateBallPosition();
};

#endif // CANON_HPP
