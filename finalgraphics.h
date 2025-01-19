// This file was supplied by Prof. Marshall Long for ENAS 130 and has been
// updated in minor ways by Dr. Beth Anne Bennett.

#ifndef FINALGRAPHICS_H
#define FINALGRAPHICS_H

#include "classVertex.h"
#include "structPoly_classSolid.h"
#include <QPainter>
#include <QPixmap>
#include <QApplication>
#include <ctime>
#include <cmath> // needed for fabs() in getAxis()

/*
Define graphics functions as follows:

void plotOn(int height, int width)   Open a window of specified size (in pixels).

void xScale(float xmin, float xmax)  Scale the window's x-axis.

void yScale(float ymin, float ymax)  Scale the window's y-axis.

void setPen(float x, float y)        Place the pen at location (x,y).

void drawLineSeg(float x, float y)   Draw a line segment to location (x,y).
                                     Leave the pen at location (x,y).

void drawCross(float x, float y)     Draw a cross at location (x,y).
                                     Leave the pen at location (x,y).

void drawPoly(Vertex* verticesToDraw, int numVertices, int fillColor, float intensity)
              Draw a polygon.
              verticesToDraw is an array containing at least numVertices Vertex objects.
              numVertices is between 3 and 10, inclusive.
              fillColor is -1 (no fill), 0 (grey), 1 (red), 2 (green), 3 (blue), or 4 (purple).
              intensity is between 0. and 1., inclusive.

void drawRect(float x0, float y0, float x1, float y1, int fillColor, float intensity)
              Draw a rectangle with opposite corners (x0,y0) and (x1,y1).
              fillColor is -1 (no fill), 0 (grey), 1 (red), 2 (green), 3 (blue), or 4 (purple).
              intensity is between 0. and 1., inclusive.

void clear()              Erase everything in the window.

void updateImage()        Update the image with everything that has been drawn so far.

void delay(int centisecs) Delay for the specified number of hundredths of seconds.

int getMouse(float *px, float *py, int *pdrag)
              Get the xy coordinates of a mouse click.
              Scaling is as per xScale and yScale calls.
              Return value is the number of the button pressed or dragged.
              Values are 1 (LEFT_BUTTON), 2 (CENTER_BUTTON), or 3 (RIGHT_BUTTON).

int neitherRightClickNorRightDrag()  Return 1 unless the right mouse button has been
                                     clicked or dragged, in which case return 0.

int getAxis(int *paxis, float *pdir)
              Respond to mouse movement and provide info on how solid object should rotate.
              1st arg returns 1 or 2 (rotation about X or Y axis).
              2nd arg returns 1 or -1, indicating the direction of rotation.
              Return value is 1 unless the mouse has been clicked or dragged in the lower
                  left corner of the graphics window.
*/

enum {NO_BUTTON, LEFT_BUTTON, CENTER_BUTTON, RIGHT_BUTTON,
                 LEFT_MOVING, CENTER_MOVING, RIGHT_MOVING};

enum Color {GREY, RED, GREEN, BLUE, PURPLE};

enum {X=1, Y, Z};

void plotOn(int, int);
void xScale(float, float);
void yScale(float, float);
void setPen(float, float);
void drawLineSeg(float, float);
void drawLine(int x0, int y0, int x1, int y1);
void drawCross(float, float);
void drawPoly(Vertex* verticesToDraw, int numVertices, int fillColor, float intensity);
void drawRect(float x0, float y0, float x1, float y1, int fillColor, float intensity);
void clear();
void updateImage();
void delay(int centisecs);
int getMouse(float *px, float *py, int *notdone);
int neitherRightClickNorRightDrag();
QPoint screenCoord(Vertex p);
void getColors();
int getAxis(int *paxis, float *pdir);

#endif // FINALGRAPHICS_H

