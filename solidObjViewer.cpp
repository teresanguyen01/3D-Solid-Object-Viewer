// This file is based on a file supplied by Prof. Marshall Long for ENAS 130.

#include <QApplication>
#include "classVertex.h"
#include "structPoly_classSolid.h"
#include "finalgraphics.h"
#include "finalgraphicswindow.h"
#include <iostream>
#include <fstream>
#include <cmath>

#define FILENAMEMAX 256

using namespace std;

// Global variables
QApplication *a2;
GraphicsWindow *w2;
const float pi = 4.*atan(1.);

// This code implements a Solid Object Viewer that draws three-dimensional
// objects on the computer screen.  After the user chooses one of six solid
// objects (and a rotation speed), a geometrical description of this object is
// read from an input file, which includes information about the vertices and
// polygons that comprise the object's surface.  The code then opens a graphics
// window, projects the solid object from three dimensions to two, and draws it
// in the graphics window using polygons filled with appropriate colors.  The
// user can rotate the object by dragging the mouse.  When the user clicks
// (with any mouse button) in the lower left corner of the graphics window, the
// code stops.

int main(int argc, char *argv[])
{
    // Application and graphics initialization
    QApplication a(argc, argv); // QApplication is a class.
    GraphicsWindow w;           // GraphicsWindow is a class.
    a2 = &a;
    w2 = &w;

    // Declarations
    int axis;
    int rotSpeed;
    float thetaInRadians; // angle by which to rotate when mouse movement is detected
    float dir;            // direction in which to rotate
    char filename[FILENAMEMAX];
    Solid convexObject;

    cout << "Enter the name of the input file (or drag it here):\n";
    cin >> filename;
    convexObject.readInFromFile(filename);

    cout << "Enter an integer for rotation speed between 1 (slow) and 10 (fast):\n";
    cin >> rotSpeed;
    thetaInRadians = rotSpeed*pi/180.;

    cout << "\nClick in the lower left corner of the graphics window to exit.\n";

    // Open the graphics window and project the object.
    convexObject.projectAndPlot();

    // Move the object in response to input from the mouse.
    while(getAxis(&axis, &dir))
    {
        convexObject.rotate(axis, dir*thetaInRadians);
        clear();
        convexObject.projectAndPlot();
    }

    return 0;
}
