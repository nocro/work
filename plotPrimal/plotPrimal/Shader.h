#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>
#define M_PI 3.14159265359
class Shader
{
    public:

        Shader();
        Shader(Shader const &shaderACopier);
        Shader(std::string vertexSource, std::string fragmentSource);
        ~Shader();

        Shader& operator=(Shader const &shaderACopier);

        bool charger();
        bool compilerShader(GLuint &shader, GLenum type, std::string const &fichierSource);
        GLuint getProgramID() const;//accesseur
        void envoyerMat4(std::string nom, glm::mat4 matrice)const ;

    private:

        GLuint m_vertexID;
        GLuint m_fragmentID;
        GLuint m_programID;

        std::string m_vertexSource;
        std::string m_fragmentSource;

};

#endif // SHADER_H
