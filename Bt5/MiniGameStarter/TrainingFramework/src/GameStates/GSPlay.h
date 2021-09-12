#pragma once
#include "GameStateBase.h"
#include "Player.h"
#include "Invader.h"
#include "Bullet.h"
#include "ParallelBG.h"
#include "AnimationSprite.h"
#include "soloud.h"
#include "soloud_wav.h"
#include <Application.h>

class Application;
class ParallelBG;
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class AnimationSprite;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	
private:
	std::shared_ptr<ParallelBG>	m_background;
	//std::shared_ptr<AnimationSprite>	m_coin;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Text>		m_highscore;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::vector<std::shared_ptr<Player>> m_listPlayer;
	std::vector<std::shared_ptr<Invader>> m_listInvaders;
	std::vector<std::shared_ptr<AnimationSprite>> m_listAnimation;
	static int m_keyPressed;
	int m_levelboss;
	int m_levelnormal;
	int m_scoreNum;
	std::string m_highscoreNum;
	int highScoreNum;
	bool isGameOver;
	float waitTime2;
	SoLoud::Soloud gSoloud; // SoLoud engine
	SoLoud::Wav m_BGM;      // BGM
	SoLoud::Wav m_hitsound;      // hitsound
	SoLoud::Wav m_invaderKilled;
	SoLoud::Wav s_playerShoot;
	SoLoud::Wav s_playerExplode;
};

