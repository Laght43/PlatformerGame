#include <SFML/Graphics.hpp>
#include <algorithm>
#include <string>
#include <vector>
#include "checkcolision.h"
#include "platforms.h"
#include "playermovement.h"
#include <iostream>


int main()
{
    int level = 1; // р≥вень
    double player_speed = 700; // швидк≥сть гравц€
    double player_velocity = 0; // прискоренн€ гравц€
    double gravity = 0.01f; // грав≥тац≥€
    double player_jumpSpeed = -2; // швидк≥сть стрибку
    bool player_onground = false; // чи знаходитьс€ гравець на земл≥

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Planformer", sf::Style::Fullscreen); // ≥н≥ц≥ал≥зац≥€ в≥кна

    sf::Clock clock; // ≥н≥ц≥ал≥зац≥€ часу

    sf::RectangleShape player(sf::Vector2f(50, 50)); // ≥н≥ц≥ал≥зац≥€ гравц€
    player.setFillColor(sf::Color::Green);
    player.setPosition(desktop.width * 0.96f, desktop.height * 0.91f);

    sf::Font font; // виб≥р шрифту
    if (!font.loadFromFile("Fonts/ArialMT.ttf"))
    {
        return -1;
    }

    sf::Text text("Level: 1 ", font, 30); // ≥н≥ц≥ал≥зац≥€ напису
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(desktop.width * 0.5f, 0);

    std::vector<sf::RectangleShape> platforms = getplatforms(desktop.width, desktop.height);
    std::vector<sf::RectangleShape> platformsLevel1 = getplatformsLevel1(desktop.width, desktop.height);
                                    
    while (window.isOpen()) // основний цикл програми
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // €кщо под≥€ закрити то закрити
            {
                window.close();
            }

            else if (event.type == sf::Event::KeyPressed) // €кщо под≥€ настиснути кнопку то
            {
                if (event.key.code == sf::Keyboard::Escape) // €кщо натиснуто escape то закрити програму
                {
                    window.close();
                }
            }
        }

        checkLevelComplete(player, desktop.width, desktop.height, level);

        double deltaTime = clock.restart().asSeconds();
        deltaTime = std::min(deltaTime, 0.05);

        player_velocity = Playermovment(&player, player_speed, deltaTime, player_onground, &player_velocity, &player_jumpSpeed);

        player_velocity += gravity; // пост≥йнпе додаванн€ сили т€гот≥нн€
        player.setPosition(player.getPosition().x, player.getPosition().y + player_velocity); // оновленн€ позиц≥€ гравц€ при пад≥нн≥

        for (const auto& platform : platforms)
        {
            checkcolision(player, platform, player_velocity, player_onground);
        }
        if (level == 1)
        {
            for (const auto& platform : platformsLevel1) // цикл дл€ вс≥х платформ першого р≥вн€
            {
                checkcolision(player, platform, player_velocity, player_onground);
            }
        }
        else if (level == 2)
        {

        }

        if (player_velocity != 0) // €кщо гравець знаходитьс€ в пов≥тр≥ то
        {
            player_onground = false; // оновити статус на "в пов≥тр≥"
        }

        std::cout << "Player Position: (" << player.getPosition().x << ", " << player.getPosition().y << ")" << std::endl;
        std::cout << "Player Velocity: " << player_velocity << std::endl;
        std::cout << "Player On Ground: " << (player_onground ? "Yes" : "No") << std::endl;

        text.setString("Level: " + std::to_string(level)); // виведенн€ к≥лькост≥ очок

        window.clear(sf::Color::Blue); // фарбуванн€ в≥кна в син≥й
        window.draw(player); // в≥дображенн€ гравц€
        window.draw(text); // в≥дображенн€ тексту
        for (const auto& platform : platforms) // цикл дл€ перебору вс≥х платформ
        {
            window.draw(platform); // в≥дображенн€ платформ
        }
        if (level == 1)
        {
            for (const auto& platform : platformsLevel1)
            {
                window.draw(platform);
            }
        }
        window.display(); // виведенн€ програми
    }
    return 0;
}