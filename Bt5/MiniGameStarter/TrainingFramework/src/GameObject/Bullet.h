#pragma once
#include "Sprite2D.h"

class Bullet :
    public Sprite2D
{
public :
    Bullet(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Bullet();
    void HitPlayer();
    void BulletDrop(float deltaTime, float DropSpeed);
    void BulletFlyUp(float deltaTime);
    void Update(float deltaTime);
    void setTarget(Vector3 target);
    bool checkIsActive();
    void Move();
    void FlyToTarget(float deltaTime);
private:
    Vector3 m_target;
    int hb, vb;
    const int BulletSpeed = 200;
    float SpeedBulletX, SpeedBulletY;
    bool active;
    
};

