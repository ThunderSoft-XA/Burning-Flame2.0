/*
 * particles.h
 *
 *  Created on: Apr 29, 2019
 *      Author: little
 */

#ifndef PARTICLES_H_
#define PARTICLES_H_

#ifdef _OGLES3
#include "OpenGLES/FrmGLES3.h"
//#include <GLES3/gl3.h>
//#include <GLES2/gl2ext.h>
#else
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif




#include <vector>
#include <iostream>



//#include <GL/glew.h>
#include <glm/glm.hpp>



#ifndef NDEBUG

#define __DEBUG_PRINT(stream, tag, m, v) \
	do { \
		stream << "[" << tag << "][@" << __LINE__ << "] " << (m) << " " << (v) << std::endl; \
	} while(0)

#define LOG_INFO(m, v)	__DEBUG_PRINT(std::cout, "INFO", m, v)
#define LOG_ERROR(m, v)	__DEBUG_PRINT(std::cerr, "ERROR", m, v)

#define PRINT_SEPARATOR() LOG_INFO("----------------------------------------------------", "")

#else

#define LOG_INFO(m, v)
#define LOG_ERROR(m, v)

#define PRINT_SEPARATOR()

#endif //NDEBUG



#ifndef NDEBUG
#define TOKEN_STR_PAIR(token)	token, #token
#define DUMP_PROG_PARAMS(program) \
	do { \
		struct _TOKEN_STR { GLenum token; const GLchar *str; }; \
		GLint params; \
		struct _TOKEN_STR pnames[] = { \
				{ TOKEN_STR_PAIR(GL_ATTACHED_SHADERS) }, \
				{ TOKEN_STR_PAIR(GL_ACTIVE_UNIFORMS) }, \
				{ TOKEN_STR_PAIR(GL_ACTIVE_ATTRIBUTES) }, \
				{ TOKEN_STR_PAIR(GL_LINK_STATUS) } \
		}; \
		\
		PRINT_SEPARATOR(); \
		LOG_INFO("Program parameters:", ""); \
		for (size_t i = 0; i < sizeof(pnames)/sizeof(pnames[0]); i++) \
		{ \
			glGetProgramiv(program, pnames[i].token, &params); \
			LOG_INFO(pnames[i].str, params); \
		} \
		PRINT_SEPARATOR(); \
	} while(0)
#else
#define DUMP_PROG_PARAMS(program)
#endif //NDEBUG


// Represents a single particle and its state
struct Particle
{
    glm::vec2 Position, Velocity;
    glm::vec4 Color;
    GLfloat Life;

    Particle() : Position(0.0f), Velocity(0.0f), Color(1.0f), Life(1.0f)
    {
    	this->ResetColor();
    }

    void ResetColor(glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f))
    {
    	this->Color = color;
    };
};

/*
typedef struct {
    GLenum			type;
    const GLchar*	source;
    GLuint			shader;
} ShaderEntry;
*/


class ParticleGenerator
{
public:
    // Constructor
    //ParticleGenerator(GLuint width, GLuint height, GLuint amount);
	ParticleGenerator();

    // Update all particles
    void Update(GLfloat dt);

    // Render all particles
    void Draw(GLfloat particle_scale = 300.0f);

    GLuint GetWidth() const		{ return this->width; }
    GLuint GetHeight() const	{ return this->height; }

//private:
    // Width and height
    GLuint width;
    GLuint height;

    GLuint VAO;
    GLuint particle_tex_id;

    // Location of uniform variables
    GLint		projection;
    GLint		offset;
    GLint		color;
    GLint		scale;
    GLint		sprite;

    glm::vec2	central_point;
    glm::vec2	emission_point;
    GLfloat		emission_center_distance;

    GLuint program;

    // State
    GLuint amount;
    std::vector<Particle> particles;

    time_t	last_time;
    int		color_index;
    int		num_color;
    int		color_change_threshold;

    // Initializes buffer and vertex attributes
    void init();
    //GLuint Load(ShaderEntry *shaders);
    void Load();

    void getUniformVarsLocation();

    void updateColor(Particle &particle, GLfloat base_value);
};


#endif /* PARTICLES_H_ */
