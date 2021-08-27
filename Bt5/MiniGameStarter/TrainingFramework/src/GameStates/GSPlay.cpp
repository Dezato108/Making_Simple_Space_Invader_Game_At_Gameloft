#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include <Invaders.h>



GSPlay::GSPlay() : m_timeline(0)
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// player spaceship
	texture = ResourceManagers::GetInstance()->GetTexture("spaceship2.tga");
	m_player = std::make_shared<Sprite2D>(model, shader, texture);
	m_player->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight-60);
	m_player->SetSize(60, 50);

	// monsters
	texture = ResourceManagers::GetInstance()->GetTexture("bsauce.tga");
	auto invader1 = std::make_shared<Invaders>(model, shader, texture);
	//m_invader->Set2DPosition((float)Globals::screenWidth - (float)Globals::screenWidth + 50, (float)Globals::screenHeight - (float)Globals::screenHeight -30);
	invader1->Set2DPosition((float)Globals::screenWidth /2, (float)Globals::screenHeight /2);
	invader1->SetSize(70, 60);
	m_listInvaders.push_back(invader1);

	auto invader2 = std::make_shared<Invaders>(model, shader, texture);
	invader2->Set2DPosition((float)Globals::screenWidth / 2+50, (float)Globals::screenHeight / 2);
	invader2->SetSize(70, 60);
	m_listInvaders.push_back(invader2);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_x.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

//int m_keyPressed = 0;
void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed == true) {
		switch (key) {
		case'A':
			m_keyPressed |= KEY_MOVE_LEFT;
			break;
		case'D':
			m_keyPressed |= KEY_MOVE_RIGHT;
			break;
		default:
			break;
		}
	}
	else {
		switch (key) {
		case'A':
			m_keyPressed ^= KEY_MOVE_LEFT;
			break;
		case'D':
			m_keyPressed ^= KEY_MOVE_RIGHT;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime){
	Vector3 currentPos = m_player->GetPosition();

	//handle character's movement
	if (m_keyPressed & KEY_MOVE_LEFT) {	
		if (currentPos.x >= 80)
			m_player->Set2DPosition(Vector2(currentPos.x - 300 * deltaTime, currentPos.y));
	}
	if (m_keyPressed & KEY_MOVE_RIGHT) {		
		if (currentPos.x <= 1200)
			m_player->Set2DPosition(Vector2(currentPos.x + 300 * deltaTime, currentPos.y));
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	for (auto i = 0; i<m_listInvaders.size(); i++) {
		m_listInvaders[i]->Draw();
	}
	//m_score->Draw();
	m_player->Draw();
	//m_invader->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}