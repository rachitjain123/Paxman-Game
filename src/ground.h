#include "main.h"

#ifndef GROUND_H
#define GROUND_H


class Ground {
public:
    Ground() {}
    Ground(float x, float y, color_t color,float size);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speedx,speedy;
    double accx, accy;
    void change_speed();
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // GROUND_H
