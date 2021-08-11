#include <iostream>
#include <Windows.h>

#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

#define GLACIAL 0
#define SURGELE 1
#define CRU 2
#define SAIGNANT 3
#define A_POINT 4
#define BIEN_CUIT 5
#define GRILLE 6
#define CARBONISE 7
#define EXPLOSIF 8

bool isTitle(Event& e)
{
    if (e.type == Event::KeyReleased)
        if (e.key.code == Keyboard::Enter)
            return false;
    
    return true;
}

int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(960, 540), "My GameJam Project", Style::Close);
    window.setFramerateLimit(60);

    Texture tTitle;
    tTitle.loadFromFile("../assets/title_screen.png");
    Sprite sTitle(tTitle);

    Texture t1, t2, t3;
    t1.loadFromFile("../assets/cooking_bar.png");
    t2.loadFromFile("../assets/player.png");
    t3.loadFromFile("../assets/request_cursor.png");

    Sprite sPlayer(t2);
    Sprite sCookingBar(t1);
    Sprite sRequest(t3);

    sCookingBar.setPosition(Vector2f(255.f, 255.f));
    sPlayer.setOrigin(Vector2f(20.f, 10.f));
    sPlayer.setPosition(Vector2f(255.f, 250.f));

    int cooking_time = rand() % 9;
    int score = 0;

    bool isSpacePressed = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
                
            if (event.type == Event::KeyReleased)
                if (event.key.code == Keyboard::Space)
                    isSpacePressed = true;
        }

        if (isTitle(event))
        {
            window.clear(Color::White);
            window.draw(sTitle);
            window.display();
        }
        
        else
        {
            switch (cooking_time)
            {
            case 0:
                sRequest.setPosition(Vector2f(260, 255-20));
                window.draw(sRequest);
                break;
            case 1:
                sRequest.setPosition(Vector2f(310, 255-20));
                window.draw(sRequest);
                break;
            case 2:
                sRequest.setPosition(Vector2f(360, 255-20));
                window.draw(sRequest);
                break;
            case 3:
                sRequest.setPosition(Vector2f(410, 255-20));
                window.draw(sRequest);
                break;
            case 4:
                sRequest.setPosition(Vector2f(460, 255-20));
                window.draw(sRequest);
                break;
            case 5:
                sRequest.setPosition(Vector2f(510, 255-20));
                window.draw(sRequest);
                break;
            case 6:
                sRequest.setPosition(Vector2f(560, 255-20));
                window.draw(sRequest);
                break;
            case 7:
                sRequest.setPosition(Vector2f(610, 255-20));
                window.draw(sRequest);
                break;
            case 8:
                sRequest.setPosition(Vector2f(660, 255-20));
                window.draw(sRequest);
                break;
            }

            if (isSpacePressed || sPlayer.getPosition().x >= 700)
            {
                switch (cooking_time)
                {
                case 0:
                    if (sPlayer.getPosition().x >= 255 && sPlayer.getPosition().x < 305) { score++; }
                    else window.close();
                    break;
                case 1:
                    if (sPlayer.getPosition().x >= 305 && sPlayer.getPosition().x < 355) { score++; }
                    else window.close();
                    break;
                case 2:
                    if (sPlayer.getPosition().x >= 355 && sPlayer.getPosition().x < 405) { score++; }
                    else window.close();
                    break;
                case 3:
                    if (sPlayer.getPosition().x >= 405 && sPlayer.getPosition().x < 455) { score++; }
                    else window.close();
                    break;
                case 4:
                    if (sPlayer.getPosition().x >= 455 && sPlayer.getPosition().x < 505) { score++; }
                    else window.close();
                    break;
                case 5:
                    if (sPlayer.getPosition().x >= 505 && sPlayer.getPosition().x < 555) { score++; }
                    else window.close();
                    break;
                case 6:
                    if (sPlayer.getPosition().x >= 555 && sPlayer.getPosition().x < 605) { score++; }
                    else window.close();
                    break;
                case 7:
                    if (sPlayer.getPosition().x >= 605 && sPlayer.getPosition().x < 655) sPlayer.setPosition(Vector2f(255.f, 250.f));
                    else window.close();
                    break;
                case 8:
                    if (sPlayer.getPosition().x >= 655 && sPlayer.getPosition().x < 705) sPlayer.setPosition(Vector2f(255.f, 250.f));
                    else window.close();
                    break;
                }
                
                sPlayer.setPosition(Vector2f(255.f, 250.f));
                cooking_time = rand() % 9;
                isSpacePressed = false;
            }

            else
            {
                sPlayer.move(3, 0);
            }

            window.clear(Color::White);
            window.draw(sCookingBar);
            window.draw(sPlayer);
            window.draw(sRequest);
            window.display();
        }
    }

    std::cout << "Perdu !\nVous avez passé " << score << " commandes.\n" << std::endl;
    system("pause");

    return EXIT_SUCCESS;
}
