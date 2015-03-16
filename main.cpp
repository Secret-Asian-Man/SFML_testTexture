#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

const int WINDOW_WIDTH=1000;
const int WINDOW_HEIGHT=500;
const float RADIUS=5; //for CircleShape

sf::Vector2f POINT1(200,200);
sf::Vector2f POINT2(250,200);

sf::Vector2f POINT3(50,50);
sf::Vector2f POINT4(100,50);

// test comment


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TEST TEST");

    // test addding comment by atomic

    //--------------renderTexture---------------
    sf::RenderTexture generatedTexture; //declares the RenderTexture
    generatedTexture.create(WINDOW_WIDTH,WINDOW_HEIGHT); //MADANTORY. Creates a new canvas for the texture. Use the same dimensions you used for RenderWindow
    sf::Sprite sprite (generatedTexture.getTexture()); //sprites needed to be able to draw the texture

    sf::RenderTexture anotherTexture;
    anotherTexture.create(WINDOW_WIDTH,WINDOW_HEIGHT);
    sf::Sprite anotherSprite(anotherTexture.getTexture());
    //------------------------------------------



    //-------------Just Simple Shapes---------------
    sf::CircleShape circle(RADIUS);
    circle.setOrigin(RADIUS/2,RADIUS/2);
    circle.move(POINT1);

    //    sf::RectangleShape rectangle(sf::Vector2f(200,200));
    //    rectangle.setOrigin(100,100);
    //    rectangle.move(200,200);
    //    rectangle.setFillColor(sf::Color::Green);
    //-----------------------------------------------


    //-------------Lines----------------
    sf::Vertex line[]={
        sf::Vertex(POINT1),
        sf::Vertex(POINT2),
    };

    //----------------------------------


    sprite.setOrigin(POINT1); //sets new origin, BUT will move everything to where (0,0) was previous. Need to compensate for movement.
    sprite.move(POINT1); //compensates for moving origin
    //sprite.rotate(90); //now we can rotate

    anotherSprite.setOrigin(POINT2);
    anotherSprite.move(POINT2);




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                window.close();
        }



        //----------------save to texture---------------------

        //        generatedTexture.draw(circle); //draws a circle into the texture and hence the sprite
        //        generatedTexture.draw(rectangle);//draws a rectangle into the texture and hence the sprite



        generatedTexture.clear(sf::Color::Transparent); //clears you a fresh canvas to draw on
        anotherTexture.clear(sf::Color::Transparent); //clears you a fresh canvas to draw on

        generatedTexture.draw(line,2,sf::Lines); //draws a line into original texture
        generatedTexture.draw(circle); //draws a circle into original texture

        sprite.rotate(1); //rotates slowly as an example
        anotherSprite.rotate(1);//rotates slowly as an example

        anotherTexture.draw(sprite); //draws the sprite from the original texture into the new texture
        //notice I didn't draw the line and circle again.

        generatedTexture.display(); //saves drawings into texture and hence the sprite
        anotherTexture.display();//saves drawings into texture and hence the sprite

        //------------------------------------------------------




        window.clear(); //comment out for fun effects

        window.draw(sprite); //use the RenderWindow to draw the sprite.
        window.draw(anotherSprite);// draws the other sprite

        window.display();



    }

    return 0;
}

