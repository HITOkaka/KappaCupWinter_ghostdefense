#include "stdafx.h"
#include "Bullet.h"

namespace {
	//定数
	const float movespeed = 50.0f;
}

bool Bullet::Start()
{
	m_modelRender.Init("Assets/modelData/Bullet.tkm");
	
	m_modelRender.Update();

	m_charaCon.Init(15.0f, 15.0f, m_position);
	return true;
}

void Bullet::Move()
{
	m_position += m_moveDir * movespeed;

	m_modelRender.SetPosition(m_position);

	m_modelRender.Update();
}

void Bullet::Update()
{
	Move();
	
}

void Bullet::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}