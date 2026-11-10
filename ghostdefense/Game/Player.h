#pragma once
class Bullet;

class Player:public IGameObject
{
public:
	Player(){}
	~Player(){}

	bool Start();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	void ManageState();
	void PlayAnimation();
	void Respawn();
	void Bullets();
	Vector3 GetPosition()const;

	int jumpState = 0;
	int playerState = 0;

	Vector3 m_position = { 0.0f,0.0f,-300.0f };

private:
	
	
	ModelRender m_modelRender;
	CharacterController m_charaCon;
	Vector3 m_moveSpeed = Vector3::Zero;
	Quaternion rot;
	Bullet* bullet = nullptr;
};

