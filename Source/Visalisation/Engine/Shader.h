#ifndef SHADER_H
#define SHADER_H

#include <string>

//#include <GL/glfw3.h>
#include <GL/glew.h>

namespace Visualisation
{
    namespace Engine
    {
        class Shader
        {
        public:
            Shader(const ::std::string& vsFileName, const ::std::string fsFileName);
            ~Shader();

            GLuint getProgramID() const;
        protected:
            void loadShader(const ::std::string& vsFileName, const ::std::string fsFileName);

            GLuint ProgramID;
        };

    }
}


#endif