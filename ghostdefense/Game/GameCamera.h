#pragma once
class Player;

class GameCamera : public IGameObject
{
public:
	GameCamera() {};
	~GameCamera() {};
	bool Start()override;
	void Update()override;

private:
	Vector3 m_toCameraPos;	//視点制作用の注視点から視点に向かうベクトル
	Player* m_player = nullptr;	//プレイヤーポインター
};


