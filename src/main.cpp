/* 
    this is the main source code 
    what's included for the c++ course : 
      oop 
      arrays
      loops and nested loops 
      cmath 
      pointers 
      vectors

*/
#include "canon.hpp"
#include "physics.hpp"

#include "cmath"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// I made this class to optimize the code , since it was repeated .
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

// Window dimensions
float windowS[2] = {1920.0f, 1080.0f};

// Dimension is x cord, y cord, width (relative to image real width), height
// (relative to image real height) . width and height is relative to origin dim
// of the image .
float canonD[4] = {50.f, windowS[1], .5f, .5f}; //.5 * 512 = 256 pixels
// Canon ball Constants .
const sf::Vector2f ballInitPosition = sf::Vector2f(225.f, windowS[1] - 280.f);
const int MAX_CANON_BALLS = 5;
CanonBall canonBalls[MAX_CANON_BALLS];

// Delay between fire balls
const sf::Time FIRE_DELAY = sf::seconds(1.f);

int main(int argc, char *argv[]) {

  float initVelocity = 130.f;
  // Main textures and fonts 
  sf::Texture head, base, ballTexture, backgroundT;
  sf::Font lemonFont;
  // Reposition the canon to make it relative
  canonD[0] = 512 * canonD[2];
  canonD[1] = windowS[1] - (canonD[3] * 512);

  sf::RenderWindow window(sf::VideoMode(windowS[0], windowS[1]),"Motion Simulator");
  window.setFramerateLimit(60);
  sf::Clock currentClock;

  float angle = -25.f;

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
    canonBalls[i] = CanonBall(25.f, 1024 * 10);
    canonBalls[i].setPosition(ballInitPosition);
    canonBalls[i].setTexture(&ballTexture);
    canonBalls[i].initPosition = ballInitPosition;
  }
  // Declaring spirtes variables .
  sf::Sprite headS(head);
  sf::Sprite baseS(base);
  sf::Sprite backgroundS(backgroundT);
  // init information labels 
  Label anglel("Angle :" + std::to_string((int)-angle), sf::Vector2f(0.f, 0.f));
  anglel.setFont(lemonFont);
  Label initVelocityl("Init Velocity : " + std::to_string((int)initVelocity / 10) + "m/s", sf::Vector2f(150.f, 0.f));
  initVelocityl.setFont(lemonFont);
  Label rangel("Range : 765m", sf::Vector2f(450.f, 0));
  rangel.setFont(lemonFont);
  Label apexl("Apex : 90m ", sf::Vector2f(720.f, 0.f));
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
      angle = atan2(dY, dX) * (180.f / M_PI);
      angle = (-angle < 0.f) ? 0.f : angle;
      angle = (-angle > 90.f) ? -90.f : angle;
      anglel.setString("Angle : " +std::to_string((angle < 0.f) ? (int)-angle : (int)(angle + 180.f)) + "");
      std::vector <sf::Vector2f> data = projectile::calcProjectileCord(std::abs(angle), initVelocity);
      rangel.setString("Range = " + std::to_string((int)data[0].x) + "m");
      apexl.setString("Apex = " + std::to_string((int)data[0].y) + "m");
    }
    // Update the head rotation .
    headS.setRotation(angle);

    // DRAWING SECTION .
    window.draw(backgroundS);

    // Canon ball
    for (int i = 0; i < MAX_CANON_BALLS; i++) {
      if (!canonBalls[i].isMoving && sf::Mouse::isButtonPressed(sf::Mouse::Left) && currentClock.getElapsedTime() >= FIRE_DELAY) 
      {
        canonBalls[i].fire(-angle, initVelocity);
        currentClock.restart();
      } else if (currentClock.getElapsedTime() < FIRE_DELAY) {
        //        std::cout << "[Delay-System] : Wait 1 sec .."
        //                 << currentClock.getElapsedTime().asSeconds() <<
        //                 std::endl;
      }
      window.draw((canonBalls[i]));
    }

    window.draw(headS);
    window.draw(baseS);
    window.draw(anglel);
    window.draw(rangel);
    window.draw(apexl);
    window.draw(initVelocityl);

    CanonBall::updateBallPosition();

    window.display();
  }
}

// sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
