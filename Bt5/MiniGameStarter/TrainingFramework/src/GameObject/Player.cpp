#include "Player.h"
#include "ResourceManagers.h"

Player::Player(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{
}
Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	//class update
	for (int i = 0; i < m_listPlayerBullets.size(); i++) {
		m_listPlayerBullets[i]->BulletFlyUp(deltaTime);
		if (m_listPlayerBullets[i]->checkIsActive() == false) {
			m_listPlayerBullets.erase(m_listPlayerBullets.begin() + i);
		}
		//std::cout << m_listPlayerBullets.size() << "\n";
	}
}

void Player::PlayerShootBullet()
{
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("b0.tga");
	auto bullet = std::make_shared<Bullet>(model, shader, texture);
	bullet->Set2DPosition(GetPosition().x, GetPosition().y);
	bullet->SetSize(10, 20);
	m_listPlayerBullets.push_back(bullet);
	
	
}


