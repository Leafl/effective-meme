/*
 * File:   Quad1.cpp
 * Project 4
 * some code may be copied and altered from
 * Triangle
 *
 * Quad1 -- uses triangle fan (such that point a is the
 * centeral point and all other verticies have one edge
 * steming from vertex a
 *
 * Emma Theberge
 */

#include "Quad1.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>

Quad1::Quad1()
{
	assert(false&&"Do not use default quad constructor.");
}
//
Quad1::Quad1(vec3 _a, vec3 _b, vec3 _c, vec3 _d)
{
	a=_a;
	b=_b;
	c=_c;
	d=_d;

	GLfloat verticies[]=
	{
		a.x, a.y, a.z,
		b.x, b.y, b.z,
		c.x, c.y, c.z,
		d.x, d.y, d.z,
	};

	GLfloat tex_coordinates[]=
	{
		0.0f, 0.0f,		//a
		0.0f, 1.0f,		//b
		1.0f, 1.0f,		//c
		1.0f, 0.0f		//d
	};

	// Set up the VertexBufferObject
	glGenVertexArrays(1, &VertexArrayObject);
	glGenBuffers(1, &VertexBufferObject);
	glBindVertexArray(VertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBufferObject);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies) + sizeof(tex_coordinates), NULL, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(verticies),verticies);

	glBufferSubData(GL_ARRAY_BUFFER, sizeof (verticies), sizeof (tex_coordinates), tex_coordinates);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*) sizeof(verticies));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

void Quad1::setFillColor(vec3 fC)
{
	fillColor=fC;
}

void Quad1::setBorderColor(vec3 bC)
{
	borderColor=bC;
}

void Quad1::setIsSelected(bool select)
{
	isSelected=select;
}

bool Quad1::getIsSelected()
{
	return isSelected;
}

void Quad1::draw(Shader *s,Texture* tex)
{
	glBindVertexArray(VertexArrayObject);
	s->useProgram();
	GLint c=s -> GetVariable("color");

	if (tex==NULL)
	{
		// Make the color the fill color
		GLint c=s -> GetVariable("color");
		s -> SetVector3(c, 1, &fillColor[0]);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}
	else if (tex!=NULL)
	{
		glBindTexture(GL_TEXTURE_2D, tex->getTexID());
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}


	if (getIsSelected()==true)
	{
		// Switch to border color for the outline
		s -> SetVector3(c, 1, &borderColor[0]);
		//glDrawArrays(GL_LINE_LOOP, 0, 4);
		glDrawArrays(GL_POINTS, 0, 4);
	}
	glBindVertexArray(0);
}
