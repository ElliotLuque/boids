#pragma once

#include <glm/glm.hpp>

class Boid {
private:
  glm::vec2 m_position;
  glm::vec2 m_velocity;
  float m_speed;
  float m_size;
};
