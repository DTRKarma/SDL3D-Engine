#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define WINDOWS_HEIGHT 800
#define WINDOWS_WIDTH 800

int main(void) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Erreur lors de l'initialisation de SDL : %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!SDL_CreateWindowAndRenderer("Test SDL3", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Erreur lors de la création de la fenêtre et du renderer : %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 60, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_FRect rect = { 220, 180, 200, 120 };
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
