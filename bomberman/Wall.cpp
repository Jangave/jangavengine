/*
 * Wall.cpp
 *
 *  Created on: 2 de ago de 2015
 *      Author: juan
 */

#include "Wall.h"

#include "Types.h"

Wall::Wall(Position* position, Image* image, Body* shape) : Object(position, image, shape) {
	image->setColor(0.545, 0.271, 0.075);
	type *= WALL;
}

Wall::~Wall() {
}

