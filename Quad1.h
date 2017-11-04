/*
 * File:   Quad1.h
 * Project 4
 * some code may be copied and altered from
 * Triangle example
 * Code taken and altered from Unit6 Texture and unit 7 lighting
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
#include <glm/glm.hpp>
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include "Triangle.hpp"
#include "Texture.hpp"
#include "Vertex.hpp"
#include "Shader.hpp"
//#include <glm/gtc/matrix_transform.hpp>

using glm::vec3;
using glm::vec4;

class Quad1
{
public:
	Quad1();
	Quad1(Vertex* _a, Vertex* _b, Vertex* _c, Vertex* _d);
	Quad1(const Quad1& orig);
	
	void setFillColor(vec3 fC);
	void setBorderColor(vec3 bC);
	
	// Calculate the normal
	void calculateNormal();

	// The draw functions
	void draw(Shader*, Texture* = NULL);

	virtual ~Quad1();
	
	// Getters and Setters
    vec3 getNormal1() { return normal1; }
	vec3 getNormal2() { return normal2; }
	
    Vertex* getVa() { return va; }
    Vertex* getVb() { return vb; }
    Vertex* getVc() { return vc; }
	Vertex* getVd() { return vd; }
private:
	// Colors
	vec3 fillColor;
	vec3 borderColor;

	//hold all four verticies of the quad
	Vertex* a;
	Vertex* b;
	Vertex* c;
	Vertex* d;
	
	vec3 normal1;
	vec3 normal2;

	GLuint VertexArrayObject;
	GLuint VertexBufferObject;
};
#endif /* Quad1_h */
