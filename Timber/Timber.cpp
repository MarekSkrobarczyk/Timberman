// Timber.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

int main()
{

    // create video mode object

    sf::VideoMode vm(1920, 1080);
    
    // Create and open window for game
    sf::RenderWindow window(vm,"Timber1", sf::Style::Fullscreen);

    // Create a texture to hold a graphic on the GPU

    Texture textureBackground;

    textureBackground.loadFromFile("graphics/background.png");

    // create a sprite 

    Sprite spriteBackground;

    // Attach the texture to the sprite

    spriteBackground.setTexture(textureBackground);
   
    // Set the spriteBackground to cover the screen

    spriteBackground.setPosition(0, 0);

    // make a tree sprite

    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    // prepare the bee

    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    // is he bee currently moving ? 

    bool beActive = false;

    // bee currently speed
    float beeSpeed = 0.0f;

    // make 3 cloud sprites from 1 texture

    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");

    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    //positon the clouds

    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    // are cloud active 

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    // cloud speed

    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    // variable to control time

    Clock clock;

    // pause state

    bool paused = true;

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            paused = false;
        }
       
        // Clear everything from the last run frame
        window.clear();

        if (!paused)

        {
            // Measure time
            Time dt = clock.restart();

            // Here we start the game 



            //setup the bee

            if (!beActive)
            {
                // How fast is the bee
                srand((int)time(0));
                beeSpeed = (rand() % 200) + 200;

                //How high is the bee
                srand((int)time(0) * 10);
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(2000, height);
                beActive = true;
            }

            else
            {
                // move the bee

                spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);

                if (spriteBee.getPosition().x < -100)
                {
                    beActive = false;
                }
            }


            //menaga the clouds
            //cloud1
            if (!cloud1Active)
            {
                //how fast is the cloud
                srand((int)time(0) * 10);
                cloud1Speed = (rand() % 200);

                // how high is the cloud
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                spriteCloud1.setPosition(-200, height);
                cloud1Active = true;

            }

            else
            {
                spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);

                if (spriteCloud1.getPosition().x > 1920)
                {
                    cloud1Active = false;
                }
            }

            //cloud2

            if (!cloud2Active)
            {
                //how fast is the cloud
                srand((int)time(0) * 20);
                cloud2Speed = (rand() % 200);

                // how high is the cloud
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                spriteCloud2.setPosition(-200, height);
                cloud2Active = true;

            }

            else
            {
                spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);

                if (spriteCloud2.getPosition().x > 1920)
                {
                    cloud2Active = false;
                }
            }


            //cloud3

            if (!cloud3Active)
            {
                //how fast is the cloud
                srand((int)time(0) * 30);
                cloud3Speed = (rand() % 200);

                // how high is the cloud
                srand((int)time(0) * 30);
                float height = (rand() % 450) - 150;
                spriteCloud3.setPosition(-200, height);
                cloud3Active = true;

            }

            else
            {
                spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);

                if (spriteCloud3.getPosition().x > 1920)
                {
                    cloud3Active = false;
                }
            }
        }

        // Draw our game scene here
        window.draw(spriteBackground);

        // draw the clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);


        // draw the trees

        window.draw(spriteTree);

        //draw the insects

        window.draw(spriteBee);

        // Show everything we just drew
        window.display();
    }
    
   
    return 0;
}


