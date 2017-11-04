/*
 * File:   Quad1.h
 * Project 4
 * some code may be copied and altered from
 * Triangle example
 * Code taken and altered from Unit6 Texture
 * Example
 *
 * Emma Theberge
 */
#ifndef Quad1_h
#define Quad1_h

/*************************
 *** GRAPHICS INCLUDES ***
 ************************/
#include <GL/glew.h>
#include "DrawableObject.h"
#include "Texture.hpp"
#include "Shader.hpp"
//#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <iostream>
#include <iomanip>
#include <stdio.h>

using glm::vec3;
using glm::vec4;

class Quad1//: public DrawableObject
{
public:
	Quad1();
	Quad1(vec3 _a, vec3 _b, vec3 _c, vec3 _d);
	void setFillColor(vec3 fC);
	void setBorderColor(vec3 bC);

	// The draw functions
	void draw(Shader*, Texture* = NULL);

	void setIsSelected(bool select);
	bool getIsSelected();

private:
	// Colors
	vec3 fillColor;
	vec3 borderColor;

	bool isSelected = true;

	//hold all four verticies of the quad
	vec3 a;
	vec3 b;
	vec3 c;
	vec3 d;

	GLuint VertexArrayObject;
	GLuint VertexBufferObject;
};
#endif /* Quad1_h */
