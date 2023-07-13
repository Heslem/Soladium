#include "VaoGenerator.h"

renderer::Vao* VaoGenerator::generateSquare()
{
    static GLfloat vertices[] = {
        // �������          // �����             // ���������� ����������
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // ������� ������
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // ������ ������
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ������ �����
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // ������� �����
    };
    static GLuint indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    return new renderer::Vao(vertices, sizeof(vertices), indices, sizeof(indices), GL_TRIANGLES, 6);
}
