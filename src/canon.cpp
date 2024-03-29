#include "canon.hpp"
#include "vector"
#include "physics.hpp"
#include <cmath>

std::vector<CanonBall *> CanonBalls;
sf::Clock UPDATE_DELAY_CLOCK;
sf::Time DELAY_TIME = sf::milliseconds(10.f);


void CanonBall::updateBallPosition() {
  if (UPDATE_DELAY_CLOCK.getElapsedTime() < DELAY_TIME)
    return;
  for (CanonBall *canonBall : CanonBalls) {
    if (canonBall->isFired && canonBall->isMoving) {
        float deltaTime = canonBall->deltaTime.getElapsedTime().asSeconds();
        float t = deltaTime;
        sf::Vector2f currentPosition = projectile::calcCurrentPosition(t,canonBall->velocity);

        canonBall->setPosition(min(canonBall->initPosition.x + currentPosition.x,canonBall->finalPosition.x) ,min(canonBall->initPosition.y - currentPosition.y,canonBall->initPosition.y)); 

    }
  }
}
CanonBall::CanonBall() : sf::CircleShape()
{
  CanonBalls.emplace_back(this);
}

CanonBall::CanonBall(float radius, float pointCount) : sf::CircleShape(radius, pointCount) {
  CanonBalls.emplace_back(this);
}

void CanonBall::fire(float angle = 25.f,float velocity = 100.f) {

  sf::Vector2f currentPos = this->getPosition();
  std::vector <sf::Vector2f> data = projectile::calcProjectileProperties(abs(angle), velocity);
  sf::Vector2f finalPos = data[0]; 

  finalPos.x += this->initPosition.x ;
  finalPos.y = currentPos.y - finalPos.y;

  this->velocity = data[1];
  this->finalPosition = finalPos;

  this->deltaTime.restart();
  this->isMoving = true;
  this->isFired = true;
  return;
}
