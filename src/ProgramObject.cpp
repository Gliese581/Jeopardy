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
	if (SDL_SetWindowFullscreen(window.get(), SDL_WINDOW_FULLSCREEN) != 0) {
        cerr << "Unable to initialize Fullscreen: " << SDL_GetError() << endl;
	}
    StartMusic();
	
	while (state != ProgramState::Quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ProcessEvent(event);
        }

        // clear screen
        SDL_SetRenderDrawColor(renderer.get(), 1, 87, 155, 1);
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
    text_renderer_H0.RenderBaked(text_object_jeopardy, glm::ivec2(100,250));
}

void ProgramObject::PlaySound() {
	Mix_VolumeChunk(sample_chunk.get(),MIX_MAX_VOLUME/5);
    Mix_PlayChannel(0,sample_chunk.get(),0);
}

void ProgramObject::StartMusic() {
    // -1 for infinite loop
    Mix_PlayMusic(music_jeopardy.get(),-1);
    Mix_VolumeMusic(MIX_MAX_VOLUME);
}
