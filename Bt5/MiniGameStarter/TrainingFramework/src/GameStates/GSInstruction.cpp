#include "GSInstruction.h"
#include "Camera.h"

GSInstruction::GSInstruction() : GameStateBase(StateType::STATE_INSTRUCTION),
m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
}


GSInstruction::~GSInstruction()
{
}



void GSInstruction::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("Parallax100.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	//keyboard
	texture = ResourceManagers::GetInstance()->GetTexture("kiboard.tga");
	m_kiboard = std::make_shared<Sprite2D>(model, shader, texture);
	m_kiboard->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight/2+100);
	m_kiboard->SetSize(800, 800);

	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_x.tga");
	auto button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arcade.ttf");
	m_text1 = std::make_shared< Text>(shader, font, "Left", TextColor::RED, 1);
	m_text1->Set2DPosition((float)Globals::screenWidth / 2 - 230, (float)Globals::screenHeight / 2-170);

	m_text2 = std::make_shared< Text>(shader, font, "Right", TextColor::RED, 1);
	m_text2->Set2DPosition((float)Globals::screenWidth / 2 - 90, (float)Globals::screenHeight / 2 - 170);

	m_text3 = std::make_shared< Text>(shader, font, "Shoot", TextColor::RED, 1);
	m_text3->Set2DPosition((float)Globals::screenWidth / 2 + 50, (float)Globals::screenHeight / 2 - 170);

	m_text4 = std::make_shared< Text>(shader, font, "Dash", TextColor::RED, 1);
	m_text4->Set2DPosition((float)Globals::screenWidth / 2 + 190, (float)Globals::screenHeight / 2 - 170);
}

void GSInstruction::Exit()
{
}


void GSInstruction::Pause()
{
}

void GSInstruction::Resume()
{
}


void GSInstruction::HandleEvents()
{
}

void GSInstruction::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSInstruction::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSInstruction::HandleMouseMoveEvents(int x, int y)
{
}

void GSInstruction::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSInstruction::Draw()
{
	m_background->Draw();
	m_kiboard->Draw();
	m_text1->Draw();
	m_text2->Draw();
	m_text3->Draw();
	m_text4->Draw();

	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
