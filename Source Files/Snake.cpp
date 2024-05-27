// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <iostream>
#include "SnakeBody.h"
#include "BodyPart.h"
#include "Node.h"
#include "Point.h"
#include "LinkedList.h"
#include "Apple.h"
#include <string>

BodyPart part(0, 0);
Node head(part);
Node* pointer = &head;
LinkedList list(pointer);
SnakeBody snake(&list);
Apple apple(10, 10);
bool isGameOver = false;

int windowWidth = 800;
int windowHeight = 800;

void drawRectangle(int x, int y) {
    int size = 40;
    
    glBegin(GL_QUADS);
    glVertex2i((x-1)*size, y * size);
    // Upper left corner
    glVertex2i((x - 1) * size, (y-1) * size);
    // Lower left corner
    glVertex2i(x*size, (y - 1) * size);
    // Lower right corner
    glVertex2i(x*size, y*size);
    glEnd();
}



void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}







void gameOver() {

    std::string score = "Score: " + std::to_string(apple.score);
    renderBitmapString(300,700, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER!");
    renderBitmapString(340, 600, GLUT_BITMAP_HELVETICA_18, score.c_str());
    renderBitmapString(310, 650, GLUT_BITMAP_HELVETICA_18, "Press r to restart");

    
}


void update(int value) {
    // Update the position of the rectangle
    if (!isGameOver) {
        glClear(GL_COLOR_BUFFER_BIT);
        std::cout << "we in baby";
        snake.move();
        snake.collision(isGameOver);
        apple.isEaten(&snake);


        //glutSwapBuffers();

        glutPostRedisplay();
        glutTimerFunc(300, update, 0);

    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
        glutTimerFunc(300, update, 0);
    }
}


void RenderScene(void)

{

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glLoadIdentity();             // Reset the modelview matrix
    if (!isGameOver) {
        // drawing snake
        glColor3f(0.0f, 1.0f, 0.0f); // Set color to green
        Node* curr = snake.list->getHead();
        while (curr != nullptr) {
            drawRectangle(curr->val.x + 1, curr->val.y + 1);
            curr = curr->next;
        }

        // draw apple 
        glColor3f(1.0f, 0.0f, 0.0f); // Set color to green
        drawRectangle(apple.x, apple.y);

    }
    else {
        gameOver();
    }
    glutSwapBuffers();  // Swap the front and back buffers
   

}

void ChangeSize(GLsizei w, GLsizei h)

// Parametry horizontal i vertical (szerokoœæ i wysokoœæ okna) s¹
// przekazywane do funkcji za ka¿dym razem, gdy zmieni siê rozmiar okna

{

    // Set the viewport to cover the entire window
    glViewport(0, 0, w, h);
    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    // Switch back to the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    


}

void keys(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        snake.dir = 'U';
        break;
    case 's':
        snake.dir = 'D';
        break;
    case 'a':
        snake.dir = 'L';
        break;
    case 'd':
        snake.dir = 'R';
        break;
    case 'r':
        if (isGameOver) {
            part = BodyPart(0, 0);
            head = Node(part);
            pointer = &head;
            list = LinkedList(pointer);
            snake = SnakeBody(&list);
            apple = Apple(10, 10);
            snake.growSnake();
            snake.move();
            isGameOver = false;
        }
    }
    glutPostRedisplay();
}



void MyInit(void)

{

    glClearColor(0.5, 0.5f, 0.5f, 1.0f);
    // Kolor okna wnêtrza okna - ustawiono na szary

}


int main()
{
    snake.growSnake();
    snake.move();

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Double buffered, RGB color
    glutInitWindowSize(800, 800); // Initial window size
    glutCreateWindow("OpenGL Rectangle Example");
    glutKeyboardFunc(keys);


    // Register callback functions
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);

    // Set the background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutTimerFunc(0, update, 0);

    // Enter the GLUT event processing loop
    glutMainLoop();


    /*

    Node* curr = snake.list->getHead();
    int ind = 0;
    snake.dir = 'U';
    while (ind <= 10) {
        while (curr != nullptr) {
            std::cout << "x: " << curr->val.x << " y:" << curr->val.y;
            curr = curr->next;
        }
        std::cout << "\n";
        curr = snake.list->getHead();
        //std::cout << "jol2";
        if(ind%2 == 0)snake.growSnake();
        //std::cout << "jol3";
        snake.move();
        

        ind++;
    }
    */
}
