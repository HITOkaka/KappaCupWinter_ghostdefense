#include "stdafx.h"
#include "BackGround.h"

bool BackGround::Start()
{
	m_modelRender.Init("Assets/modelData/stage/Map_base.tkm");
	m_pso.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	return true;
}

void BackGround::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}