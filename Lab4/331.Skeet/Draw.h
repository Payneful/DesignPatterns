#pragma once
#include "point.h"
#include "skeet.h"
#include <string>
#include <sstream>

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_18
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#define GLUT_TEXT GLUT_BITMAP_HELVETICA_12
#endif // _WIN32

class Draw {
public:
	void drawBackground(double redBack, double greenBack, double blueBack) const;
	void drawTimer(double percent,
		double redFore, double greenFore, double blueFore,
		double redBack, double greenBack, double blueBack) const;
	void drawText(const Point& topLeft, const char* text);
	void drawText(const Point& topLeft, const string& text);
};