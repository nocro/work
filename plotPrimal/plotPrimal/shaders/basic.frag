#version 150 core

in vec3 color;


uniform vec3 Ucolor;
out vec4 out_Color;

void main()
{

    out_Color = vec4(Ucolor,1.0);
}
