#include "data.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define kejdown meowEvent.type == SDL_KEYDOWN
#define kejup meowEvent.type == SDL_KEYUP

int tablicaAktywnych[4][10];
int turnOn = 1;

int lenstr(const char  tablica[]) {for (int i = 0; 1; i++) if (tablica[i] == 0) return i;}

int main() {
    for (int x = 0; x < 10; x++ ) for (int y = 0; y < 4; y++) tablicaAktywnych[y][x] = 0;

    SDL_Window* meowOkno = SDL_CreateWindow ("Fajne Okno",100,100,100,100, SDL_WINDOW_SHOWN);
    SDL_Renderer* meowRender = SDL_CreateRenderer (meowOkno, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event meowEvent;
    Mix_Chunk *sound[4][10];

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 500);
    Mix_AllocateChannels(92);
    Mix_Music * struny[4];
    char otworRezonansowy[4] = {0,0,0,0};

    for (int y = 0; y < 4; y++) for (int x = 0; x < 10; x++)
    {
        char buffor[100] = "posortowane/";
        char mp3[] = ".mp3";
        int pierwszy = lenstr(buffor);
        int ostatni = lenstr(gryfMp3[y][x]);

        for (int i = pierwszy; i < pierwszy + ostatni ; i++ ) buffor[i] = gryfMp3[y][x][i-pierwszy];
        for (int i = pierwszy + ostatni; i < pierwszy + ostatni+1 + 5; i++) buffor[i] = mp3[i-(pierwszy + ostatni)];

        sound[y][x] = Mix_LoadWAV(buffor);
    }


    while (turnOn) {

        while (SDL_PollEvent(&meowEvent)) {
            if (meowEvent.type == SDL_QUIT ) turnOn = 0; 
            else if (kejdown || kejup)
            {
                int evvalue = 0;
                if (kejdown) evvalue=1;
                int evcode = meowEvent.key.keysym.scancode;

                if (evcode == 41) turnOn = 0;

                for (int x = 0; x < 10; x++) for (int y = 0; y < 4; y++) if (evcode == gryfLiczby[y][x]) tablicaAktywnych[y][x] = evvalue;
                for (int i = 0; i < 4; i++) if (evcode == wlaczniki[i]) otworRezonansowy[i] = evvalue;
            
                for (int y = 0; y < 4; y++) if (evcode == wlaczniki[y]) for (int x = 9; x >= 0; x-- )
                {
                    if ((tablicaAktywnych[y][x] == 1 || x == 0) && kejup)
                    {
                        int p;
                        for (p = y; p < 64 && Mix_Playing(p) ; p+=4) {}
                        if (p > 63) Mix_PlayChannel(-1, sound[y][x], 0);
                        else Mix_PlayChannel(p, sound[y][x], 0);

                        break;
                    }
                }
            }
        }
        SDL_RenderPresent(meowRender); 
        SDL_Delay(16);
    }

    for (int i = 0; i < 4; i++) Mix_FreeMusic(struny[i]);
    for (int y = 0; y < 4; y++) for (int x = 0; x <10; x++) Mix_FreeChunk(sound[y][x]);
    SDL_DestroyRenderer (meowRender);
    SDL_DestroyWindow (meowOkno);
    SDL_Quit();
    return 67;
}
