#include "HalfSphere.h"
#include "gl\glut.h"
#include "cggl\MathUtils.h"
#include <math.h>

using namespace cggl;

HalfSphere::HalfSphere(int radius)
{
	_radius = radius;
}


HalfSphere::~HalfSphere(void)
{
}

void HalfSphere::Draw(short detailLevel)
{
	glPushMatrix();
		glBegin(GL_TRIANGLE_STRIP);

		glVertex3f(0, _radius, 0);

		int verticalSegments = detailLevel;
		int horizontalSegments = detailLevel * 2;
				
		for (int i = 0; i < ((double) detailLevel / 2 + 0.5) - 1; i++)
        {
			float prevLatitude = (i * PI / verticalSegments) - (PI / 2);
            float latitude = ((i + 1) * PI / verticalSegments) - (PI / 2);

			float pdy = sin(prevLatitude) * -1;
			float pdxz = cos(prevLatitude);

            float dy = sin(latitude) * -1;
            float dxz = cos(latitude);

			for (int j = 0; j <= horizontalSegments; j++)
            {
                float longitude = j * (PI * 2) / horizontalSegments;

				float c = cos(longitude), s = sin(longitude);

				float pdx = c * pdxz;
				float pdz = s * pdxz;
			
				glNormal3f(pdx, pdy, pdz);
				glVertex3f(pdx * _radius, pdy * _radius, pdz * _radius);
				                
                float dx = c * dxz;
                float dz = s * dxz;

				glNormal3f(dx, dy, dz);
                glVertex3f(dx * _radius, dy * _radius, dz * _radius);
            }
        }

		glEnd();
	glPopMatrix();
}