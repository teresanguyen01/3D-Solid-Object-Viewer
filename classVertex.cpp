// NOTE: This file is identical to the finalproj_part1_soln.cpp file, which was
//       provided as the solution to Part 1 of the Final Project.

#include "classVertex.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//==============================================================================
// Class implementation for the Vertex class
//==============================================================================

// This function is the constructor.  Based on the three inputs, it sets x, y,
// and z.  It also computes the corresponding distFromOrigin.
Vertex::Vertex(float xInput, float yInput, float zInput)
{
    x = xInput;
    y = yInput;
    z = zInput;
    distFromOrigin = sqrt(x*x + y*y + z*z);
}

//------------------------------------------------------------------------------

// This getter prints the values of the member variables.
void Vertex::show()
{
    cout << "(" << setw(8) << x << ", "
                << setw(8) << y << ", "
                << setw(8) << z << "), distFromOrigin = "
                << setw(8) << distFromOrigin << endl;
    return;
}

//------------------------------------------------------------------------------

// This operator function computes the sum of this Vertex and the input Vertex.
Vertex Vertex::operator+(Vertex onTheRight)
{
    return Vertex(x+onTheRight.x, y+onTheRight.y, z+onTheRight.z);
}

//------------------------------------------------------------------------------

// This operator function computes this Vertex minus the input Vertex.
Vertex Vertex::operator-(Vertex onTheRight)
{
    return Vertex(x-onTheRight.x, y-onTheRight.y, z-onTheRight.z);
}

//------------------------------------------------------------------------------

// This operator function computes the product of this Vertex and the input 
// scalar.
Vertex Vertex::operator*(float scalar)
{
    return Vertex(x*scalar, y*scalar, z*scalar);
}

//------------------------------------------------------------------------------

// This operator function computes this Vertex divided by the input scalar.
Vertex Vertex::operator/(float scalar)
{
    return Vertex(x/scalar, y/scalar, z/scalar);
}

//------------------------------------------------------------------------------

// This operator function computes the dot product of this Vertex and the input
// Vertex.
float Vertex::operator*(Vertex onTheRight)
{
    return x*onTheRight.x + y*onTheRight.y + z*onTheRight.z;
}

//------------------------------------------------------------------------------

// This operator function computes the cross product of this Vertex and the
// input Vertex.
Vertex Vertex::operator%(Vertex onTheRight)
{
    return Vertex(y*onTheRight.z - z*onTheRight.y,
                  z*onTheRight.x - x*onTheRight.z,
                  x*onTheRight.y - y*onTheRight.x);
}

//------------------------------------------------------------------------------

// This function computes the unit vector pointing from the origin toward this
// Vertex.
Vertex Vertex::unit()
{
    return Vertex(x/distFromOrigin, y/distFromOrigin, z/distFromOrigin);

    // Alternate way without a call to the constructor:
    // return *this/distFromOrigin;
}

//------------------------------------------------------------------------------

// This function computes the projection of this Vertex using a given z0 
// (z-coordinate of the projection plane) and a given COP (center of projection).
Vertex Vertex::project(float z0, Vertex cop)
{
    float t0 = (z0-cop.z)/(z-cop.z); // value of parameter t when z = z0

    return Vertex(cop.x + t0*(x-cop.x),
                  cop.y + t0*(y-cop.y),
                  z0);

    // Alternate way without a call to the constructor:
    // return cop + ((*this-cop)*t0;
}

//------------------------------------------------------------------------------

// This function rotates this Vertex by the input angle about the x-axis.
Vertex Vertex::rotx(float angleInRadians)
{
    return Vertex(x,
                  y*cos(angleInRadians) - z*sin(angleInRadians),
                  y*sin(angleInRadians) + z*cos(angleInRadians));
}

//------------------------------------------------------------------------------

// This function rotates this Vertex by the input angle about the y-axis.
Vertex Vertex::roty(float angleInRadians)
{
    return Vertex(x*cos(angleInRadians) + z*sin(angleInRadians),
                  y,
                  -x*sin(angleInRadians) + z*cos(angleInRadians));
}

//------------------------------------------------------------------------------

// This function rotates this Vertex by the input angle about the z-axis.
Vertex Vertex::rotz(float angleInRadians)
{
    return Vertex(x*cos(angleInRadians) - y*sin(angleInRadians),
                  x*sin(angleInRadians) + y*cos(angleInRadians),
                  z);
}

