#include "Libraries\Includes\GL\glew.h" /* include GLEW and new version of GL on Windows */
#include "Libraries\Includes\GLFW\glfw3.h" /* GLFW helper library */
#include <stdlib.h>
#include <stdio.h>
#include "Source Code/Aurora/Aurora.h"

static void error_callback(int error, const char* description)
{    
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{    
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{    
	Ellipsoid er;
	/*int stackValue = 200;
	float stackValue2 = 12;
	double stackValue3 = 200;
	Event<int, float, double> e;
	e += [=](int i, float j, double k) { printf("%d\n", i + stackValue + (int)j + (int)k); };
	e += [&](int i, float j, double k) { printf("%d\n", i + stackValue + (int)j + (int)k); stackValue += 100; };
	e += [&stackValue](int i, float j, double k) { printf("%d\n", i + stackValue + (int)j + (int)k); };
	e += [stackValue](int i, float j, double k) { printf("%d\n", i + stackValue + (int)j + (int)k); };

	e(100, stackValue2, 53);*/
	GLFWwindow* window;    
	glfwSetErrorCallback(error_callback);    
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)    {        glfwTerminate();        exit(EXIT_FAILURE);    }
	glfwMakeContextCurrent(window);    glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window))
	{        
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION); 
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity(); 
		glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}    
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}