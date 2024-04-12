#version 330 core
out vec4 FragColor;
uniform vec4 pixelColor;

in vec4 pos_fragment;

void main()
{
   FragColor = pos_fragment;
};