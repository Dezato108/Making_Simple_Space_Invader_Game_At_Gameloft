#include "Invaders.h"


Invaders::Invaders(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model,shader,texture)
{
}

Invaders::~Invaders()
{
}

//void Invaders::Init()
//{5
//}
//
//void Invaders::Update()
//{
//}
//
//void Invaders::Draw()
//{
//}

void Invaders::changePos(GLfloat deltaTime)
{
	Vector3 currentInvaderPos = GetPosition();

	m_timeline += deltaTime;
	//invader's movement
	if (m_timeline > 0.0) {		
		Set2DPosition(currentInvaderPos.x, currentInvaderPos.y + 100*deltaTime );
	}	
	if (m_timeline > 2.0) {
		Set2DPosition(currentInvaderPos.x, currentInvaderPos.y);
	}
	if (m_timeline > 2.2) {
		Set2DPosition(currentInvaderPos.x+ 1280 *deltaTime, currentInvaderPos.y);
	}
	if (m_timeline > 2.4) {
		Set2DPosition(currentInvaderPos.x , currentInvaderPos.y  );
	}
	if (m_timeline > 2.6) {
		Set2DPosition(currentInvaderPos.x+ 1280 * deltaTime, currentInvaderPos.y);
	}
	if (m_timeline > 2.8) {
		Set2DPosition(currentInvaderPos.x , currentInvaderPos.y  );
	}
	if (m_timeline > 3.0) {
		Set2DPosition(currentInvaderPos.x+ 1280 * deltaTime, currentInvaderPos.y );
	}
	if (m_timeline > 3.1) {
		Set2DPosition(currentInvaderPos.x, currentInvaderPos.y );
	}
	if (m_timeline > 3.2) {
		Set2DPosition(currentInvaderPos.x + 1280 * deltaTime, currentInvaderPos.y);
	}
	if (m_timeline > 3.4) {
		Set2DPosition(currentInvaderPos.x , currentInvaderPos.y);
	}
	if (m_timeline > 3.6) {
		Set2DPosition(currentInvaderPos.x + 1280 * deltaTime, currentInvaderPos.y);
	}
	if (m_timeline > 3.8) {
		Set2DPosition(currentInvaderPos.x , currentInvaderPos.y);
	}
	if (m_timeline > 4.0) {
		Set2DPosition(currentInvaderPos.x - 1280 * deltaTime, currentInvaderPos.y+ 1280 * deltaTime);
	}
	if (m_timeline > 4.1) {
		Set2DPosition(currentInvaderPos.x , currentInvaderPos.y);
	}
}

