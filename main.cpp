#include "bobat.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <stdexcept>

// For a window
#include <SDL2/SDL.h>

using namespace std;

template <class T>
void printVec(vector3d<T> other)
{
	cout << other.getX() << "; ";
	cout << other.getY() << "; ";
	cout << other.getZ() << "\n";
}

#include <assert.h>
int main(int argc, char ** args)
{
	scene testscene;

	testscene.props.width = 200;
	testscene.props.height = 100;

	testscene.backgroundColor = color<f32>(0.5,0,0,1);

	// construct testScene
	vector3df TestPoly[] = {
		vector3df(0,0,0),
		vector3df(0,0,1),
		vector3df(0,-1,1),

		vector3df(0,0,0),
		vector3df(0,-1,1),
		vector3df(0,-1,0)
	};

	testscene.Plist.push_back(new polygon(TestPoly));
	testscene.Plist.push_back(new polygon(TestPoly+3));

	((polygon*)testscene.Plist[1])->setColor(color<f32>(0.5,0.5,1,1));

	camera testcam(vector3df(3,1,0),vector3df(-1,-1,0), vector3df(0,1,0));

	SDL_Init(SDL_INIT_VIDEO);

	// WINDOW stuff
	SDL_Window * window;
	SDL_Renderer * renderer;

	SDL_CreateWindowAndRenderer(testscene.props.width, testscene.props.height, SDL_WINDOW_SHOWN, &window, &renderer);

	SDL_Texture * RenderTex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, testscene.props.width, testscene.props.height);

	if (!RenderTex)
		throw std::runtime_error("Could not create Texture");

	u64 timeBench = 0;
	u64 average = 0;

	bool running = true;
	while(running)
	{
		SDL_Event e;
		while(SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				running = false;

			if (e.type == SDL_KEYDOWN)
				if (e.key.keysym.sym == SDLK_ESCAPE)
					running = false;
		}

		int err = SDL_UpdateTexture(RenderTex, NULL, testcam.render(testscene, &timeBench), testscene.props.width*4);
		// calculate the average
		average = (f32)(average+timeBench)/2.0;
		std::cout << "Time Need:(avg)" << average << " (cur) " << timeBench << '\n';

		if (err < 0)
			throw std::runtime_error("Could not update Texture: " + std::string(SDL_GetError()));

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, RenderTex, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();

	return 0;
}
