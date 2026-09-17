#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800
#define WINDOW_TOTAL_PIXELS (WINDOW_WIDTH * WINDOW_HEIGHT)
#define WINDOW_SIZE_NUMBER (WINDOW_TOTAL_PIXELS * sizeof(uint32_t))

void	clear_buffer(uint32_t *buffer)
{
	memset(buffer, 0, WINDOW_SIZE_NUMBER);
}

int	main(void) 
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Erreur lors de l'initialisation de SDL : %s", SDL_GetError());
        return (1);
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!SDL_CreateWindowAndRenderer("SDL3D", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer))
    {
        SDL_Log("Erreur lors de la création de la fenêtre et du renderer : %s", SDL_GetError());
        SDL_Quit();
        return (1);
    }

    int running = 1;
    SDL_Event event;
    
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);

    uint32_t *buffer = malloc(WINDOW_TOTAL_PIXELS * sizeof(uint32_t));

    if (!buffer)
    {
	    printf("Malloc failed");
	    return (1);
    }

    SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH * sizeof(uint32_t));

    while (running) 
    {
        while (SDL_PollEvent(&event)) 
	{
            if (event.type == SDL_EVENT_QUIT) 
                running = 0;
        }

        SDL_RenderClear(renderer);

	clear_buffer(buffer);

    	SDL_UpdateTexture(texture, NULL, buffer, WINDOW_WIDTH * sizeof(uint32_t));
	SDL_RenderTexture(renderer, texture, NULL, NULL);
        
	SDL_RenderPresent(renderer);

	SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
