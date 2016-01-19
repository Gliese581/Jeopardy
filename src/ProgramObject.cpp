#include "ProgramObject.h"
#include <iostream>

using std::cerr;
using std::endl;

void ProgramObject::Quit() {
    state = ProgramState::Quit;
}

bool ProgramObject::ProcessEvent(const SDL_Event &event) {
    switch (event.type) {
    case SDL_QUIT:
        Quit();
        return true;
    case SDL_KEYDOWN:
        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            Quit();
            return true;
        } else {
            return false;
        }
    case SDL_MOUSEBUTTONDOWN:
        PlaySound();
    default:
        return false;
    }
}

void ProgramObject::MainLoop() {
    StartMusic();
	SDL_SetWindowFullscreen(window.get(), SDL_WINDOW_FULLSCREEN);
    
	while (state != ProgramState::Quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ProcessEvent(event);
        }

        // clear screen
        SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
        SDL_RenderClear(renderer.get());

        Update();
        Render();

        // make things visible
        SDL_RenderPresent(renderer.get());
    }
}

void ProgramObject::Update() {
    // insert code here
}

void ProgramObject::Render() const {
    // insert code here

    text_renderer.RenderBaked(sample_text_object, glm::ivec2(100,250));
    text_renderer.RenderDirect("Jeopardy", glm::ivec2(100,350));

}

void ProgramObject::PlaySound() {
	Mix_VolumeChunk(sample_chunk.get(),MIX_MAX_VOLUME/2);
    Mix_PlayChannel(0,sample_chunk.get(),0);
}

void ProgramObject::StartMusic() {
    // -1 for infinite loop
    Mix_PlayMusic(sample_music.get(),-1);
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
}
