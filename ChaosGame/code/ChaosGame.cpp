#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

using namespace sf;
using namespace std;

int main()
{
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
	
        int verts;
        cout << "Choose amount of vertices 3-5" << endl;
        cin >> verts;
	
        while(verts != 3 && verts != 4 && verts != 5)
        {
            cout << "Error: Choose amount of vertices 3-5" << endl;
            cin >> verts;
        }
	
        if(verts == 3)
        {
        	instructionText.setString("                                                                                                                 Click on any three points to create the vertices for the triangle.");
        }
        else if(verts == 4)
        {
        	instructionText.setString("                                                                                                              Click on any four points to create the vertices for the square/rectangle");
        }
        else if(verts == 5)
        {
        	instructionText.setString("                                                                                                                 Click on any five points to create the vertices for the pentagon");
        }


	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Chaos Game", Style::Default);

    	vector<Vector2f> vertices;
    	vector<Vector2f> points;



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

                    if(vertices.size() < verts)
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

        if(verts == 3)
        {
            if(points.size() > 0)
            {
                for(int x = 0; x < 50; x++)
                {
     	        //current point
                Vector2f lastPoint = points.back();

	        //random vertex
                Vector2f randomVertex = vertices[rand() % vertices.size()];

	        //calculates midpoint
                Vector2f midpoint = (lastPoint + randomVertex) / 2.0f;

	        //pushes new point back into vector
                points.push_back(midpoint);
                }
            }
        }
        
        if(verts == 4)
        {
            if(points.size() > 0)
            {
                for(int x = 0; x < 50; x++)
                {
                    Vector2f lastPoint = points.back();
			
                    int randVert;
                    int prevVert;
			
                    randVert = rand() % verts;
			
                    	while(randVert == prevVert + 2 || randVert == prevVert - 2)
                    	{
                        	randVert = rand() % verts;
                        	Vector2f randomVertex = vertices[randVert];
                   	}
			
                    	Vector2f randomVertex = vertices[randVert];
                    	Vector2f midpoint = (lastPoint + randomVertex) / 2.0f;
			
                    prevVert = randVert;
                    points.push_back(midpoint);
                }
            }

        }

        if(verts == 5)
        {
            if(points.size() > 0)
            {
                for(int x = 0; x < 50; x++)
                {
                    Vector2f lastPoint = points.back();
                    int randVert;
                    int prevVert;
			
                    	randVert = rand() % verts;
			
                   	while(randVert == prevVert)
                   	{
                        	randVert = rand() % verts;
                        	Vector2f randomVertex = vertices[randVert];
                    	}
			
                   	 Vector2f randomVertex = vertices[randVert];
                   	 Vector2f midpoint = (lastPoint + randomVertex) / 2.0f;
			
                    prevVert = randVert;
                    points.push_back(midpoint);
                }
            }
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
