#pragma once
#include "GameStateBase.h"
#include "ResourceManagers.h"
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;

class GSGameOver :
	public GameStateBase
{
public:
	GSGameOver();
	~GSGameOver();

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
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>	m_imageGameOver;
	std::shared_ptr<Text>		m_text1;
	std::shared_ptr<Text>		m_text2;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::string m_scoreNum;
	std::string m_highScoreNum;
};

