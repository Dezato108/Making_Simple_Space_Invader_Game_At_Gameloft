#pragma once
#include "Sprite2D.h"

class Invaders : public Sprite2D{
public:
	Invaders(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
	~Invaders();
	/*void Init();
	void Update();
	void Draw();*/
	void changePos(GLfloat deltaTime);
private:	
	int m_timeline=0;
};