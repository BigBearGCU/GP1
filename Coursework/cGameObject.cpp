#include "cGameObject.h"

void cGameObject::Update(float delta)
{
	if (destroy)
		return;

	float angleDelta = targetRot - sprite->getSpriteRotation();
	if (glm::abs(angleDelta) > 180)
		angleDelta = (360 - glm::abs(angleDelta)) * -glm::sign(angleDelta);
	angleDelta = glm::clamp(angleDelta, -rotSpeed, rotSpeed);
	sprite->setSpriteRotation(sprite->getSpriteRotation() + angleDelta * delta);

	if (glm::abs(velocity.length()) <= 1)
		velocity = glm::vec2(0, 0);
	else
	{
		velocity.x = glm::clamp(velocity.x, -maxVel, maxVel);
		velocity.y = glm::clamp(velocity.y, -maxVel, maxVel);

		glm::vec2 pos = sprite->getSpritePos();
		pos += ((velocity.x * forward) + (velocity.y * GetRight())) * delta;
		sprite->setSpritePos(pos);
	}

	sprite->updateMatrix();
	sprite->updateBoundingRect();
	UpdateForward();
}

void cGameObject::Render()
{
	sprite->render();
}

void cGameObject::LookAt(glm::vec2 target)
{
	glm::vec2 n = target - sprite->getSpritePos();
	float angle = glm::degrees(glm::atan(n.y, n.x));
	targetRot = angle + 90;
}

void cGameObject::UpdateForward()
{
	forward = glm::rotate(glm::vec2(0, -1), sprite->getSpriteRotation());
}

void cGameObject::CollidedWith(cGameObject *col)
{
	cout << typeid(this).name() << " collided with " << typeid(col).name() << endl;
}