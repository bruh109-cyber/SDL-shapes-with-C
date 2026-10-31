SDL3 Framebuffer

A simple framebuffer rendering project built with C and SDL3.

This project demonstrates how to create a software framebuffer using a uint32_t pixel array and display it in an SDL3 window using a streaming texture. The framebuffer is scaled up using nearest-neighbor filtering to preserve sharp, pixelated graphics.

Features
Window creation using SDL3.
Software framebuffer using a 32-bit integer array.
Streaming texture for framebuffer rendering.
Nearest-neighbor texture scaling.
Real-time framebuffer updates.
Basic SDL event handling.
Clean resource management on exit.
Project Configuration

The framebuffer resolution is:

c
#define WIDTH 320
#define HEIGHT 200


The window is displayed at 4 times the framebuffer resolution:

Framebuffer: 320 × 200 pixels
Window: 1280 × 800 pixels
Pixel format: SDL_PIXELFORMAT_XRGB8888
Requirements
C compiler (GCC, Clang, or MSVC).
SDL3 development libraries.
SDL3 headers.
Compilation

If SDL3 is installed and available through pkg-config, compile using:

bash
gcc main.c -o framebuffer $(pkg-config --cflags --libs sdl3)


Run the program:

bash
./framebuffer


On Windows, the executable will be:

bash
framebuffer.exe

How It Works
1. Framebuffer Creation

A global array stores the pixels that make up the image:

c
uint32_t framebuffer[WIDTH * HEIGHT];


Each element represents one pixel using a 32-bit integer.

2. Texture Creation

SDL3 creates a streaming texture that receives the framebuffer data:

c
texture = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_XRGB8888,
    SDL_TEXTUREACCESS_STREAMING,
    WIDTH,
    HEIGHT
);

3. Nearest-Neighbor Scaling

To preserve the original pixel appearance when scaling:

c
SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);

4. Drawing Pixels

You can modify individual pixels directly through the framebuffer array:

c
framebuffer[16500] = 0x00FF0000;


The array uses row-major indexing:

c
framebuffer[y * WIDTH + x] = color;

5. Updating the Texture

Every frame, the framebuffer is uploaded to the SDL texture:

c
SDL_UpdateTexture(
    texture,
    NULL,
    framebuffer,
    WIDTH * sizeof(uint32_t)
);


The pitch represents the number of bytes in one row of the framebuffer.

6. Rendering

Finally, SDL renders the texture to the window:

c
SDL_RenderClear(renderer);
SDL_RenderTexture(renderer, texture, NULL, NULL);
SDL_RenderPresent(renderer);

Project Structure
text
SDL3-Framebuffer/
│
├── main.c
└── README.md

Future Improvements

Possible features to implement:

Pixel drawing functions.
Rectangle and line drawing.
Framebuffer clearing.
Color manipulation.
Basic 2D graphics.
Keyboard input handling.
Frame rate control.
BMP image loading.
Basic software rasterizer.
License

This project is open-source. Feel free to use, modify, and experiment with the code.

Built with C and SDL3.
