#include <GL/glut.h>

float angle = 0.0;       // Ângulo para rotacionar o braço
float clawAngle = 0.0;   // Ângulo para abrir/fechar a garra

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(60.0, 1.0, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void wireBox(float x, float y, float z) {
    glPushMatrix();
    glScalef(x, y, z);
    glutWireCube(1.0);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glPushMatrix();

    glTranslatef(0.0, 0.0, -5.0);  // Move para a posição inicial
    wireBox(2.0, 0.4, 1.0);        // Desenha a base do braço

    glTranslatef(1.0, 0.0, 0.0);   // Move para o ponto de rotação do braço
    glRotatef(angle, 0.0, 0.0, 1.0); // Rotaciona o braço
    glTranslatef(1.0, 0.0, 0.0);   // Move o braço para fora da base
    wireBox(2.0, 0.4, 1.0);        // Desenha o braço

    glTranslatef(1.0, 0.0, 0.0);   // Move para o ponto de rotação da garra

    // Desenha a primeira parte da garra
    glPushMatrix();
    glTranslatef(0.5, 0.1, 0.0);  // Move para o ponto de rotação da primeira garra
    glRotatef(clawAngle, 0.0, 0.0, 1.0); // Rotaciona a primeira garra
    glTranslatef(0.5, 0.0, 0.0);  // Move para a posição correta da primeira garra
    wireBox(1.0, 0.2, 0.5);
    glPopMatrix();

    // Desenha a segunda parte da garra
    glPushMatrix();
    glTranslatef(0.5, -0.1, 0.0);  // Move para o ponto de rotação da segunda garra
    glRotatef(-clawAngle, 0.0, 0.0, 1.0); // Rotaciona a segunda garra
    glTranslatef(0.5, 0.0, 0.0);  // Move para a posição correta da segunda garra
    wireBox(1.0, 0.2, 0.5);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': // Rotacionar o braço no sentido anti-horário
            angle += 5.0;
            if (angle > 360) angle -= 360;
            glutPostRedisplay();
            break;
        case 'd': // Rotacionar o braço no sentido horário
            angle -= 5.0;
            if (angle < 0) angle += 360;
            glutPostRedisplay();
            break;
        case 'w': // Abrir a garra
            clawAngle += 5.0;
            if (clawAngle > 45) clawAngle = 45; // Limita a abertura
            glutPostRedisplay();
            break;
        case 's': // Fechar a garra
            clawAngle -= 5.0;
            if (clawAngle < 0) clawAngle = 0; // Limita o fechamento
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Garra do Robô");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
