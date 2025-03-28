#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera {
public:
    glm::vec3 Position;

    Camera(glm::vec3 startPosition) {
        Position = startPosition;
    }
};
#endif
#pragma once
