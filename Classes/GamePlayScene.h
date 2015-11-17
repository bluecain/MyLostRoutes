
#ifndef __GAME_PLAY_SCENE_H__
#define __GAME_PLAY_SCENE_H__

#define GameSceneNodeTagStatusBarFighterNode		301
#define GameSceneNodeTagStatusBarLifeNode			302
#define GameSceneNodeTagStatusBarScore				303

#define GameSceneNodeBatchTagBackground				800
#define GameSceneNodeTagFighter						900
#define GameSceneNodeTagExplosionParticleSystem		901
#define GameSceneNodeBatchTagBullet					902
#define GameSceneNodeBatchTagEnemy					903

//发射炮弹的速度
#define GameSceneBulletVelocity						300

#include "cocos2d.h"
#include "Enemy.h"
#include "Fighter.h"
#include "Bullet.h"
#include "GameOverScene.h"

#include "SystemHeader.h"

//定义 击毁敌人获得的分数.
typedef enum
{
	EnemyStone_Score = 5,
	Enemy1_Score = 10,
	Enemy2_Score = 15,
	EnemyPlanet_Score = 20
} EnemyScores;


class GamePlayLayer : public cocos2d::Layer
{
private:

	Fighter* fighter;	//飞机
	cocos2d::Menu* menu;  //菜单
	int score;  //分数
	int scorePlaceholder;  //记录0~999分数
	cocos2d::EventListenerTouchOneByOne *touchFighterlistener;  //触摸listener
	cocos2d::EventListenerPhysicsContact *contactListener;  //物理listener（这个不太熟悉）

public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();

	//发射一枚炮弹.
	void shootBullet(float dt);

	//初始化背景.
	void initBG();

	//在状态栏中设置和更新玩家的生命值.
	void updateStatusBarFighter();

	//在状态栏中更新得分.
	void updateStatusBarScore();

	//按钮的回调函数
	void menuPauseCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);
	void menuResumeCallback(cocos2d::Ref* pSender);

	//处理玩家与敌人的碰撞检测
	void handleFighterCollidingWithEnemy(Enemy* enemy);

	//处理子弹与敌人的碰撞检测
	void handleBulletCollidingWithEnemy(Enemy* enemy);

	CREATE_FUNC(GamePlayLayer);
};

#endif // __GAME_PLAY_SCENE_H__
