#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "config.h"
#include "pointers.h"
#include "TextRenderer.h"

// can be extended with states like menu, game, etc
enum class ProgramState {
    Running,
    Quit,
};

class ProgramObject {
  protected:
    ProgramState state;
    UniqueWindow window;
    UniqueRenderer renderer;
    TextRenderer text_renderer;
    TextObject sample_text_object;
    UniqueChunk sample_chunk;
    UniqueMusic sample_music;
  public:
    ProgramObject():
        state(ProgramState::Running),
        window(SDL_CreateWindow(APPLICATION, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0)),
        renderer(SDL_CreateRenderer(window.get(), 0, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED)),
        text_renderer(renderer.get(), base_path+"assets/fonts/jeopardy.ttf", 32),
        sample_text_object(text_renderer.BakeString("d1p0")),
        sample_chunk(Mix_LoadWAV((base_path+"assets/sounds/jdaily2x.wav").c_str())),
        //sample_music(Mix_LoadMUS((base_path+"assets/Dandelions.ogg").c_str()))
        sample_music(Mix_LoadMUS((base_path+"assets/music/jeopardy.wav").c_str()))
    {
    }

    // should return true when the event has been processed. Is called for every incoming event
    bool ProcessEvent(const SDL_Event &event);
    // call this function if you want the main to to break;
    void Quit();
    // event catching, update, render
    void MainLoop();
    // do everything that make changes in the world like a simulation step
    void Update();
    // just rendering nothing else
    void Render() const;
    // plays the one sample sound chunk
    void PlaySound();
    // stars the one sample music
    void StartMusic();
};
