#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "a simple game");
    window.setFramerateLimit(60);

    sf::RectangleShape player({40, 40});
    player.setFillColor(sf::Color::Green);
    player.setPosition({380, 280});
    int coins = 0;

    sf::RectangleShape coin({20, 20});
    coin.setFillColor(sf::Color::Yellow);
    coin.setPosition({20, 20});
    bool isCoin = true;

    sf::Font font("Stick-Regular.ttf");

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player.getPosition().y > 0) {
            player.move({0, -5});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && player.getPosition().y < 600 - 40) {
            player.move({0, 5});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && player.getPosition().x > 0) {
            player.move({-5, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && player.getPosition().x < 800 - 40) {
            player.move({5, 0});
        }

        if (player.getGlobalBounds().findIntersection(coin.getGlobalBounds())) {
            isCoin = false;
            coin.setPosition({-100, -100});
            coins++;
        }

        sf::Text coinText(font, "coins:" + std::to_string(coins));
        coinText.setFillColor(sf::Color::Red);
        
        window.clear(sf::Color::Blue);
        if (isCoin) {
            window.draw(coin);
        }
        window.draw(player);
        window.draw(coinText);
        window.display();
    }
}
