#pragma once

 class Bullet :public IGameObject
 {
 public:
     Vector3 m_position;
     Vector3 m_moveDir;
     bool Start();
     void Update();
     void Move();
     void Render(RenderContext& rc);

 private:
     ModelRender m_modelRender;
     CharacterController m_charaCon;
 };
