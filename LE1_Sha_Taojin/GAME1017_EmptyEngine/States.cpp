#include "States.h"
#include "StateManager.h"
#include "Engine.h"
#include <iostream>
using namespace std;

void State::Render()
{
	SDL_RenderPresent(Engine::Instance().GetRenderer());
}

/// <summary>
/// ////////////////////
/// </summary>
/// 
TitleState::TitleState(){}

void TitleState::Enter()
{
	cout << "Enter Title State --> " << endl;
	//load music track, add it to map, and  play
}

void TitleState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_N))
	{
		cout << "changing to game state" << endl;
		STMA::ChangeState(new GameState);
	}
}

void TitleState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 0, 255, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());
	State::Render();
}

void TitleState::Exit()
{
	cout << "exit title state----->" << endl;
	//call mix_freeMusic on track
	
}


/// <summary>
/// ////////////////////
/// </summary>
/// 
PauseState::PauseState()
{
	
}

void PauseState::Enter()
{
	cout << "Enter pauseState --> " << endl;
}

void PauseState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_R))
	{
		STMA::PopState();
	}
}

void PauseState::Render()
{
	//first render the game state.
	STMA::GetStates().front()->Render();
	// now render ther rest of pasuse state
	SDL_SetRenderDrawBlendMode(Engine::Instance().GetRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 255, 0, 0, 126);
	SDL_Rect rect = { 255,128,512,512 };
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &rect);
	State::Render();
}

void PauseState::Exit()
{
	cout << "exit pauseState----->" << endl;
}

/// <summary>
/// ////////////////////
/// </summary>
/// 

GameState::GameState()
{
	
}

void GameState::Enter()
{
	cout << "Enter GameState --> " << endl;
	//load music track and music sfx , add it to map, and  play
	m_pMusic = Mix_LoadMUS("Aud/????.mp3");
	m_pSounds = Mix_LoadWAV("Aud/>>>>.wav");
}

void GameState::Update()
{
	if (Engine::Instance().KeyDown(SDL_SCANCODE_P))
	{
		cout << "changing to pauseState" << endl;
		STMA::PushState(new PauseState);
	}
	//pause 'x' and change state to end state.
	//push key 1 to play sound 1
	// push key 1 to play sound 2

	
}

void GameState::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), 0, 255, 0, 255);
	SDL_RenderClear(Engine::Instance().GetRenderer());
	// this code below prevents SDL_RenderPresent from running twice in one frame.
	if(dynamic_cast<GameState*>(STMA::GetStates().back()))
	State::Render();
}

void GameState::Exit()
{
	cout << "exit game state----->" << endl;
}

void GameState::Resume()
{
	cout << "resuming gamestate----->" << endl;
	//resum music track
}