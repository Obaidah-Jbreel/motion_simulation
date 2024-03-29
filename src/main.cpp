#include "canon.hpp"
#include "physics.hpp"
#include "main.hpp" 
#include "stdlib.h"

#include <array>
#include <iostream>
#include "cmath"

// Window dimensions
float windowS[2] = {1920.0f, 1080.0f};

// Dimension is x cord, y cord, width (relative to image real width), height
// (relative to image real height) . width and height is relative to origin dim
// of the image .
float canonD[4] = {50.f, windowS[1], .5f, .5f}; //.5 * 512 = 256 pixels
// Canon ball Constants .
const sf::Vector2f ballInitPosition = sf::Vector2f(225.f, windowS[1] - 275.f);
const int MAX_CANON_BALLS = 5;
CanonBall canonBalls[MAX_CANON_BALLS];

// Delay between fire balls
const sf::Time FIRE_DELAY = sf::seconds(1.f);

int main(int argc, char *input[]) {
  float initVelocity = 100.f;
  float angle = -25.f;
  std::cout << argc << endl;
  switch (argc) {
    case 2 : 
        initVelocity = atof(input[1]) * 10 ;
        break;
    case 3 : 
        angle = -atof(input[2]);
        break;
    
  }
  // Main textures and fonts 
  sf::Texture head, base, ballTexture, backgroundT;
  sf::Font lemonFont;
  // Target Line . 
  sf::VertexArray targetLine(sf::LinesStrip);
  // caluclate canon cords based on its dimensions;  
  canonD[0] = 512 * canonD[2];
  canonD[1] = windowS[1] - (canonD[3] * 512);

  sf::RenderWindow window(sf::VideoMode(windowS[0], windowS[1]),"Motion Simulator");
  window.setFramerateLimit(144);
  sf::Clock currentClock;


  // Check if textures loaded .
  if (!head.loadFromFile("./head.png")) {
    return 1;
  } else {
    head.setSmooth(true);
  }
  if (!base.loadFromFile("./base.png")) {
    return 1;
  } else {
    base.setSmooth(true);
  }
  if (!lemonFont.loadFromFile("./Lemon-Regular.ttf"))
    return 1; //*/
  if (!ballTexture.loadFromFile("./ballTexture.jpg"))
    return 1; //*/
  if (!backgroundT.loadFromFile("./background.png"))
    return 1; //*/
  // Init the ammo for the canon ball . 
  for (int i = 0; i < MAX_CANON_BALLS; i++) {
    canonBalls[i] = CanonBall(20.f, 1024 * 10);
    canonBalls[i].setPosition(ballInitPosition);
    canonBalls[i].setTexture(&ballTexture);
    canonBalls[i].initPosition = ballInitPosition;
  }
  // Declaring spirtes variables .
  sf::Sprite headS(head);
  sf::Sprite baseS(base);
  sf::Sprite backgroundS(backgroundT);
  // init information labels 
  std::vector <sf::Vector2f> initData = projectile::calcProjectileProperties(std::abs(angle), initVelocity);
  Label anglel("Angle :" + std::to_string((int)-angle), sf::Vector2f(0.f, 0.f));
  anglel.setFont(lemonFont);
  Label initVelocityl("Init Velocity : " + std::to_string( static_cast<int>(initVelocity)/ 10 )  + "m/s", sf::Vector2f(150.f, 0.f));
  initVelocityl.setFont(lemonFont);
  Label rangel("Range : "+ std::to_string(static_cast<int>(initData[0].x) /10) + "m", sf::Vector2f(500.f, 0));
  rangel.setFont(lemonFont);
  Label apexl("Apex : " + std::to_string(static_cast<int>(initData[0].y) /10) + "m" , sf::Vector2f(720.f, 0.f));
  apexl.setFont(lemonFont);
  // RENDER LOOP (main loop) .
  while (window.isOpen()) {
    for (sf::Event event = sf::Event{}; window.pollEvent(event);) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // start rendering the game
    window.clear();
    // Change spirite dimensions .
    headS.setPosition(sf::Vector2f(canonD[0] - 5, canonD[1])); // absolute position
    baseS.setPosition(sf::Vector2f(canonD[0] - 80, canonD[1] - 40)); // absolute position
    // Change Origin to match rotation algrothim .
    sf::FloatRect bounds = headS.getLocalBounds();
    headS.setOrigin(bounds.width / 4.f, bounds.height / 2.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
      // calculate the angle between canon ball and mouse .
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      float dX = mousePos.x - ballInitPosition.x,dY = mousePos.y - ballInitPosition.y;
      angle = atan2(dY, dX) * (180.f / PI);
      angle = (-angle < 20.f) ? -20.f : angle;
      angle = (-angle > 90.f) ? -90.f : angle;
      anglel.setString("Angle : " + std::to_string((angle < 0.f) ? (int)-angle : (int) (angle + 180.f)) + "");
      // Update Information labels text .
      initData = projectile::calcProjectileProperties(std::abs(angle), initVelocity);
      rangel.setString("Range = " + std::to_string(static_cast<int>(initData[0].x) /10) + "m");
      apexl.setString("Apex = " + std::to_string(static_cast<int>(initData[0].y) /10) + "m");
    }
    // Update the head rotation .
    headS.setRotation(angle);

    // DRAWING SECTION .
    window.draw(backgroundS);


    // Create target line based on angle . 
    float timeOfFlight = initData[2].x; 
    targetLine.clear();
    while (timeOfFlight > 0)  
    {
      sf::Vector2f position = projectile::calcCurrentPosition(timeOfFlight,initData[1]);
      position.x += ballInitPosition.x + 20; 
      position.y = ballInitPosition.y - position.y + 20;
      targetLine.append(sf::Vertex(position));
      timeOfFlight = timeOfFlight - 0.1;
      // std::cout << position.x << "  ----  " << position.y << std::endl;  
    }

    window.draw(headS);
    window.draw(baseS);
    window.draw(anglel);
    window.draw(rangel);
    window.draw(apexl);
    window.draw(initVelocityl);
    window.draw(targetLine);

    CanonBall::updateBallPosition();
    // Canon ball
    for (int i = 0; i < MAX_CANON_BALLS; i++) {
      if (!canonBalls[i].isMoving && sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.hasFocus() && currentClock.getElapsedTime() >= FIRE_DELAY) 
      {
        canonBalls[i].fire(-angle, initVelocity);
        currentClock.restart();
      }
      window.draw((canonBalls[i]));
    }
    window.display();
  }
}

// sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
