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
#include <iostream>
#include <fstream>

using namespace std;

int GSPlay::m_keyPressed(0);


GSPlay::GSPlay()
{
	waitTime2 = 0;
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	
	highScoreNum = 0;
	m_levelboss = 0;
	m_levelnormal = 0;
	m_scoreNum = 0;
	isGameOver = false;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");

	// background
	auto texture = ResourceManagers::GetInstance()->GetTexture("Parallax100.tga");
	m_background = std::make_shared<ParallelBG>(model, shader, texture, 100.0f);

	//player spaceship
	texture = ResourceManagers::GetInstance()->GetTexture("spaceship2.tga");
	std::shared_ptr<Player> player = std::make_shared<Player>(model, shader, texture);
	player->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight - 60);
	player->SetSize(60, 50);
	m_listPlayer.push_back(player);

	// invaders
	texture = ResourceManagers::GetInstance()->GetTexture("rsauce.tga");
	auto invader1 = std::make_shared<Invader>(model, shader, texture);
	invader1->Set2DPosition((float)Globals::screenWidth+150, (float)Globals::screenHeight / 2 -200);
	invader1->SetSize(70, 60);
	invader1->SetType("boss");
	invader1->SetLevelBoss(1);
	invader1->SetHP(4);
	m_listInvaders.push_back(invader1);

	texture = ResourceManagers::GetInstance()->GetTexture("bsauce.tga");
	auto invader2 = std::make_shared<Invader>(model, shader, texture);
	invader2->Set2DPosition(-150, (float)Globals::screenHeight / 2 - 100);
	invader2->SetSize(70, 60);
	invader2->SetType("normal");
	invader2->SetLevelNormal(1);
	invader2->SetHP(2);
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
	
	//Init Sound
	
	gSoloud.init(); // Initialize SoLoud
	m_BGM.load("GSPlay_BGM.wav"); // Load BGM
	m_BGM.setLooping(true);
	m_BGM.setVolume(0.6f);

	m_hitsound.load("hitsound.wav"); // load bullet hitsound
	m_hitsound.setVolume(0.8f);

	m_invaderKilled.load("invaderkilled.wav"); // load invader kill sound
	
	s_playerShoot.load("shoot.wav");
	s_playerShoot.setVolume(0.6f);
	s_playerExplode.load("explosion.wav");
	s_playerExplode.setVolume(0.7f);
	gSoloud.play(m_BGM); // Play BGM
	
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
		case'L':
			m_keyPressed |= KEY_SPEED_UP;
			break;
		case'K':
			m_keyPressed |= KEY_SHOOT;
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
		case'L':
			m_keyPressed ^= KEY_SPEED_UP;
			break;
		case'K':
			m_keyPressed ^= KEY_SHOOT;
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

void GSPlay::Update(float deltaTime)
{
	// score
	auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	auto font = ResourceManagers::GetInstance()->GetFont("arcade.ttf");
	std::string s = "Score: " + std::to_string(m_scoreNum);
	m_score = std::make_shared< Text>(shader, font, s, TextColor::RED, 0.8);
	m_score->Set2DPosition((float)Globals::screenWidth/2 -100 , 50);
	

	//highscore
	ifstream myReadFile("highscore.txt");
	getline(myReadFile, m_highscoreNum);	

	//convert string highscore to int
	stringstream geek(m_highscoreNum);
	geek >> highScoreNum;
	
	//update highscore (cmp with surrent score)
	std::string s1 = "High Score: " + m_highscoreNum;
	m_highscore = std::make_shared< Text>(shader, font, s1, TextColor::WHITE, 0.8);
	m_highscore->Set2DPosition(20, 50);
	if (highScoreNum <= m_scoreNum) {
		ofstream myFile("highscore.txt");
		highScoreNum = m_scoreNum;
		myFile << std::to_string(highScoreNum);
		myFile.close();
	}
	
	//handle player's movement
	Vector3 currentPos = m_listPlayer[0]->GetPosition();
	if (m_keyPressed & KEY_MOVE_LEFT) {
		if (m_keyPressed & KEY_SPEED_UP) {
			if (currentPos.x >= 50)
				m_listPlayer[0]->Set2DPosition(Vector2(currentPos.x - 600 * deltaTime, currentPos.y));
		}
		else if (currentPos.x >= 50)
			m_listPlayer[0]->Set2DPosition(Vector2(currentPos.x - 300 * deltaTime, currentPos.y));
	}
	if (m_keyPressed & KEY_MOVE_RIGHT) {
		if (m_keyPressed & KEY_SPEED_UP) {
			if (currentPos.x <= (float)Globals::screenWidth - 50)
				m_listPlayer[0]->Set2DPosition(Vector2(currentPos.x + 600 * deltaTime, currentPos.y));
		}
		else if (currentPos.x <= (float)Globals::screenWidth - 50)
			m_listPlayer[0]->Set2DPosition(Vector2(currentPos.x + 300 * deltaTime, currentPos.y));
	}
	static float playerShootTime = 0;
	if (playerShootTime <= 0.5) playerShootTime += deltaTime;
	if (m_keyPressed & KEY_SHOOT) {		
		if (playerShootTime > 0.5) {
			gSoloud.play(s_playerShoot);
			m_listPlayer[0]->PlayerShootBullet();
			playerShootTime = 0;
		}
	}

	/*Class update*/
	//button
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	//player
	m_listPlayer[0]->Update(deltaTime);
	//player bullet interact
	for (auto k = 0; k < m_listInvaders.size(); k++) {
		//invader	
		m_listInvaders[k]->Update(deltaTime, m_listPlayer[0]->GetPosition());

		//invader drop bullets collision with player		
		for (auto i = 0; i < m_listInvaders[k]->m_listBullets.size(); i++) {
			float delta_x = m_listInvaders[k]->m_listBullets[i]->GetPosition().x - m_listPlayer[0]->GetPosition().x;
			float delta_y = m_listInvaders[k]->m_listBullets[i]->GetPosition().y - m_listPlayer[0]->GetPosition().y;
			if (abs(sqrt(delta_x * delta_x + delta_y * delta_y) < 20)) {
				m_listInvaders[k]->m_listBullets.erase(m_listInvaders[k]->m_listBullets.begin() + i);
				//GameOver when player get hit				
				isGameOver = true;
				// animate space ship explode
				auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
				auto texture = ResourceManagers::GetInstance()->GetTexture("explode.tga");
				auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
				auto m_animationExplode = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
				m_animationExplode->Set2DPosition(m_listPlayer[0]->GetPosition().x, m_listPlayer[0]->GetPosition().y);
				m_animationExplode->SetSize(100, 100);
				m_listAnimation.push_back(m_animationExplode);
			}
		}
		//invader curved bullets collision with player		
		for (auto i = 0; i < m_listInvaders[k]->m_listCurvedBullets.size(); i++) {
			float delta_x = m_listInvaders[k]->m_listCurvedBullets[i]->GetPosition().x - m_listPlayer[0]->GetPosition().x;
			float delta_y = m_listInvaders[k]->m_listCurvedBullets[i]->GetPosition().y - m_listPlayer[0]->GetPosition().y;
			if (abs(sqrt(delta_x * delta_x + delta_y * delta_y) < 20)) {
				m_listInvaders[k]->m_listCurvedBullets.erase(m_listInvaders[k]->m_listCurvedBullets.begin() + i);
				//GameOver when player get hit		
				isGameOver = true;
				// animate explode at player position
				auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
				auto texture = ResourceManagers::GetInstance()->GetTexture("explode.tga");
				auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
				auto m_animationExplode = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
				m_animationExplode->Set2DPosition(m_listPlayer[0]->GetPosition().x, m_listPlayer[0]->GetPosition().y);
				m_animationExplode->SetSize(100, 100);
				m_listAnimation.push_back(m_animationExplode);
				}
		}
		//invader boss collision with player bullet
		for (auto i = 0; i < m_listPlayer[0]->m_listPlayerBullets.size(); i++) {
			float delta_x = m_listPlayer[0]->m_listPlayerBullets[i]->GetPosition().x - m_listInvaders[k]->GetPosition().x;
			float delta_y = m_listPlayer[0]->m_listPlayerBullets[i]->GetPosition().y - m_listInvaders[k]->GetPosition().y;
			if (abs(sqrt(delta_x * delta_x + delta_y * delta_y) < 60) & m_listInvaders[k]->GetType() == "boss") {
				m_listInvaders[k]->SetHP(m_listInvaders[k]->GetHP() - 1);
				m_listPlayer[0]->m_listPlayerBullets.erase(m_listPlayer[0]->m_listPlayerBullets.begin() + i);
				
				gSoloud.play(m_hitsound); // Play hitsound
				if (m_listInvaders[k]->GetHP() == 0) {
					// animate explode at invader position
					auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
					auto texture = ResourceManagers::GetInstance()->GetTexture("explode.tga");
					auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
					auto m_animationExplode = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
					m_animationExplode->Set2DPosition(m_listInvaders[k]->GetPosition().x, m_listInvaders[k]->GetPosition().y);
					m_animationExplode->SetSize(100, 100);
					m_listAnimation.push_back(m_animationExplode);
					gSoloud.play(m_invaderKilled);
					// animate explode at invader's bullet position
					for (auto i1 = 0; i1 < m_listInvaders[k]->m_listCurvedBullets.size(); i1++) {
						auto m_animationExplode1 = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
						m_animationExplode1->Set2DPosition(m_listInvaders[k]->m_listCurvedBullets[i1]->GetPosition().x, m_listInvaders[k]->m_listCurvedBullets[i1]->GetPosition().y);
						m_animationExplode1->SetSize(100, 100);
						m_listAnimation.push_back(m_animationExplode1);
					}					
					//
					std::cout << "bullet kill boss invader" << "\n";
					m_scoreNum += 4;
					std::cout << m_scoreNum << "\n";					
					m_listInvaders.erase(m_listInvaders.begin() + k);
					m_levelboss += 1;					
					shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
					texture = ResourceManagers::GetInstance()->GetTexture("rsauce.tga");
					auto invader1 = std::make_shared<Invader>(model, shader, texture);
					invader1->Set2DPosition((float)Globals::screenWidth + 150, (float)Globals::screenHeight / 2 - 200);
					invader1->SetSize(70, 60);
					invader1->SetType("boss");
					invader1->SetLevelBoss(m_levelboss);
					invader1->SetHP(4);
					m_listInvaders.push_back(invader1);
					std::cout << "respawn boss" << "\n";
				}								
			}
		}
		//invader normal collision with player bullet
		for (auto i = 0; i < m_listPlayer[0]->m_listPlayerBullets.size(); i++) {
			float delta_x2 = m_listPlayer[0]->m_listPlayerBullets[i]->GetPosition().x - m_listInvaders[k]->GetPosition().x;
			float delta_y2 = m_listPlayer[0]->m_listPlayerBullets[i]->GetPosition().y - m_listInvaders[k]->GetPosition().y;
			if (abs(sqrt(delta_x2 * delta_x2 + delta_y2 * delta_y2) < 50) & m_listInvaders[k]->GetType() == "normal") {
				m_listInvaders[k]->SetHP(m_listInvaders[k]->GetHP() - 1);
				m_listPlayer[0]->m_listPlayerBullets.erase(m_listPlayer[0]->m_listPlayerBullets.begin() + i);
				
				gSoloud.play(m_hitsound); // Play hitsound
				if (m_listInvaders[k]->GetHP() == 0) {
					// animate explode at invader position
					auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
					auto texture = ResourceManagers::GetInstance()->GetTexture("explode.tga");
					auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
					auto m_animationExplode = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
					m_animationExplode->Set2DPosition(m_listInvaders[k]->GetPosition().x, m_listInvaders[k]->GetPosition().y);
					m_animationExplode->SetSize(100, 100);
					m_listAnimation.push_back(m_animationExplode);
					gSoloud.play(m_invaderKilled);
					// animate explode at invader's bullet position
					for (auto i1 = 0; i1 < m_listInvaders[k]->m_listBullets.size(); i1++) {
						auto m_animationExplode1 = std::make_shared<AnimationSprite>(model, shader, texture, 4, 0.2f);
						m_animationExplode1->Set2DPosition(m_listInvaders[k]->m_listBullets[i1]->GetPosition().x, m_listInvaders[k]->m_listBullets[i1]->GetPosition().y);
						m_animationExplode1->SetSize(100, 100);
						m_listAnimation.push_back(m_animationExplode1);
					}
					//
					std::cout << "bullet kill normal invader" << "\n";
					m_scoreNum += 2;
					std::cout << m_scoreNum << "\n";					
					m_listInvaders.erase(m_listInvaders.begin() + k);
					m_levelnormal += 1;
					shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
					texture = ResourceManagers::GetInstance()->GetTexture("bsauce.tga");
					auto invader2 = std::make_shared<Invader>(model, shader, texture);
					invader2->Set2DPosition(-150, (float)Globals::screenHeight / 2 - 100);
					invader2->SetSize(70, 60);
					invader2->SetType("normal");
					invader2->SetLevelNormal(m_levelnormal);
					invader2->SetHP(2);
					m_listInvaders.push_back(invader2);
					std::cout << "respawn normal" << "\n";
				}
			}
		}	
		
	}
	
	if (isGameOver == true) {
		gSoloud.play(s_playerExplode);
		auto texture = ResourceManagers::GetInstance()->GetTexture("transparent.tga");
		m_listPlayer[0]->SetTexture(texture);
		waitTime2 += deltaTime;
		if (waitTime2 >= 0.6) {
			gSoloud.deinit(); // Clean up sound!
			//change state and save score
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_GAMEOVER);
			ofstream myFile("score.txt");
			myFile << std::to_string(m_scoreNum);
			myFile.close();
		}
	}
	
	//parallelBG
	m_background->Update(deltaTime);
	
	//score update
	m_score->Update(deltaTime);
	m_highscore->Update(deltaTime);

	//animation list
	float animation_timer = 0;
	animation_timer += deltaTime;
	for (int i = 0; i < m_listAnimation.size(); i++) {
		m_listAnimation[i]->Update(deltaTime);
		if (animation_timer > 1) {
			m_listAnimation.erase(m_listAnimation.begin() + 0);
			animation_timer =0;
		}
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_listPlayer[0]->Draw();
	for (int i = 0; i < m_listAnimation.size(); i++) {
		m_listAnimation[i]->Draw();
	}
	for (int i = 0; i < m_listPlayer[0]->m_listPlayerBullets.size(); i++) {
		m_listPlayer[0]->m_listPlayerBullets[i]->Draw();
	}
	for (int i = 0; i < m_listInvaders.size(); i++) {
		m_listInvaders[i]->Draw();
		for (int i2 = 0; i2 < m_listInvaders[i]->m_listBullets.size(); i2++) {
			m_listInvaders[i]->m_listBullets[i2]->Draw();
		}
		for (int i3 = 0; i3 < m_listInvaders[i]->m_listCurvedBullets.size(); i3++) {
			m_listInvaders[i]->m_listCurvedBullets[i3]->Draw();
		}
	}
	m_score->Draw();
	m_highscore->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	
}