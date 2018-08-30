#version 330

///resulting color of fragment
layout(location = 0) out vec4 color;

vec4 jglFragmentShader();

void main() {
    color = jglFragmentShader();
}
