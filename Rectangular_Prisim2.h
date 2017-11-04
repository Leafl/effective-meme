/* 
 * File:   Rectangular_Prisim2.h
 * Author: Suzuka
 *
 * Created on Ocotober 4, 2017
 *
 *  Recycled and revised/edidted StuetzleC's Cube
 */

#ifndef RECTANGULAR_PRISIM2_H
#define RECTANGULAR_PRISIM2_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <stdio.h>

#include "Rectangular_Prisim2.h"
#include "DrawableObject.h"
#include "Triangle.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "Vertex.hpp"

using glm::vec3;
class Triangle;

class Rectangular_Prisim2 : public DrawableObject {
public:
    Rectangular_Prisim2();
    Rectangular_Prisim2(vec3 _f, double _length, double _width, double _depth, vec3 fill, vec3 border, Texture* tex = NULL);
    Rectangular_Prisim2(const Rectangular_Prisim2& orig);
    virtual ~Rectangular_Prisim2();

    // The draw function
    void draw(Shader*);

    //vec3 getEyeDirection(Camera*, int vertNum = 0 );
private:
	void initalizeRemainingPoints(vec3 _f, double _length, double _width, double _depth);
	
    Triangle* triangles[12];
    Vertex* vertices[8];
    double length;
	double width;
	double depth;

    // Colors
    vec3 fillColor;
    vec3 borderColor;

    // Set up the vertex buffer object and vertex array object
    GLuint rect_pris2_VertexArrayObject;
    GLuint rect_pris2_VertexBufferObject;
};

#endif /* RECTANGULAR_PRISIM2_H */

