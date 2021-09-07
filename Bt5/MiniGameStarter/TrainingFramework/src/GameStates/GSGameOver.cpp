#include "GSGameOver.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include <iostream>
#include <fstream>
using namespace std;

GSGameOver::GSGameOver()
{
}


GSGameOver::~GSGameOver()
{
}


void GSGameOver::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	//image game over
	texture = ResourceManagers::GetInstance()->GetTexture("img_gameover.tga");
	m_imageGameOver = std::make_shared<Sprite2D>(model, shader, texture);
	m_imageGameOver->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2 - 150);
	m_imageGameOver->SetSize(500, 100);

	// button back to menu
	texture = ResourceManagers::GetInstance()->GetTexture("btn_home.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth /2, Globals::screenHeight /2 + 150);
	button->SetSize(150, 150);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		});
	m_listButton.push_back(button);

	// text
	ifstream myReadFile("score.txt");
	getline(myReadFile, m_scoreNum);

	ifstream myReadFile1("highscore.txt");
	getline(myReadFile1, m_highScoreNum);

	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arcade.ttf");
	m_text1 = std::make_shared< Text>(shader, font, "Score : "+ m_scoreNum, TextColor::RED, 1.3);
	m_text1->Set2DPosition((float)Globals::screenWidth / 2 - 150, (float)Globals::screenHeight / 2+50);
	
	m_text2 = std::make_shared< Text>(shader, font, "High Score : " + m_highScoreNum, TextColor::WHITE, 1.3);
	m_text2->Set2DPosition((float)Globals::screenWidth / 2 -305, (float)Globals::screenHeight / 2 -30);
}

void GSGameOver::Exit()
{
}


void GSGameOver::Pause()
{
}

void GSGameOver::Resume()
{
}


void GSGameOver::HandleEvents()
{
}

void GSGameOver::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSGameOver::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSGameOver::HandleMouseMoveEvents(int x, int y)
{
}

void GSGameOver::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSGameOver::Draw()
{
	m_background->Draw();
	m_imageGameOver->Draw();
	m_text1->Draw();
	m_text2->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}