#pragma once

#include "Level3DRender/LevelRender.h"

class Player;
class BackGround;
class GameCamera;

class Game : public IGameObject
{
public:
	Game() {}
	~Game() {}
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	GameCamera* m_gameCamera = nullptr;;
	BackGround* m_bg = nullptr;
	Player* m_player = nullptr;
	ModelRender m_modelRender;
	Vector3 m_pos;
};

