#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window{sf::VideoMode{640, 480}, "CMake/vcpkg/SFML Demo"};

  sf::CircleShape shape{50.f};
  shape.setFillColor(sf::Color::Cyan);
  shape.setPosition(100.f, 100.f);

  while (window.isOpen()) {
    sf::Event event{};

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Escape)) {
        window.close();
      }
    }

    window.clear(sf::Color::Black);

    window.draw(shape);

    window.display();
  }

  return EXIT_SUCCESS;
}
