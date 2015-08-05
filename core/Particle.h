/*
 * Particle.h
 *
 *  Created on: 31 de jul de 2015
 *      Author: juan
 */

#ifndef CORE_OBJECTS_HEADERS_PARTICLE_H_
#define CORE_OBJECTS_HEADERS_PARTICLE_H_

#include "Drawable.h"
#include "Updateable.h"

class Image;

class Particle: public Updateable, public Drawable {
public:
	Particle(Position* position, Image* image, Ambient* ambient);
	virtual ~Particle();
};

#endif /* CORE_OBJECTS_HEADERS_PARTICLE_H_ */
