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
    int level = 1; // �����
    double player_speed = 700; // �������� ������
    double player_velocity = 0; // ����������� ������
    double gravity = 0.01f; // ���������
    double player_jumpSpeed = -2; // �������� �������
    bool player_onground = false; // �� ����������� ������� �� ����

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Planformer", sf::Style::Fullscreen); // ����������� ����

    sf::Clock clock; // ����������� ����

    sf::RectangleShape player(sf::Vector2f(50, 50)); // ����������� ������
    player.setFillColor(sf::Color::Green);
    player.setPosition(desktop.width * 0.96f, desktop.height * 0.91f);

    sf::Font font; // ���� ������
    if (!font.loadFromFile("Fonts/ArialMT.ttf"))
    {
        return -1;
    }

    sf::Text text("Level: 1 ", font, 30); // ����������� ������
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(desktop.width * 0.5f, 0);

    std::vector<sf::RectangleShape> platforms = getplatforms(desktop.width, desktop.height);
    std::vector<sf::RectangleShape> platformsLevel1 = getplatformsLevel1(desktop.width, desktop.height);
                                    
    while (window.isOpen()) // �������� ���� ��������
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // ���� ���� ������� �� �������
            {
                window.close();
            }

            else if (event.type == sf::Event::KeyPressed) // ���� ���� ���������� ������ ��
            {
                if (event.key.code == sf::Keyboard::Escape) // ���� ��������� escape �� ������� ��������
                {
                    window.close();
                }
            }
        }

        checkLevelComplete(player, desktop.width, desktop.height, level);

        double deltaTime = clock.restart().asSeconds();
        deltaTime = std::min(deltaTime, 0.05);

        player_velocity = Playermovment(&player, player_speed, deltaTime, player_onground, &player_velocity, &player_jumpSpeed);

        player_velocity += gravity; // �������� ��������� ���� ��������
        player.setPosition(player.getPosition().x, player.getPosition().y + player_velocity); // ��������� ������� ������ ��� �����

        for (const auto& platform : platforms)
        {
            checkcolision(player, platform, player_velocity, player_onground);
        }
        if (level == 1)
        {
            for (const auto& platform : platformsLevel1) // ���� ��� ��� �������� ������� ����
            {
                checkcolision(player, platform, player_velocity, player_onground);
            }
        }
        else if (level == 2)
        {

        }

        if (player_velocity != 0) // ���� ������� ����������� � ����� ��
        {
            player_onground = false; // ������� ������ �� "� �����"
        }

        std::cout << "Player Position: (" << player.getPosition().x << ", " << player.getPosition().y << ")" << std::endl;
        std::cout << "Player Velocity: " << player_velocity << std::endl;
        std::cout << "Player On Ground: " << (player_onground ? "Yes" : "No") << std::endl;

        text.setString("Level: " + std::to_string(level)); // ��������� ������� ����

        window.clear(sf::Color::Blue); // ���������� ���� � ����
        window.draw(player); // ����������� ������
        window.draw(text); // ����������� ������
        for (const auto& platform : platforms) // ���� ��� �������� ��� ��������
        {
            window.draw(platform); // ����������� ��������
        }
        if (level == 1)
        {
            for (const auto& platform : platformsLevel1)
            {
                window.draw(platform);
            }
        }
        window.display(); // ��������� ��������
    }
    return 0;
}