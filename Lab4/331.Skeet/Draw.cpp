
#include "Draw.h"

/************************************************************************
 * DRAW Background
 * Fill in the background
 *  INPUT color   Background color
 *************************************************************************/
void Draw::drawBackground(double redBack, double greenBack, double blueBack) const
{
	glBegin(GL_TRIANGLE_FAN);

	// two rectangles is the fastest way to fill the screen.
	glColor3f((GLfloat)redBack /* red % */, (GLfloat)greenBack /* green % */, (GLfloat)blueBack /* blue % */);
	glVertex2f((GLfloat)0.0, (GLfloat)0.0);
	glVertex2f((GLfloat)dimensions.getX(), (GLfloat)0.0);
	glVertex2f((GLfloat)dimensions.getX(), (GLfloat)dimensions.getY());
	glVertex2f((GLfloat)0.0, (GLfloat)dimensions.getY());

	glEnd();
}

/************************************************************************
 * DRAW Timer
 * Draw a large timer on the screen
 *  INPUT percent     Amount of time left
 *        Foreground  Foreground color
 *        Background  Background color
 *************************************************************************/
void Draw::drawTimer(double percent,
    double redFore, double greenFore, double blueFore,
    double redBack, double greenBack, double blueBack) const
{
    double radians;

    GLfloat length = (GLfloat)dimensions.getX();
    GLfloat half = length / (GLfloat)2.0;

    // do the background stuff
    drawBackground(redBack, greenBack, blueBack);

    // foreground stuff
    radians = percent * M_PI * 2.0;
    GLfloat x_extent = half + length * (GLfloat)sin(radians);
    GLfloat y_extent = half + length * (GLfloat)cos(radians);

    // get read to draw the triangles
    glBegin(GL_TRIANGLE_FAN);
    glColor3f((GLfloat)redFore /* red % */, (GLfloat)greenFore /* green % */, (GLfloat)blueFore /* blue % */);
    glVertex2f(half, half);

    // fill in the triangles, one eight at a time
    switch ((int)(percent * 8.0))
    {
    case 7: // 315 - 360
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, length);
        break;
    case 6: // 270 - 315
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, half);
        break;
    case 5: // 225 - 270
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(0.0, 0.0);
        break;
    case 4: // 180 - 225
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, 0.0);
        glVertex2f(half, 0.0);
        break;
    case 3: // 135 - 180
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, half);
        glVertex2f(length, 0.0);
        break;
    case 2: // 90 - 135 degrees
        glVertex2f(half, length);
        glVertex2f(length, length);
        glVertex2f(length, half);
        break;
    case 1: // 45 - 90 degrees
        glVertex2f(half, length);
        glVertex2f(length, length);
        break;
    case 0: // 0 - 45 degrees
        glVertex2f(half, length);
        break;
    }
    glVertex2f(x_extent, y_extent);

    // complete drawing
    glEnd();

    // draw the red line now
    glBegin(GL_LINES);
    glColor3f((GLfloat)0.6, (GLfloat)0.0, (GLfloat)0.0);
    glVertex2f(half, half);
    glVertex2f(x_extent, y_extent);
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);
    glEnd();
}

/*************************************************************************
 * DRAW TEXT
 * Draw text using a simple bitmap font
 *   INPUT  topLeft   The top left corner of the text
 *          text      The text to be displayed
 ************************************************************************/
void Draw::drawText(const Point& topLeft, const char* text)
{
    void* pFont = GLUT_TEXT;
    glColor3f((GLfloat)1.0 /* red % */, (GLfloat)1.0 /* green % */, (GLfloat)1.0 /* blue % */);

    // prepare to output the text from the top-left corner
    glRasterPos2f((GLfloat)topLeft.getX(), (GLfloat)topLeft.getY());

    // loop through the text
    for (const char* p = text; *p; p++)
        glutBitmapCharacter(pFont, *p);
}
void Draw::drawText(const Point& topLeft, const string& text)
{
    drawText(topLeft, text.c_str());
}