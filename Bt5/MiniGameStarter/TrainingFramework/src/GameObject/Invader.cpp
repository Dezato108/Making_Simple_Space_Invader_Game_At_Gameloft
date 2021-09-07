#include "Invader.h"
#include "ResourceManagers.h"

Invader::Invader(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture), m_levelboss(1), m_levelnormal(1)
{
}

Invader::~Invader()
{
}

std::shared_ptr<Bullet> Invader::Shoot_Single_Bullet()
{
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("b0.tga");
	auto bullet = std::make_shared<Bullet>(model, shader, texture);
	bullet->Set2DPosition(GetPosition().x, GetPosition().y+10);
	bullet->SetSize(10, 30);
	return bullet;
}

std::shared_ptr<Bullet> Invader::Shoot_A_Curved_Of_Bullet(Vector3 target)
{
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("b0.tga");
	auto bullet = std::make_shared<Bullet>(model, shader, texture);
	bullet->Set2DPosition(GetPosition().x, GetPosition().y+10);
	bullet->SetSize(10, 10);
	bullet->setTarget(target);
	bullet->Move();
	return bullet;
}

void Invader::SetLevelNormal(int level)
{
	m_levelnormal = level;
}

void Invader::SetLevelBoss(int level)
{
	m_levelboss = level;
}

void Invader::Move(float deltaTime)
{
	static bool moveRight = true;
	/*if (GetPosition().y < (float)Globals::screenHeight / 2 - 200) {
		Set2DPosition(GetPosition().x , GetPosition().y - 100 * deltaTime);
	}*/
	if (GetPosition().x < 49) {
		Set2DPosition(GetPosition().x + 100 * deltaTime, GetPosition().y);
	}
	if (GetPosition().x >1150) moveRight = false;
	else if(GetPosition().x < 50) moveRight = true;

	if (moveRight) {
		Set2DPosition(GetPosition().x + 80 * m_levelboss * deltaTime, GetPosition().y);		
	}
	else {
		Set2DPosition(GetPosition().x - 80 * m_levelboss * deltaTime, GetPosition().y);
	}
}

void Invader::Move2(float deltaTime)
{
	/*if (GetPosition().y < (float)Globals::screenHeight / 2 - 100) {
		Set2DPosition(GetPosition().x, GetPosition().y - 100 * deltaTime);
	}*/
	static bool moveRight = true;
	if (GetPosition().x > 1151) {
		Set2DPosition(GetPosition().x - 100 * deltaTime, GetPosition().y);
	}
	if (GetPosition().x > 1150) moveRight = false;
	else if (GetPosition().x < 50) moveRight = true;

	if (moveRight) {
		Set2DPosition(GetPosition().x + 50 * m_levelnormal * deltaTime, GetPosition().y);
	}
	else {
		Set2DPosition(GetPosition().x - 50 * m_levelnormal * deltaTime, GetPosition().y);
	}
}

void Invader::Update(float deltaTime, Vector3 PlayerPosition)
{	
	if (m_type == "boss") Move(deltaTime);
	if (m_type == "normal") Move2(deltaTime);
	static float m_SingleBulletTime = 0;
	static float m_CurvedBulletTime = 0;
	m_SingleBulletTime += deltaTime;
	m_CurvedBulletTime += deltaTime;
	if (m_SingleBulletTime > 1.0f) {
		if (m_type == "normal") {	
				m_listBullets.push_back(Shoot_Single_Bullet());			
		}		
		m_SingleBulletTime = 0;
	}

	if (m_CurvedBulletTime > 1.5f) {	
		if (m_type == "boss")
			for (int i = 0; i < m_levelboss; i++) {				
			Vector3 target(PlayerPosition.x + 25 * (i-(m_levelboss/2)), PlayerPosition.y,0);
			m_listCurvedBullets.push_back(Shoot_A_Curved_Of_Bullet(target));				
			}
		m_CurvedBulletTime = 0;
	}

	//Class update
	for (int i = 0; i < m_listBullets.size(); i++) {
		m_listBullets[i]->BulletDrop(deltaTime, m_levelnormal);
		if (m_listBullets[i]->checkIsActive() == false) {
			m_listBullets.erase(m_listBullets.begin() + i);
		}		
	}
	for (int i = 0; i < m_listCurvedBullets.size(); i++) {			
		m_listCurvedBullets[i]->FlyToTarget(deltaTime);
		if (m_listCurvedBullets[i]->checkIsActive()==false) {
			m_listCurvedBullets.erase(m_listCurvedBullets.begin() + i);
		}
	}
}

void Invader::SetType(std::string type)
{
	m_type = type;
}

void Invader::SetHP(int hp)
{
	m_hp = hp;
}

int Invader::GetHP()
{
	return m_hp;
}

std::string Invader::GetType()
{
	return m_type;
}
