// NOTE: There are some minor differences between this version of classVertex.h
//       and the version that appeared in Part 1 of the Final Project.  In
//       particular, some additional lines have been inserted: one line that
//       #includes the QApplication file (which relates to using Qt's graphics)
//       and a few lines containing the friends list (so that other classes
//       can directly access the member variables of Vertex objects).

#ifndef VERTEX_H
#define VERTEX_H

#include <QApplication>

//------------------------------------------------------------------------------
// The Vertex class
//------------------------------------------------------------------------------
// Use this class to define vertices in 3D and to do some basic operations.  For
// these operations, each vertex is often treated as a vector whose tail is at
// the origin and whose tip is located at coordinates (x,y,z), which are three
// of the four member variables.

// Class declaration for Vertex class
class Vertex
{
// Friends list
friend class Solid;                 // give the Solid class access to our coords.
friend void drawPoly(Vertex* verticesToDraw, int numVertices,
                     int fillColor, float intensity);
                                    // see definition in finalgraphics.h
friend QPoint screenCoord(Vertex);  // get a screen coordinate

private:
    float x;
    float y;
    float z;
    float distFromOrigin;

public:
    // Based on the three inputs, sets x, y, and z.
    //  Also computes the corresponding distFromOrigin.
    Vertex(float=0., float=0., float=0.);

    // Prints the values of the member variables.
    void show();

    // Computes the sum of this Vertex and the input Vertex.
    Vertex operator+(Vertex);

    // Computes this Vertex minus the input Vertex.
    Vertex operator-(Vertex);

    // Computes the product of this Vertex and the input scalar.
    Vertex operator*(float);

    // Computes this Vertex divided by the input scalar.
    Vertex operator/(float);

    // Computes the dot product of this Vertex and the input Vertex.
    float operator*(Vertex);

    // Computes the cross product of this Vertex and the input Vertex.
    Vertex operator%(Vertex);

    // Computes the unit vector pointing from the origin toward this Vertex.
    Vertex unit();

    // Computes the projection of this Vertex using a given z0 (z-coordinate of
    // the projection plane) and a given COP (center of projection).
    Vertex project(float z0, Vertex cop);

    // Rotates this Vertex by the input angle about the x-axis.
    Vertex rotx(float angleInRadians);

    // Rotates this Vertex by the input angle about the y-axis.
    Vertex roty(float angleInRadians);

    // Rotates this Vertex by the input angle about the z-axis.
    Vertex rotz(float angleInRadians);
};

#endif // VERTEX_H
