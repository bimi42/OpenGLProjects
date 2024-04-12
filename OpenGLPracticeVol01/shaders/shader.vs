#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 pos_fragment;

void main()
{
   pos_fragment = vec4(aPos.x , aPos.y * -1.0f, aPos.z, 1.0);
   gl_Position = pos_fragment;
};