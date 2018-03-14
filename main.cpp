#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
//Jairo Ariel Martinez Villalta
//Jeafean Oskar Cruz Martinez

GLfloat angulo, i, radio = 0.75, cx = 0, cy = 0, radio_esquina = 0.20;

GLint w = 600;
GLint h = 420;
void display(void)
{
	glClearColor(0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_LINES);
    glPointSize(70);
    //Lineas de afuera
    glVertex3f(4.5f,4.5f,0.0f);//
    glVertex3f(-4.5f,4.5f,0.0f);//
    
    glVertex3f(-4.5f,4.5f,0.0f);//
    glVertex3f(-4.5f,-4.5f,0.0f);//
    
    glVertex3f(-4.5f,-4.5f,0.0f);//
    glVertex3f(4.5f,-4.5f,0.0f);//
    
    glVertex3f(4.5f,4.5f,0.0f);//
    glVertex3f(4.5f,-4.5f,0.0f);//
    
    glVertex3f(0.0f,4.5f,0.0f);//
    glVertex3f(0.0f,-4.5f,0.0f);//
    //Porteria izquierda
    glVertex3f(-4.5f,2.0f,0.0f);//
    glVertex3f(-3.5f,2.0f,0.0f);//
    glVertex3f(-3.5f,2.0f,0.0f);//
    glVertex3f(-3.5f,-2.0f,0.0f);//
    glVertex3f(-3.5f,-2.0f,0.0f);//
    glVertex3f(-4.5f,-2.0f,0.0f);//
    
    glVertex3f(-4.5f,3.0f,0.0f);//
    glVertex3f(-2.5f,3.0f,0.0f);//
    glVertex3f(-2.5f,3.0f,0.0f);//
    glVertex3f(-2.5f,-3.0f,0.0f);//
    glVertex3f(-2.5f,-3.0f,0.0f);//
    glVertex3f(-4.5f,-3.0f,0.0f);//
    //Porteria derecha
    glVertex3f(4.5f,2.0f,0.0f);//
    glVertex3f(3.5f,2.0f,0.0f);//
    glVertex3f(3.5f,2.0f,0.0f);//
    glVertex3f(3.5f,-2.0f,0.0f);//
    glVertex3f(3.5f,-2.0f,0.0f);//
    glVertex3f(4.5f,-2.0f,0.0f);//
    
    glVertex3f(4.5f,3.0f,0.0f);//
    glVertex3f(2.5f,3.0f,0.0f);//
    glVertex3f(2.5f,3.0f,0.0f);//
    glVertex3f(2.5f,-3.0f,0.0f);//
    glVertex3f(2.5f,-3.0f,0.0f);//
    glVertex3f(4.5f,-3.0f,0.0f);//
    
    glEnd();
    
    glPointSize(1);
    glBegin(GL_POINTS);
    
    glVertex3f(-3.0f,0.0f,0.0f);//
    glVertex3f(3.0f,0.0f,0.0f);//
    glVertex3f(0.0f,0.0f,0.0f);//
    
    //Circulo Central
    for(i = 0; i<=8; i+=0.01)
    {
		cx = radio*cos(i);
		cy = radio*sin(i);
		glVertex3f(cx, cy, 0.0f);
	}
	
	for(i = 0; i<=45; i+=1)
    {
		angulo = i*M_PI/90.00f;
		glVertex3f(-2.5 + cos(angulo), sin(angulo), 0.0f);
	}
	
	for(i = 270; i<=360; i+=1)
    {
		angulo = i*M_PI/180.00f;
		glVertex3f(-2.5 + cos(angulo), sin(angulo), 0.0f);
	}
	
	//Media luna derecha
	for(i = 90; i<=270; i+=1)
    {
		angulo = i*M_PI/180.00f;
		glVertex3f(2.5 + cos(angulo), sin(angulo), 0.0f);
	}
	
	//Circulo esquina superior izquierda
    for(double i = 11; i<=12.5; i+=0.01)
    {
		cx = radio_esquina*cos(i) + (-4.5);
		cy = radio_esquina*sin(i) + (4.5);
		glVertex3f(cx, cy, 0.0f);
	}
	
	//Circulo esquina inferior izquierda
    for(double i = 6.3; i<=8; i+=0.01)
    {
		cx = radio_esquina*cos(i) + (-4.5);
		cy = radio_esquina*sin(i) + (-4.5);
		glVertex3f(cx, cy, 0.0f);
	}
	
	//Circulo esquina superior derecha
	for(double i = 3.1; i<=4.7; i+=0.01)
    {
		cx = radio_esquina*cos(i) + (4.5);
		cy = radio_esquina*sin(i) + (4.5);
		glVertex3f(cx, cy, 0.0f);
	}
	
	//Circulo esquina inferior derecha
	for(double i = 1.6; i<=3.1; i+=0.01)
    {
		cx = radio_esquina*cos(i) + (4.5);
		cy = radio_esquina*sin(i) + (-4.5);
		glVertex3f(cx, cy, 0.0f);
	}
    glEnd();
    
    
    glPointSize(2.5);
    glBegin(GL_POINTS);
    
    glVertex3f(-3.0f,0.0f,0.0f);//
    glVertex3f(3.0f,0.0f,0.0f);//
    glVertex3f(0.0f,0.0f,0.0f);//
    glEnd();
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, 1.0, -1.0);//Pantalla Completa
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 420);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejemplo Clase");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
