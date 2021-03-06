#ifndef NERD_H
# define NERD_H
# define FOURCC_DXT1 0x31545844
# define FOURCC_DXT3 0x33545844
# define FOURCC_DXT5 0x35545844
# define WIDTH 1078
# define HEIGHT 768

using namespace std;
#include "../glad/include/glad/glad.h"
#include "../glfw/include/GLFW/glfw3.h"
#include <iostream>
#include <filesystem>
#include "../libkaf/libkaf.h"
using namespace glm;
using namespace kaf_graphics;
#include "controls.hpp"
#include "shader.hpp"
#include "camera.hpp"
#include "mesh.hpp"
#include "model.hpp"
#include "typewriter.hpp"
using namespace kaf_typewriter;
using namespace kaf_shader;

typedef struct	t_DDS
{
	unsigned int	height;
	unsigned int	width;
	unsigned int	linear_size;
	unsigned int	mip_map_count;
	unsigned int	four_cc;
	unsigned int	block_size;
	unsigned int	format;
}				s_DDS;

typedef struct	t_bitmap
{
	int				width;
	int				height;
	int				channel_count;
	unsigned char	*data;
}				s_bitmap;

typedef struct	t_main
{
	GLuint						vertex_array_object;
	GLuint						texture1;
	GLuint						texture2;
	GLuint						texture_id;
	vector<unsigned int>		indices;
	GLuint						vertex_buffer_object;
	GLuint						texel_buffer_object;
	GLuint						normal_buffer_object;
	GLuint						element_buffer_object;
	GLuint						light_array_object;
	kaf_model::Model			model;
	kaf_shader::Shader			view_object;
	kaf_shader::Shader			text;
	kaf_typewriter::Typewriter	writer;
	t_text_mod					mod;
	float						light_power;
}				s_main;

void	clean_up_gl(t_main *main);
int		create_window(GLFWwindow **window);
void	fps_timer(t_time *t);
void 	framebuffer_size_callback(GLFWwindow* window, int width, int height);
int		init_glfw();
void	initialize_buffers(t_main *main);
void	initialize_input(GLFWwindow **window, t_camera *cam);
void	initialize_time(t_time *t);
void	handle_key_input(GLFWwindow *window, t_camera *cam, float delta_time);
void	handle_mouse_movement(GLFWwindow *window, t_camera *cam);
GLuint	loadDDS(const char * imagepath);
GLuint	load_image(const char *path, const string &directory, bool gamma);
int		run_main_loop(GLFWwindow *window, t_main *main, t_camera *cam);
void	toggle_transparency(t_inputs *input);
void	toggle_wireframe(t_inputs *input);
void	update_world(GLFWwindow *window, t_camera *cam);

#endif
