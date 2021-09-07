#include "ParallelBG.h"
#include "Application.h"


ParallelBG::ParallelBG() : m_time(0), m_speed(0)
{
}

ParallelBG::ParallelBG(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLfloat speed)
	: BaseObject(0,model,shader,texture), m_time(0.0f), m_speed(speed)
{
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize((float)Globals::screenWidth+100, (float)Globals::screenHeight+100);

	m_background1 = std::make_shared<Sprite2D>(model, shader, texture);
	m_background1->Set2DPosition((float)Globals::screenWidth/2 , -(float)Globals::screenHeight/2);
	m_background1->SetSize((float)Globals::screenWidth+100, (float)Globals::screenHeight+100);
	Init();
}

void ParallelBG::Init()
{
	SetCamera(Application::GetInstance()->GetCamera());
	CalculateWorldMatrix();
}

void ParallelBG::Update(GLfloat deltaTime)
{
	m_time += deltaTime;
	Vector2 deltaMove = Vector2(0,1) * m_speed * deltaTime;
	m_background->Set2DPosition(m_background->GetPosition().x + deltaMove.x, m_background->GetPosition().y + deltaMove.y);

	if (m_background->GetPosition().y > Globals::screenHeight + Globals::screenHeight/2+50) {
		//m_background->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2, m_background->GetPosition().y);
		m_background->Set2DPosition(m_background->GetPosition().x, -Globals::screenHeight/2);
	}

	m_background1->Set2DPosition(m_background1->GetPosition().x + deltaMove.x, m_background1->GetPosition().y + deltaMove.y);

	if (m_background1->GetPosition().y > Globals::screenHeight + Globals::screenHeight / 2+50) {
		//m_background1->Set2DPosition(Globals::screenWidth + Globals::screenWidth / 2, m_background1->GetPosition().y);
		m_background1->Set2DPosition(m_background1->GetPosition().x, -Globals::screenHeight / 2 );
	}
}

void ParallelBG::Draw()
{
	m_background->Draw();
	m_background1->Draw();
}
