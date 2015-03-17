#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

const int WINDOW_WIDTH=300;
const int WINDOW_HEIGHT=300;
const float RADIUS=5; //for CircleShape

sf::Vector2f POINT1(150,150); // first 2 points
sf::Vector2f POINT2(200,150);


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TEST TEST");

    //--------------renderTexture---------------
    sf::RenderTexture mainTexture; //declares the RenderTexture
    mainTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT); //MADANTORY. Creates a new canvas for the texture. Use the same dimensions you used for RenderWindow
    mainTexture.setSmooth(true);

    sf::RenderTexture altTexture;
    mainTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT);
    mainTexture.setSmooth(true);

//    sf::RenderTexture anotherTexture;
//    anotherTexture.create(WINDOW_WIDTH, WINDOW_HEIGHT);

    //-------------Just Simple Shapes---------------
//    sf::CircleShape circle(RADIUS);
//    circle.setOrigin(RADIUS/2,RADIUS/2);
//    circle.move(POINT1);

    //    sf::RectangleShape rectangle(sf::Vector2f(200,200));
    //    rectangle.setOrigin(100,100);
    //    rectangle.move(200,200);
    //    rectangle.setFillColor(sf::Color::Green);
    //-----------------------------------------------


    mainTexture.clear(sf::Color::Transparent); //clears you a fresh canvas to draw on
    altTexture .clear(sf::Color::Transparent);

    //-------------Lines----------------
    sf::VertexArray first_line(sf::LinesStrip,2);
    first_line[0].position = POINT1;
    first_line[1].position = POINT2;

    mainTexture.draw(first_line); //draws a line into original texture


    //------------------------------------------
    sf::Sprite sprite        (mainTexture.getTexture()); //sprites needed to be able to draw the texture
    sf::Sprite rotatingSprite(mainTexture.getTexture());
    sf::Sprite testSprite    (altTexture. getTexture());

    sprite.setOrigin(POINT1); // sets new origin, BUT will move everything to where (0,0) was previous.
                              // Need to compensate for movement.
    sprite.move(POINT1);      // compensates for moving origin

    rotatingSprite.setOrigin(POINT1);
    rotatingSprite.move(POINT1.x + 50, POINT1.y);
    rotatingSprite.rotate(-90);

    testSprite.setOrigin(POINT1);
    testSprite.move(POINT1);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
            {
//                mainTexture.clear(sf::Color::Transparent);
                altTexture.clear(sf::Color::Transparent);
                altTexture.draw(sprite);
                altTexture.draw(rotatingSprite);
                testSprite.setTexture(altTexture.getTexture());
//                rotatingSprite.setTexture(mainTexture.getTexture());
//                rotatingSprite.setOrigin(POINT1);
//                rotatingSprite.move(POINT1.x + 50, POINT1.y);
//                rotatingSprite.rotate(-90); //now we can rotate
//                rotatingSprite.move(POINT1.x + 80, POINT1.y);
            }
        }


        //----------------save to texture---------------------

        //        mainTexture.draw(circle); //draws a circle into the texture and hence the sprite
        //        mainTexture.draw(rectangle);//draws a rectangle into the texture and hence the sprite


//        mainTexture.draw(line,2,sf::Lines); //draws a line into original texture
//        mainTexture.draw(circle);           //draws a circle into original texture

//        sprite.rotate(1);        //rotates slowly as an example
//        rotatingSprite.rotate(1); //rotates slowly as an example

//        anotherTexture.draw(sprite); //draws the sprite from the original texture into the new texture
        //notice I didn't draw the line and circle again.

//        mainTexture.display(); //saves drawings into texture and hence the sprite
        //------------------------------------------------------

        window.clear(); //comment out for fun effects

        window.draw(sprite); //use the RenderWindow to draw the sprite.
        window.draw(rotatingSprite);// draws the other sprite
        window.draw(testSprite);
        window.display();



    }

    return 0;
}

