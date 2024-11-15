/**
 * vector_operations.h
 * -------------------------------
 * Defines a singleton class which computes needed vector operations
 * for our Plane class after each button press in the main OpenGL loop
 *
 * @author Paul Lambert 
 * @note CS418
 */

#ifndef mp2_vector_operations_h
#define mp2_vector_operations_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <unistd.h>
#include <math.h>

/**
 * Singleton utility class for computing needed vector operations
 * for this assignment
 */
class VectorOperations
{

public:
    /**
     * Multiplies a vector by a float constant.
     *
     * @note Assumes vector size of 3 (x, y, z).
     * @param vector the vector to be multiplied
     * @param mult the float by which to multipy vector
     * @return a size 3 GLfloat vector (x, y, z)
     */
    GLfloat *mult_v(GLfloat vector[], float mult);

    /**
     * Adds two vectors together.
     *
     * @note assumes both vectors are of size 3 (x, y, z)
     * @note due to the commutativity of addition, paramater names
     *       of "first" and "second" are misnomers. lose no sleep.
     * @param first the first operand
     * @param second the second operand
     * @return a size 3 Glfloat vector (x, y, z)
     */
    GLfloat *add_v(GLfloat first[], GLfloat second[]);

    /**
     * Computes the cross product of two vectors.
     *
     * @note Assumes vector size of 3 (x, y, z).
     * @param first the first operand (size 3 vector)
     * @param second the the second operand (size 3 vector)
     * @return a size 3 GLfloat vector (x, y, z)
     */
    GLfloat *cross_product(GLfloat first[], GLfloat second[]);

    /**
     * Computes the 2-norm of a size 3 vector.
     *
     * @note Assumes vector size of 3 (x, y, z).
     * @note needed by unit_v() down below
     * @param vector the vector to be normed
     * @return the paramater's norm, a single float value
     */
    GLdouble norm(GLfloat vector[]);

    /**
     * Computes a size 3 vector's unit vector
     *
     * @note Assumes vector size of 3 (x, y, z).
     * @param vector the vector to be normalized
     * @return a size 3 GLfloat vector (x, y, z)
     */
    GLfloat *unit_v(GLfloat vector[]);
};


#endif
