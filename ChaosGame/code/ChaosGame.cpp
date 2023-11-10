#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

using namespace sf;
using namespace std;

int main()
{
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Chaos Game", Style::Default);

    vector<Vector2f> vertices;
    vector<Vector2f> points;

	//font
        sf::Font font;
        if (!font.loadFromFile("Arial.ttf"))
        {   
        cerr << "Error" << endl;
        return -1;
        }
	//setting the text
        Text instructionText;
        instructionText.setFont(font);
        instructionText.setCharacterSize(20);
        instructionText.setFillColor(Color::White);
        instructionText.setString("                                                                                                                 Click on any three points to create the vertices for the triangle.");
   

	while (window.isOpen())
	{
      
        
        
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
		    //terminal prints location
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 3)
                    {
			//adds to vertices vector
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                       points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));

                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

        if(points.size() > 0)
        {
     	    //current point
            Vector2f lastPoint = points.back();
	    //random vertex
            Vector2f randomVertex = vertices[rand() % vertices.size()];
	    //calculates midpoint
            Vector2f midpoint = (lastPoint + randomVertex) / 2.0f;
	    //pushes new point back into vector
            points.push_back(midpoint);

            Vector2f lastPoint1 = points.back();
            Vector2f randomVertex1 = vertices[rand() % vertices.size()];
            Vector2f midpoint1 = (lastPoint1 + randomVertex1) / 2.0f;
            points.push_back(midpoint1);

            Vector2f lastPoint2 = points.back();
            Vector2f randomVertex2 = vertices[rand() % vertices.size()];
            Vector2f midpoint2 = (lastPoint2 + randomVertex2) / 2.0f;
            points.push_back(midpoint2);

        
        }
        
        window.clear();

	//draws new points
        for(int i = 0; i < points.size(); i++)
        {
            RectangleShape rect(Vector2f(2.5,2.5));
            rect.setPosition(Vector2f(points[i].x, points[i].y));
            rect.setFillColor(Color::White);
            window.draw(rect);
        }

	//draws vertices
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }

	//prints text
        window.draw(instructionText);
        window.display();
    }
}
