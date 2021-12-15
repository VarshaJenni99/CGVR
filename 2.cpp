#include<iostream>
#include<gl/glut.h>
int xc, yc, r;
int flag = 0;
using namespace std;
void drawCircle(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - y, yc - x);
	glEnd();
}
void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;

	while (x < y)
	{
		drawCircle(xc, yc, x, y);
		x++;
		if (d < 0)
			d = d + 4 * x + 6;
		else
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		//drawCircle(xc, yc, x, y);
	}
}
void display()
{
	int j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	circleBres(xc, yc, r);
	glFlush();
}
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0, 0, 1.0);
	glPointSize(5.0);
	gluOrtho2D(-250, 250, -250, 250);
}

void myMouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			if (flag == 0)
			{
				printf("Defining x1,y1");
				xc = x - 250;
				yc = 250 - y;
				flag++;
				cout << xc << " " << yc << " \n";
			}
			else
			{
				int x1 = x - 250;
				int y1 = 250 - y;

				r = (int)sqrt((double)((x1 - xc) * (x1 - xc) + (y1 - yc) * (y1 - yc)));
				flag = 0;
				cout << "r" << r << endl;
				circleBres(xc, yc, r);
				glFlush();

			}
		}
		break;
	}

}

void displayMouse()
{
	int j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}
void main(int argc, char* argv[])
{
	int j;
	//for keyboard
	printf("Enter coord of centre of circle & radius: ");
	cin >> xc >> yc >> r;
	//end keyboard
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenhams Circle");
	glutDisplayFunc(display);
	//glutMouseFunc(myMouse);
	//glutDisplayFunc(displayMouse);
	myinit();
	glutMainLoop();
}
