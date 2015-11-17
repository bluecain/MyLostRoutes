//
//  Bullet.cpp
//  Created by tonyguan on 13-12-11.
//
//

#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::createWithSpriteFrameName(const char* spriteFrameName)
{
	Bullet *bullet = new Bullet();
	if (bullet && bullet->initWithSpriteFrameName(spriteFrameName)) {
		bullet->autorelease();
		bullet->setVisible(false);  //子弹刚刚创建的时候是不可见的

		auto body = PhysicsBody::createBox(bullet->getContentSize());  //创造bullet大小的受物理影响的刚体

		body->setCategoryBitmask(0x01);			//0001
		body->setCollisionBitmask(0x02);		//0010  碰撞分组掩码
		body->setContactTestBitmask(0x01);  //接触分组掩码

		bullet->setPhysicsBody(body);  //附着刚体于bullet精灵上

		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return nullptr;
}

void Bullet::shootBulletFromFighter(Fighter* fighter)
{
	this->setPosition(fighter->getPosition() + Vec2(0, fighter->getContentSize().height/2));
	this->setVisible(true);
	this->unscheduleUpdate();
	this->scheduleUpdate();

}

void Bullet::update(float dt)
{
	Size screenSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(this->getPosition() + velocity *dt));
	if (this->getPosition().y > screenSize.height) {
		//log("isVisible = %d",this->isVisible());
		this->setVisible(false);
		this->unscheduleUpdate();
		this->removeFromParent();
	}    
}