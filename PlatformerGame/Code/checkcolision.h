#include <SFML/Graphics.hpp>

void checkcolision(sf::RectangleShape& player, sf::RectangleShape platform, double& player_velocity, bool& player_onground)
{
    if (player.getGlobalBounds().intersects(platform.getGlobalBounds())) // ���� ������� ��������� ��������� ��
    {
        // �������� ����������� ���糿
        if (player.getPosition().y + player.getSize().y - player_velocity <= platform.getPosition().y)
        {
            player.setPosition(player.getPosition().x, platform.getPosition().y - player.getSize().y);
            player_onground = true;
            player_velocity = 0;
        }
        else if (player.getPosition().y - player_velocity >= platform.getPosition().y + platform.getSize().y)
        {
            player.setPosition(player.getPosition().x, platform.getPosition().y + platform.getSize().y);
            player_velocity = 0;
        }
        // �������� ������������� ���糿
        else
        {

            if (player.getPosition().x < platform.getPosition().x)
            {
                player.setPosition(platform.getPosition().x - player.getSize().x, player.getPosition().y);
            }
            else
            {
                player.setPosition(platform.getPosition().x + platform.getSize().x, player.getPosition().y);
            }
        }
    }
}
void checkLevelComplete(sf::RectangleShape& player, int width, int height, int& level)
{
    if (player.getPosition().x + player.getSize().x > width) // ���� ������� ����� ������ ��
    {
        player.setPosition(width * 0.04f, height * 0.91f); // ���������� ������ �� �������� �������
        level++; // ��������� ����
    }
}