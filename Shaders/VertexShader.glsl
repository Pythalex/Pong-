#version 330 core

layout (location = 0) in vec3 aPos;

uniform float width;
uniform float height;

void main(){
	float x = (aPos.x/ width) * 2 - 1.0f;
	float y = -(aPos.y / height) * 2 + 1.0f;
	gl_Position = vec4(x, y, aPos.z, 1.0);
}