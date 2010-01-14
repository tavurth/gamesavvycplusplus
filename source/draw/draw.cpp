//		Copyright (c) William Whitty 2010
//
//     This file is part of GSC. 
//
//     GSC is free software: you can redistribute it and/or modify
//     it under the terms of the GNU Lesser General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     GSC is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU Lesser General Public License for more details.
//
//     You should have received a copy of the GNU Lesser General Public License
//     along with GSC.  If not, see <http:##www.gnu.org/licenses/>.

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

void draw::texture (Texture * tex, float x, float y, float z, float w, float h) {
	glPushMatrix();
	glTranslatef(x,y,z);
	glBindTexture(GL_TEXTURE_2D, tex->get_id());
	glBegin(GL_QUADS);
		glTexCoord2d(0.01,0.01);	glVertex3f(0, 0, 0);
		glTexCoord2d(0.99,0.01);	glVertex3f(w, 0, 0);
		glTexCoord2d(0.99,0.99);	glVertex3f(w, h, 0);
		glTexCoord2d(0.01,0.99);	glVertex3f(0, h, 0);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
}
