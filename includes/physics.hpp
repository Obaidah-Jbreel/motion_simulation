
#include "SFML/System/Vector2.hpp"
#include <vector>
#include "cmath"

using namespace std;
const float g = 9.8f;
class projectile {
  public :
  static std::vector<sf::Vector2f> calcProjectileCord(float angle = 25, float initVelocity = 100.f) 
  {
      float thetaRad = angle * (M_PI / 180.f);
      float initialVelocityX = initVelocity * cos(thetaRad); // 90
      float initialVelocityY = initVelocity * sin(thetaRad); // 42
    
      // Calculate the time of flight
      float timeOfFlight = (2.f * initialVelocityY) / g; // 8.5

      // Calculate the maximum height (apex)
      float apexHeight = (initialVelocityY * initialVelocityY) / (2.f * g); // 90

      // Calculate the range
      float range = initialVelocityX * timeOfFlight; // 765
      std::vector<sf::Vector2f> cords{sf::Vector2f(range, apexHeight),sf::Vector2f(initialVelocityX,initialVelocityY)};
      return cords;
  }
  float calcCurrentTime(float initialVelocityX = 0.f,float range = 0.f)
  {
    return (range/initialVelocityX);
  }
  float calcCurrentYVelocity(float initialVelocityY = 0.f, float currentTime = 0.f)
  {
    float gt = currentTime * g; 
    return (initialVelocityY - gt);
  }
};