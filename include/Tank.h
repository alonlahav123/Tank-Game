#pragma once
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<string>
#include "BGraphic.h"
#include"Bullet.h"
#include"Coin.h"
#include<thread>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace sf;


const Color NoColor = Color(0, 0, 0, 0);
class Tank {
	Texture aTexture;
	BSprite*spTank;
	BSize tankSize;
	direction tankFace = top;
	int nHp = 100;
	int nDamage;
	int nSpeed;
        unsigned int score = 0;
        sf::RectangleShape tankBox;
	BLine trajectory;
	bool isMoving;
	Clock aClock;
	Texture fireTexture;
	BPoint ptMouth = BPoint(0, 0);
	std::string tankPath = "images/Ntank1.png";
	std::string damageSoundPath = "sounds/attacked.wav";
	std::string fireSoundPath = "sounds/fire.wav";
	std::string moveSoundPath = "sounds/moving.wav";
	std::string explSoundPath = "sounds/Explosion.wav";
	bool gameOver = false;
	bool MvThreadEnd = false;
	BSound * sdExplosion = nullptr;
	BSound * sdFire = nullptr;
	BSound * sdDamaged = nullptr;
	BSound * sdMoving = nullptr;
	//std::thread animatedThread;
	std::thread * moveThread;

public:
	bool getisMoving() { return isMoving; };// start moving
	int getHp() { return nHp; }
        unsigned int getScore() { return score; }
	BPoint getPtMouth() { return spTank->getPeakPoint(); }// return tank's muzzle point
	BSprite* getSpTank() { return spTank; }
	void setGameOver();
	Tank(BPoint pt, direction dc, BSize size, Color aColor);
	bool isContainItems(BPoint pt = BPoint(0, 0), std::vector<BPoint>vPoint = {});
	//return tank's muzzle, peak left and peak right
	std::vector<BPoint>getFrontPoints();
	//return tank's top left point
	BPoint getTopLeft();
	void MOVE();
	void fire(std::vector<Bullet*>&bList);
	// get damage
	void damaged(int damage);
        //score functions
        void addScore(unsigned int);
        bool isCollidingWithCoin(Coin*);
  //sf::FloatRect getGlobalBounds();
	void eat() {};// eating bonus
	//start moving
	void move();
	void switchDirection(direction newDic);
	void stop();
	~Tank();
};
