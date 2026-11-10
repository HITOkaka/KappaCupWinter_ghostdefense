#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"

bool Game::Start()
{
	m_bg = NewGO<BackGround>(0, "backGround");
	m_player = NewGO<Player>(0, "player");
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");
	return true;
}

void Game::Update()
{
	
	
}

void Game::Render(RenderContext& rc)
{
	
}