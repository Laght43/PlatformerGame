#include <SFML/Graphics.hpp>
#include <vector>

std::vector<sf::RectangleShape> getplatforms(int width, int height)
{
	std::vector<sf::RectangleShape> platforms;

    sf::RectangleShape platform1(sf::Vector2f(static_cast<float>(width), static_cast<float>(height) * 0.04f)); // ініціалізація платформи 1
    platform1.setFillColor(sf::Color::Black);
    platform1.setPosition(0, height * 0.96f);
    platforms.push_back(platform1);

    sf::RectangleShape platform2(sf::Vector2f(static_cast<float>(width) * 0.04f, static_cast<float>(height))); // ініціалізація платформи 2
    platform2.setFillColor(sf::Color::Black);
    platform2.setPosition(0, 0);
    platforms.push_back(platform2);

    sf::RectangleShape platform3(sf::Vector2f(width * 0.04f, height * 0.41f)); // ініціалізація платформи 3
    platform3.setFillColor(sf::Color::Black);
    platform3.setPosition(width * 0.96f, 0);
    platforms.push_back(platform3);

    sf::RectangleShape platform4(sf::Vector2f(width * 0.04f, height * 0.41f)); // ініціалізація платформи 4
    platform4.setFillColor(sf::Color::Black);
    platform4.setPosition(width * 0.96f, height * 0.59f);
    platforms.push_back(platform4);

    return platforms;
}

std::vector<sf::RectangleShape> getplatformsLevel1(int width, int height)
{
    std::vector<sf::RectangleShape> platformsLevel1;

    sf::RectangleShape platform1Level1(sf::Vector2f(width * 0.08f, height * 0.04f)); // ініціалізація платформи 1 рівня 1
    platform1Level1.setFillColor(sf::Color::Black);
    platform1Level1.setPosition(width * 0.08f, height * 0.8f);
    platformsLevel1.push_back(platform1Level1);

    sf::RectangleShape platform2Level1(sf::Vector2f(width * 0.08f, height * 0.04f)); // ініціалізація платформи 2 рівня 1
    platform2Level1.setFillColor(sf::Color::Black);
    platform2Level1.setPosition(width * 0.3f, height * 0.7f);
    platformsLevel1.push_back(platform2Level1);

    sf::RectangleShape platform3Level1(sf::Vector2f(width * 0.08f, height * 0.04f)); // ініціалізація платформи 3 рівня 1
    platform3Level1.setFillColor(sf::Color::Black);
    platform3Level1.setPosition(width * 0.5f, height * 0.6f);
    platformsLevel1.push_back(platform3Level1);

    sf::RectangleShape platform4Level1(sf::Vector2f(width * 0.08f, height * 0.04f)); // ініціалізація платформи 4 рівня 1
    platform4Level1.setFillColor(sf::Color::Black);
    platform4Level1.setPosition(width * 0.8f, height * 0.6f);
    platformsLevel1.push_back(platform4Level1);

    return platformsLevel1;
}