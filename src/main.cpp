#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "2DGameEngine");
    int fpsLimit = 60;
    window.setFramerateLimit(fpsLimit);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        // TODO: draw your stuff here
        window.display();
    }

    return 0;
}
