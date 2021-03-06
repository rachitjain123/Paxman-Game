#include "ground2.h"
#include "main.h"
#include <stdlib.h>

Ground2::Ground2(float x, float y, color_t color,float size)
{



    // this->position = glm::vec3(x, y, 0);
    this->rotation = 0;

    // speedx = -0.01+(rand()/(float) RAND_MAX)*0.02;
    speedx = 0.0;
    speedy = 0.0;
    accx = 0.0 ;
    accy = 0.0;

    // float r = 0.5;
    static const GLfloat vertex_buffer_data[] = {
        -4.0f, -1.5f, 0.0f,
        4.0f, -1.5f, 0.0f,
        -4.0f, -3.5f, 0.0f,

        4.0f, -1.5f, 0.0f,
         4.0f, -3.5f, 0.0f,
        -4.0f, -3.5f, 0.0f,

        // 4.0f, -1.0f, 0.0f,
        // 1.0f, -1.0f, 0.0f,
        // 4.0f, -3.5f, 0.0f,

        // 1.0f, -1.0f, 0.0f,
        // 1.0f, -3.5f, 0.0f,
        // 4.0f, -3.5f, 0.0f,
    };


    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Ground2::draw(glm::mat4 VP)
{
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

bounding_box_t Ground2::bounding_box()
{
    float x = this->position.x, y = this->position.y;
    bounding_box_t bbox = { x, y, 0.4, 0.4 };
    return bbox;
}
