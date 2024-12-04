#include <SFML/Graphics.hpp>

double Playermovment(sf::RectangleShape* player, double player_speed, double deltaTime, bool& player_onground, double* player_velocity, double* player_jumpSpeed)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // якщо натиснуто кнопку А то
    {
        player->move(-player_speed * deltaTime, 0); // рух гравця вліво
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // якщо натиснуто D то
    {
        player->move(player_speed * deltaTime, 0); // рух гравця вправо
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player_onground) // якщо натиснуто W то
    {
        *player_velocity = *player_jumpSpeed; // зміна прискорення гравця
        player_onground = false; // зміна стану на гравець не на землі
    }
    return *player_velocity;
}