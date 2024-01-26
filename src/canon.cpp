#include "canon.hpp"
#include <vector>
#include "iostream"
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
        float deltaTime = canonBall->time.getElapsedTime().asSeconds();
        float t = deltaTime; 
        float x = canonBall->velocity.x * t ; 
        float y = canonBall->velocity.y * t - 0.5 * 9.8 * t * t ; 

        canonBall->setPosition(min(canonBall->initPosition.x + x,canonBall->finalPosition.x) ,min(canonBall->initPosition.y - y,canonBall->initPosition.y)); 

    }
  }
}

CanonBall::CanonBall() : sf::CircleShape() {
  CanonBalls.emplace_back(this);
}

CanonBall::CanonBall(float radius, std::size_t pointCount) : sf::CircleShape(radius, pointCount) {
  CanonBalls.emplace_back(this);
}

void CanonBall::fire(float angle = 25.f,float velocity = 100.f) {
  sf::Vector2f currentPos = this->getPosition();
  std::vector <sf::Vector2f> data = projectile::calcProjectileCord(abs(angle), velocity);
  sf::Vector2f finalPos = data[0]; 
  cout << finalPos.x << "    " << finalPos.y << endl; 
  finalPos.x += this->initPosition.x ;
  finalPos.y = currentPos.y - finalPos.y;
  cout << finalPos.x << "    " << finalPos.y << endl; 

  this->velocity = data[1];
  this->finalPosition = finalPos;

  this->time.restart();
  this->isMoving = true;
  this->isFired = true;
  return;
}
