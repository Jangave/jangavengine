/*
 * Fire.cpp
 *
 *  Created on: 2 de ago de 2015
 *      Author: juan
 */

#include "Fire.h"

#include <GLFW/glfw3.h>

#include "../core/Ambient.h"
#include "../core/Body.h"
#include "../core/Image.h"
#include "../core/Map.h"
#include "../core/Object.h"
#include "../core/Position.h"
#include "../core/Types.h"
#include "Bomb.h"
#include "Types.h"

Fire::Fire(Position* p, Ambient* ambient) : Entity(p, new Image(), new Body(), ambient) {
	int u = ambient->getMap()->getUnit();
	position->setX(position->getX() / u * u);// + u/4);
	position->setY(position->getY() / u * u);// + u/4);

	image->setHeight(u);///2);
	image->setWidth(u);///2);
	image->setColor(1, 1, 0);

	shape->setSizeX(u);///2);
	shape->setSizeY(u);///2);

	initTime = glfwGetTime();

	type *= FIRE;
}

Fire::~Fire() {
}

void Fire::update() {
	if(glfwGetTime() - initTime > 1){
		ambient->removeEntity(this);
	}
}

void Fire::onCollide(Tangible* t) {
	if(t->type % FIRE)
	{
		if(t->type % OBJECT == 0){
			ambient->removeObject((Object*)t);
			ambient->removeEntity(this);
		}
		if(t->type%BOMB == 0){
			((Bomb*)t)->explode();
		}
	}

}
