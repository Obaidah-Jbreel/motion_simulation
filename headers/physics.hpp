#include "SFML/System/Vector2.hpp"
#include <vector>
#include "cmath"

#define PI 3.14159265359

using namespace std;
const float g = 9.8f;
class projectile {
  public :
  static std::vector<sf::Vector2f>  calcProjectileProperties(float angle = 25, float initVelocity = 100.f) 
  {
      float thetaRad = angle * (PI / 180.f); // 25 
      float initialVelocityX = initVelocity * cos(thetaRad); // 90
      float initialVelocityY = initVelocity * sin(thetaRad); // 42
    
      // Calculate the time of flight
      float timeOfFlight = (2.f * initialVelocityY) / g; // 8.5

      // Calculate the maximum height (apex) (h = Vyi^2 / 2g)
      float apexHeight = (initialVelocityY * initialVelocityY) / (2.f * g); // 90

      // Calculate the range (x = Vxi * T)
      float range = initialVelocityX * timeOfFlight; // 765

      std::vector<sf::Vector2f> cords{
        sf::Vector2f(range, apexHeight),
        sf::Vector2f(initialVelocityX,initialVelocityY),
        sf::Vector2f(timeOfFlight,0)
      };
      return cords;
  }
  static sf::Vector2f calcCurrentPosition(float currentTime = 0.f,sf::Vector2f velocity = sf::Vector2f(0.f,0.f))
  {

        float x = velocity.x * currentTime ; 
        float y = velocity.y * currentTime - 0.5 * g * currentTime * currentTime ;

        return sf::Vector2f(x,y);
  }
};
