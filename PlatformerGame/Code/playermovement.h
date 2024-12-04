#include <SFML/Graphics.hpp>

double Playermovment(sf::RectangleShape* player, double player_speed, double deltaTime, bool& player_onground, double* player_velocity, double* player_jumpSpeed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // ���� ��������� ������ � ��
    {
        player->move(-player_speed * deltaTime, 0); // ��� ������ ����
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // ���� ��������� D ��
    {
        player->move(player_speed * deltaTime, 0); // ��� ������ ������
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player_onground) // ���� ��������� W ��
    {
        *player_velocity = *player_jumpSpeed; // ���� ����������� ������
        player_onground = false; // ���� ����� �� ������� �� �� ����
    }
    return *player_velocity;
}