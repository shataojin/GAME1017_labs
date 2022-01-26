#pragma once
#ifndef _STATES_H_
#define _STATES_H_

class State
{
protected:
	State() = default;
public:
	//virtual ~State() = default;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Render();
	virtual void Exit() = 0;
	virtual void Resume(){};
};


class TitleState: public State
{
private:

public:
	TitleState();
	virtual void Enter() ;
	virtual void Update() ;
	virtual void Render();
	virtual void Exit() ;
};

class PauseState : public State
{
private:

public:
	PauseState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

class GameState : public State
{
private:
	//map for music track
//map for sfx

public:
	GameState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
	virtual void Resume();
};

class EndState : public State
{
private:

public:
	EndState();
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif