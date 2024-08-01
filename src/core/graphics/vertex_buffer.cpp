#include "vertex_buffer.hpp"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
  glGenBuffers(1, &m_renderer_ID);
  glBindBuffer(GL_ARRAY_BUFFER, m_renderer_ID);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &m_renderer_ID); }

void VertexBuffer::bind() { glBindBuffer(GL_ARRAY_BUFFER, m_renderer_ID); }

void VertexBuffer::unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
