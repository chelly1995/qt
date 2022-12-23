#ifndef QTQLUT_H
#define QTQLUT_H

#include <QtOpenGL>

void glutWireCube(GLdouble size);
void glutSolidCube(GLdouble size);

void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint nsides, GLint rings);
void glutSolidCube(GLdouble innerRadius, GLdouble douterRadius, GLint nsides, GLint rings);

void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);

#endif // QTQLUT_H
