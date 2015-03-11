#pragma once

#include <Windows.h>
#include "glm\glm.hpp"
#include "cTexture.h"
#include "cGUI.h"
#include "cPlayer.h"
#include "cBackground.h"

class cGame
{
private:
	cGame();
	static cGame *singleton;

	cGUI *gui;
	cBackground *background;
	bool paused;
	cPlayer *player = NULL;
	vector<cGameObject*> gameObjects;
	vector<cGameObject*> objctsToDelete;
	map<string, cTexture*> textures;
	int score = 0;

	bool PerPixelCollision(cGameObject* g1, cGameObject* g2);
	void LoadTextures();

public:
	~cGame();
	static cGame* Get() { if (!singleton) singleton = new cGame(); return singleton; }

	int GetScore() { return score; }
	void AddScore(int delta) { score += delta; }

	void Update(float delta);
	void CollisionUpdate(); //Implement this - http://gamedevelopment.tutsplus.com/tutorials/quick-tip-use-quadtrees-to-detect-likely-collisions-in-2d-space--gamedev-374
	void Render();
	void AddGameObject(cGameObject *obj) { gameObjects.push_back(obj); }
	cGameObject* ClickedOn(glm::vec2 pos);
	void StartLevel(int level);
	cPlayer* GetPlayer() { return player; };
	void SetPaused(bool state) { paused = state; }
	void Clear();
	int GetGameObjetsCount() { return gameObjects.size(); }
	void OnResize(int width, int height);
};