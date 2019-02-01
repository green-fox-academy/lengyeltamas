#include <iostream>
#include <SDL.h>

//Screen dimension constants
const double SCREEN_WIDTH = 600;
const double SCREEN_HEIGHT = 600;

//Draws geometry on the canvas
void draw();

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The window renderer
SDL_Renderer* gRenderer = nullptr;

void fractalDrawer3000 (long double limit, long double width, long double height, long double X, long double Y) {

    if (limit > 1) {
        long double quaterWidth = width / 4;
        long double quaterHeight = height / 4;
        long double Xstart = X;
        long double Ystart = Y;
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);

        SDL_RenderDrawLine(gRenderer, Xstart + quaterWidth * 0, Ystart + quaterHeight * 0, Xstart + quaterWidth * 2, Ystart + quaterHeight * 4);
        SDL_RenderDrawLine(gRenderer, Xstart + quaterWidth * 2, Ystart + quaterHeight * 4, Xstart + quaterWidth * 4, Ystart + quaterHeight * 0);
        SDL_RenderDrawLine(gRenderer, Xstart + quaterWidth * 0, Ystart + quaterHeight * 0, Xstart + quaterWidth * 4, Ystart + quaterHeight * 0);

        fractalDrawer3000(limit - 1, 2 * quaterWidth, 2 * quaterHeight, 2 * quaterWidth + Xstart, Ystart);
        fractalDrawer3000(limit - 1, 2 * quaterWidth, 2 * quaterHeight, quaterWidth + Xstart, 2 * quaterHeight + Ystart);
        fractalDrawer3000(limit - 1, 2 * quaterWidth, 2 * quaterHeight, Xstart, Ystart);

    }
}



void draw()
{
    long double number = 9;
    long double Xstart = 0;
    long double Ystart = 0;
    fractalDrawer3000(number, SCREEN_WIDTH, SCREEN_HEIGHT, Xstart, Ystart);


}
bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow( "Line Play Quaters", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == nullptr )
    {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == nullptr )
    {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit ) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        draw();

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}