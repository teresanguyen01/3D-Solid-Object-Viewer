// Some parts of this file are based on a file supplied by Prof. Marshall Long 
// for ENAS 130.

#ifndef POLYSOLID_H
#define POLYSOLID_H

#include <QApplication>
#include "classVertex.h"

#define MAXVERTSINPOLY 10

//------------------------------------------------------------------------------
// The Poly structure
//------------------------------------------------------------------------------
// A polygon is defined by the vertices that bound it.
// A vertex is specified by its index in the listOfVertsInThisPoly array.
// We'll consider polygons with at most MAXVERTSINPOLY vertices.
typedef struct
{
    int nVertsInThisPoly;           // number of vertices in this polygon, which
                                    //     is less than or equal to MAXVERTSINPOLY
    int listOfVertsInThisPoly[MAXVERTSINPOLY];
                                    // contains indices of the vertices that form
                                    //     this polygon
    int colorOfThisPoly;            // color of this polygon (0=grey, 1=red,
                                    //     2=green, 3=blue, or 4=purple)
    Vertex centroidOfThisPoly;      // centroid of this polygon
} Poly;

//------------------------------------------------------------------------------
// The Solid class
//------------------------------------------------------------------------------

// Class declaration for Solid class
class Solid
{
private:
    int nVertsInObj;         // number of vertices
    Vertex *vertArray;       // an array of vertices that define the object
    int nPolysInObj;         // number of polygons
    Poly *polyArray;         // an array of polygon structures
    float maxDistFromOrigin; // max distance of any vertex in the object from the origin
    float z0;                // specifies where the projection plane cuts the z-axis
    Vertex cop;              // the COP (center of projection)

public:
    // Constructor: Sets each member variable to 0 or to nullptr (except cop,
    // which is a Vertex object).
    Solid();

    // Destructor: Deallocates memory associated with vertArray and polyArray.
    ~Solid();

    // Reads in the geometric description of the solid object (i.e., vertex list
    // and polygon list) from the specified file, as well as the color of each
    // of each polygon.  It also calculates the centroid of each polygon.
    // Finally, it determines maxDistFromOrigin, z0, and the COP.
    void readInFromFile(char* filename);

    // Projects the vertices and plots the result.  The first time the function is
    // called, it opens the graphics window.  Subsequent calls to projectAndPlot()
    // must NOT re-open the window, because it's already open.
    void projectAndPlot();

    // Rotates all vertices in the object about the specified axis (X, Y, or Z) by
    // the specified angle.  Also rotates the centroids of all polygons.
    void rotate(int axis, float angleInRadians);

    // Computes the outward unit normal for polygon iPoly.
    Vertex polyNorm(int iPoly);
};

#endif // POLYSOLID_H
