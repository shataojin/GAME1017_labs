#pragma once
#ifndef _STATEMANAGER_H_
#define _STATEMANAGER_H_

#include "States.h"
#include <vector>

// We're going to make StateManager a "static class".

class StateManager
{
private:
	static std::vector<State*> s_states;
private:
	StateManager()
	{
		
	}

public:
	static void Update();
	static void Render();
	static void PushState(State* pstate);
	static void PopState();
	static void ChangeState(State* pstate);
	static void Quit();
	static  std::vector<State*>& GetStates();
};

typedef StateManager STMA;

#endif

