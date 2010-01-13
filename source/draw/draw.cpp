#include "draw.h"

using namespace gsc;

void draw::rect (float x, float y, float w, float h) {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glBegin(GL_QUADS);
		glVertex3f(0, 0, 0);
		glVertex3f(w, 0, 0);
		glVertex3f(w, h, 0);
		glVertex3f(0, h, 0);
	glEnd();
	glPopMatrix();
}

void draw::texture (GLuint tex, float x, float y, float z, float w, float h) {
	glPushMatrix();
	glTranslatef(x,y,z);
	glBindTexture(GL_TEXTURE_2D, tex);
	glBegin(GL_QUADS);
		glTexCoord2d(0.01,0.01);	glVertex3f(0, 0, 0);
		glTexCoord2d(0.99,0.01);	glVertex3f(w, 0, 0);
		glTexCoord2d(0.99,0.99);	glVertex3f(w, h, 0);
		glTexCoord2d(0.01,0.99);	glVertex3f(0, h, 0);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
