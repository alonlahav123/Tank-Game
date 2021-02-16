#pragma once

#include<SFML/Graphics.hpp>

class Coin {
private:
  sf::RectangleShape coin;


public:
  Coin(sf::Vector2f size) {
    coin.setSize(size);
    coin.setFillColor(sf::Color::Yellow);
  }

  void drawTo(sf::RenderWindow &window) {
    window.draw(coin);
  }

  sf::FloatRect getGlobalBounds() {
    return coin.getGlobalBounds();
  }

  //used to "delete" coins (TEMP SOLUTION)
  void setPos(sf::Vector2f newPos) {
    coin.setPosition(newPos);
  }


};
