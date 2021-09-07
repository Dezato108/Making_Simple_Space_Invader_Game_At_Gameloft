#include "Bullet.h"


Bullet::Bullet(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
	: Sprite2D(model, shader, texture)
{
	active = true;
}

Bullet::~Bullet()
{
}

void Bullet::HitPlayer()
{
}

void Bullet::BulletDrop(float deltaTime,float DropSpeed)
{
	Set2DPosition(GetPosition().x, GetPosition().y + DropSpeed * 100 * deltaTime);
}

void Bullet::BulletFlyUp(float deltaTime)
{
	Set2DPosition(GetPosition().x, GetPosition().y - 600 * deltaTime);
}

void Bullet::Update(float deltaTime)
{
}

void Bullet::setTarget(Vector3 target)
{
	m_target = target;
}

bool Bullet::checkIsActive()
{
	if (GetPosition().y > 800 || GetPosition().y < -10) {
		active = false;
	}
	return active;
}

void Bullet::Move()
{
	float a = m_target.y - GetPosition().y;
	float b = GetPosition().x - m_target.x;
	if (a >= 0) vb = 1; else vb = -1;
	if (b >= 0) hb = -1; else hb = 1;
	SpeedBulletX = BulletSpeed * abs(b) / abs(sqrt(a * a + b * b));
	SpeedBulletY = BulletSpeed * abs(a) / abs(sqrt(a * a + b * b));
}

void Bullet::FlyToTarget(float deltaTime)
{
	Set2DPosition(GetPosition().x + SpeedBulletX * hb * deltaTime, GetPosition().y + SpeedBulletY * vb * deltaTime);
}


