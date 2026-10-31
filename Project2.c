#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <SDL3/SDL.h>
#include <stdlib.h>

#define WIDTH 320
#define HEIGHT 200

uint32_t framebuffer[WIDTH * HEIGHT];
int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL Framebuffer", 
     WIDTH * 4, 
     HEIGHT * 4, 
     0
    );

    renderer = SDL_CreateRenderer(  
        window, 
        NULL
    );

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_XRGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH,
        HEIGHT
    );

    SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
    

    


    uint8_t is_running = 1;

    while(is_running){
        /*Pull the events*/
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                is_running = 0;
            }
        }

        /*Here we manipulate our framebuffer array as we wish*/
        framebuffer[16500] = 0xFF0000;

        SDL_UpdateTexture(texture,
        NULL,
        framebuffer,
        WIDTH * sizeof(uint32_t) //pitch --> the width of the image/texture in bytes, which is the width of the image multiplied by the size of each pixel in bytes
        );


        /*Display the window and the renderer */
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();



    printf("SDL is working fine.\n");

    return EXIT_SUCCESS;
}