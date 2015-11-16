
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

//�����ڵ����ٶ�
#define GameSceneBulletVelocity						300

#include "cocos2d.h"
#include "Enemy.h"
#include "Fighter.h"
#include "Bullet.h"
#include "GameOverScene.h"

#include "SystemHeader.h"

//���� ���ٵ��˻�õķ���.
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

	Fighter* fighter;	//�ɻ�
	cocos2d::Menu* menu;  //�˵�
	int score;  //����
	int scorePlaceholder;  //��¼0~999����
	cocos2d::EventListenerTouchOneByOne *touchFighterlistener;  //����listener
	cocos2d::EventListenerPhysicsContact *contactListener;  //����listener�������̫��Ϥ��

public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void onEnter();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();

	//�����ڵ�.
	void shootBullet(float dt);

	//��ʼ������.
	void initBG();

	//��״̬�������ú͸�����ҵ�����ֵ.
	void updateStatusBarFighter();

	//��״̬���и��µ÷�.
	void updateStatusBarScore();

	//��ť�Ļص�����
	void menuPauseCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);
	void menuResumeCallback(cocos2d::Ref* pSender);

	//�����������˵���ײ���
	void handleFighterCollidingWithEnemy(Enemy* enemy);

	//�����ӵ�����˵���ײ���
	void handleBulletCollidingWithEnemy(Enemy* enemy);

	CREATE_FUNC(GamePlayLayer);
};

#endif // __GAME_PLAY_SCENE_H__