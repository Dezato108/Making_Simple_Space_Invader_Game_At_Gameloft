#pragma once
#include "Sprite2D.h"
#include "Bullet.h"

class Player :
    public Sprite2D
{
public:
    Player(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Player();
    void Update(float deltaTime);
    void PlayerShootBullet();
    //void Draw();
    std::vector<std::shared_ptr<Bullet>> m_listPlayerBullets;
private:
    
};

