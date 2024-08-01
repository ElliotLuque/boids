#pragma once

#include "core/graphics/shader.hpp"
#include "index_buffer.hpp"

class Renderer {
 public:
  void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};
