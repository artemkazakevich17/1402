#include "settings.h"
#include "road.h"
#include "player.h"

using namespace sf;

int main()
{

	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass1, grass2, road1, road2;
	roadLayerInit(grass1, Vector2f{ 0.f,0.f }, "grass.jpg", 0.f);
	roadLayerInit(grass2, Vector2f{ 0.f,-WINDOW_HEIGHT }, "grass.jpg", 0.f);
	roadLayerInit(road1, Vector2f{ 100.f,0.f }, "road.jpg", 100.f);
	roadLayerInit(road2, Vector2f{ 100.f,-WINDOW_HEIGHT }, "road.jpg", 100.f);
	Player player;
	playerInit(player);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)
				
				window.close();
		}
		//Update
		roadLayerUpdate(grass1);
		roadLayerUpdate(grass2);
		roadLayerUpdate(road1);
		roadLayerUpdate(road2);
		playerUpdate(player);

		window.clear();
		roadLayeDraw(window, grass1);
		roadLayeDraw(window, grass2);
		roadLayeDraw(window, grass1);
		roadLayeDraw(window, grass2);
		roadLayeDraw(window, road1);
		roadLayeDraw(window, road2);
		playerDraw(window, player);
		window.display();
	}

	return 0;
}