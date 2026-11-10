#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"

namespace {
	//定数
	const float moveSpeedRatio = 8.0f;  //移動速度の倍率
	const float moveJump = 30.0f;	//ジャンプ数値
	const float moveRun = 3.5f;		//ダッシュの倍率
}

bool Player::Start()
{
	


	m_modelRender.Init("Assets/modelData/unityChan.tkm");

	m_modelRender.Update();
	//キャラコンの初期値
	//半径25、高さ75、キャラコンの座標はプレイヤーのポジション
	m_charaCon.Init(25.0f, 75.0f, m_position);

	return true;
}

void Player::Update()
{
	Move();
	//キャラコンをmoveSpeed分動かすと同時に動いた後の座標はを取得する
	m_position = m_charaCon.Execute(m_moveSpeed, 1.0f);
	//モデルレンダーを更新
	m_modelRender.SetPosition(m_position);

	Rotation();

	Respawn();

	Bullets();

	m_modelRender.Update();

}

void Player::Move()
{
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.z = 0.0f;

	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	right *= stickL.x * moveSpeedRatio;
	forward *= stickL.y * moveSpeedRatio;


	

	m_moveSpeed += right + forward;

	//地面にいるか
	//if (m_charaCon.IsOnGround() == true)
	//{
	//	

	//}
	//else
	//{
	//	m_moveSpeed.y -= 1.5f;
	//}

	//if (g_pad[0]->IsPress(enButtonB))
	//{
	//	m_moveSpeed.x *= moveRun;
	//	m_moveSpeed.z *= moveRun;
	//}



	m_position = m_charaCon.Execute(m_moveSpeed, 1.0f / 60.0f);

	m_modelRender.SetPosition(m_position);


}

//弾を発射する
void Player::Bullets()
{
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		Bullet* bullet = NewGO<Bullet>(0);

		Vector3 forward= g_camera3D->GetForward();
		
		forward.Normalize();

		bullet->m_position = m_position;
		bullet->m_position.y += 80.0f;
		bullet->m_moveDir = forward;
	}
}

void Player::Rotation()
{
	if (fabsf(m_moveSpeed.x) >= 0.001 || fabsf(m_moveSpeed.z) >= 0.001f)
	{
		rot.SetRotationYFromDirectionXZ(m_moveSpeed);

		m_modelRender.SetRotation(rot);

	}
}

void Player::ManageState()
{
	
}

void Player::PlayAnimation()
{
	
}

void Player::Respawn()
{
	if (m_position.y < -1000.0f)
	{
		m_position = Vector3(0.0f, 10.0f, 0.0f);

		m_moveSpeed = Vector3::Zero;

		m_charaCon.SetPosition(m_position);

		m_modelRender.SetPosition(m_position);

	}
}

Vector3 Player::GetPosition()const
{
	return m_position;
}


void Player::Render(RenderContext& rc)
{
	//m_modelRender.Draw(rc);
}

