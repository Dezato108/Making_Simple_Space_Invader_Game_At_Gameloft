#pragma once
#include "Sprite2D.h"
#include "Bullet.h"
class Invader :
    public Sprite2D
{
public:
    Invader(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    ~Invader();
    
    std::shared_ptr<Bullet> Shoot_Single_Bullet();
    std::shared_ptr<Bullet> Shoot_A_Curved_Of_Bullet(Vector3 PlayerPosition);
    void SetLevelBoss(int level);
    void SetLevelNormal(int level);
    void Move(float deltaTime);
    void Move2(float deltaTime);
    void Update(float deltaTime, Vector3 PlayerPosition);
    void SetType(std::string type);
    void SetHP(int hp);
    int GetHP();
    std::string GetType();
    std::vector<std::shared_ptr<Bullet>> m_listBullets;
    std::vector<std::shared_ptr<Bullet>> m_listCurvedBullets;
private:
    std::string m_type;
    int m_hp;
    int m_levelboss;
    int m_levelnormal;
};

