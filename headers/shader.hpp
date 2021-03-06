#ifndef SHADER_HPP
#define SHADER_HPP
#include "../glad/include/glad/glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

namespace kaf_shader
{
	class Shader
	{
		typedef struct t_temp_loader
		{
			std::string			vertex_code;
			std::string			fragment_code;
			std::ifstream		vertex_shader_file;
			std::ifstream		fragment_shader_file;
			std::stringstream	vertex_shader_stream;
			std::stringstream	fragment_shader_stream;
			GLuint				vertex;
			GLuint				fragment;
		}				s_temp_loader;
		private:
			bool	initialized;
			void	check_compiling_errors(GLuint type, const char *msg);
		public:
			GLuint	program_id;
			Shader(void);
			void	use();
			void	load_from_file(const char* vertex_file_path, const char* fragment_file_path);
			void	setBool(const std::string &name, bool value) const;
			void	setInt(const std::string &name, int value) const;
			void	setFloat(const std::string &name, float value) const;
			void	setVec3(const std::string &name, glm::vec3 &v);
			void	setVec3(const std::string &name, float x, float y, float z);
			void	setMat4(const std::string &name, glm::mat4 &m);
	};
}
#endif
