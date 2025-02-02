#pragma once

#include <glad/glad.h>

class VertexBuffer {
private:
  unsigned int m_renderer_ID;

public:
  VertexBuffer(const void *data, unsigned int size);
  ~VertexBuffer();

  void bind();
  void unbind();
};
