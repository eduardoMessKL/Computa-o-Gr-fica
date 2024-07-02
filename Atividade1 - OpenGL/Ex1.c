/*
1) Faça as seguintes alterações no arquivo Primeiro programa em OpenGL: 

- a cor do fundo para amarelo;
- faça um retângulo com as medidas diferentes da apresentada no exemplo, e ele deve aparecer com efeito gradiente na cor magenta;
- Faça com que o programa apresente mensagem quando for clicado no CTRL;
- Altere o programa de modo que a janela de visualização tenha os seguintes valores: X: – 20 a 20 Y: – 20 a 20; 
- Altere o tamanho da janela GLUT para 300 X 200.*/

//#define GL_SILENCE_DEPRECATION
#include<GL/glut.h>
#include<GL/freeglut.h>
#include<stdlib.h>
#include<stdio.h>

// adicionar as formas a serem mostradas na cena
void display()
{
    /* Limpa todos os pixels da tela */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Desenha um retângulo com gradiente magenta */
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex2f(-10.0, -5.0);
    glColor3f(0.5, 0.0, 0.5); // Roxo
    glVertex2f(10.0, -5.0);
    glColor3f(1.0, 0.5, 1.0); // Rosa claro
    glVertex2f(10.0, 5.0);
    glColor3f(0.5, 0.0, 0.5); // Roxo
    glVertex2f(-10.0, 5.0);
    glEnd();

    /* Troca buffers (double-buffering) */
    glutSwapBuffers();
}

void myReshape(int winWidth, int winHeight) // reshape window
{
    int tam = winWidth < winHeight ? winWidth : winHeight;
    glViewport(0, 0, tam, tam); // reset the viewport
}

// Colocar comandos pelo teclado
void myKeyboard(unsigned char c, int x, int y)
{
    switch(c){
    case 'q':
        exit(0);
        break;
    }
}

/* comandos especiais do teclado */
void keySpecial(int key, int x, int y) {
    printf("(%d, %d)\n", x, y);
    switch(key){
    case GLUT_KEY_LEFT:
        printf("Left pressed\n");
        break;
    case GLUT_KEY_UP:
        printf("Up pressed\n");
        break;
    }

    if(glutGetModifiers() == GLUT_ACTIVE_CTRL)
        printf("CTRL pressed\n");
}

// imprimir as coordenadas com o clique do mouse
void myMouse(int b, int s, int x, int y)
{
    switch(b){
    case GLUT_LEFT_BUTTON:
        printf("(%d, %d)\n", x, y);
    }
}

// função detecta movimento do mouse e salva coordenadas
void myMotion(int x, int y){
    printf("Motion: (%d, %d)\n", x, y);
}

void init()
{
    /* Define a cor de fundo (amarelo) */
    glClearColor(1.0, 1.0, 0.0, 0.0);

    /* Inicializa as Matrizes do OpenGL */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20.0, 20.0, -20.0, 20.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // inicializa
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // mostra o display como
    glutInitWindowSize(300, 200); // tamanho da janela
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(keySpecial);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutMainLoop();
    return 0;
}
