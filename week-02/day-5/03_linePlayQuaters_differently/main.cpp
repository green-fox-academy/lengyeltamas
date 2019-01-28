#include <iostream>
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

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

void fun (int& x, int& y, int& lines, int& multiplicator) {

    int PIECE_WIDTH = SCREEN_WIDTH/multiplicator;
    int PIECE_HEIGHT = SCREEN_HEIGHT/multiplicator;


    SDL_SetRenderDrawColor(gRenderer, 218, 112, 214, 0xFF);

    SDL_RenderDrawLine(gRenderer, ((PIECE_WIDTH * y) - PIECE_WIDTH), ((PIECE_HEIGHT * x) - PIECE_HEIGHT + lines), ((PIECE_WIDTH * y) - PIECE_WIDTH + lines), (PIECE_HEIGHT * x));

    SDL_SetRenderDrawColor(gRenderer, 50, 205, 50, 0xFF);

    SDL_RenderDrawLine(gRenderer, ((PIECE_WIDTH * y) - PIECE_WIDTH + lines), ((PIECE_HEIGHT * x) - PIECE_HEIGHT) ,(PIECE_WIDTH * y) ,(PIECE_WIDTH * x) - PIECE_HEIGHT+lines );
}

void draw()
{
    int num = 1; //num is the value of the multiplication by axis. 1, 2, 4 and 8 are tested.//
    for (int x = 0; x <= num; x++) {
        for (int y = 0; y <= num; y++) {
            for (int i = ((SCREEN_WIDTH/num)/20); i < (SCREEN_WIDTH/num); i+= ((SCREEN_WIDTH/num)/40)) {
                fun (x, y, i, num);
            }
        }
    }
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