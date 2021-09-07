#pragma once
#include "Sprite2D.h"
#include "BaseObject.h"
class ParallelBG : BaseObject
{
public:
	ParallelBG();
	ParallelBG(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, GLfloat speed);

	void	Init() override;
	void	Update(GLfloat deltaTime) override;
	void	Draw() override;

protected:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>	m_background1;
	GLfloat m_time;
	GLfloat m_speed;
};

