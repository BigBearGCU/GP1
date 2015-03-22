#include "cBullet.h"
#include "cShip.h"
#include "cGame.h"

cBullet::cBullet(cTexture *pText, Owner pOwner, int pDamage) : 
	cGameObject(pText, pOwner)
{
	damage = pDamage; 
	cGame::Get()->PlaySnd("bullet");
}

void cBullet::Update(float delta)
{
	if (destroy)
		return;

	currentLife -= delta;
	if (currentLife < 0)
		destroy = true;

	cGameObject::Update(delta);
}

void cBullet::CollidedWith(cGameObject *col)
{
	if (!dynamic_cast<cBullet*>(col))
		destroy = true;
	if (cShip *ship = dynamic_cast<cShip*>(col))
		ship->ApplyDamage(damage);
}