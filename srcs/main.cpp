#include "../headers/nerd.hpp"
using namespace glm;
using namespace kaf_graphics;

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "ERROR: Incorrect number of arguments." << endl;
		cout << argv[0] << endl;
		return (EXIT_FAILURE);
	}
	GLFWwindow *window;
	t_camera	cam;

	if (init_glfw() || create_window(&window))
		return (EXIT_FAILURE);
	initialize_camera_position(&cam);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return (EXIT_FAILURE);
	}
	initialize_input(&window, &cam);
	glClearColor(0.0f, 0.0f, 0.2f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	t_main	main;
	main.mod.x = 200;
	main.mod.y = 200;
	main.mod.scale = 1.0f;
	main.mod.color = glm::vec3(1.0f, 0.0f, 0.0f);
	main.view_object.load_from_file(
		"assets/shaders/StandardShading.vs",
		"assets/shaders/StandardShading.fs");
	main.text.load_from_file(
		"assets/shaders/Typewriter.vs",
		"assets/shaders/Typewriter.fs");
	main.text.use();
	glUniformMatrix4fv(glGetUniformLocation(main.text.program_id, "typewriting"), 1, GL_FALSE, glm::value_ptr(cam.typewriting));
	main.writer.initialize_typeface(
		"assets/fonts/Crumbled-Pixels.ttf");
	try
	{
		main.box.load_from_file(argv[1]);
		main.box.index_VBO();
	}
	catch (char const *str)
	{
		cout << str << endl;
		clean_up_gl(&main);
		return (EXIT_FAILURE);
	}
	initialize_buffers(&main);
	main.texture1 = load_image("assets/textures/container.jpg", false);
	main.texture2 = load_image("assets/textures/awesomeface.png", true);
	main.view_object.use();
	main.view_object.setInt("texture1", 0);
	main.view_object.setInt("texture2", 1);
	main.view_object.setVec3("light.position", 4.0f, 4.0f, 4.0f);
	main.view_object.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
	main.view_object.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f);
	main.view_object.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
	main.view_object.setVec3("material.ambient", 0.1f, 0.1f, 0.1f);
	main.view_object.setVec3("material.diffuse", 1.0f, 0.5f, 0.31f);
	main.view_object.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
	main.view_object.setFloat("material.shininess", 32.0f);
	run_main_loop(window, &main, &cam);
	clean_up_gl(&main);
	glfwTerminate();
	return (EXIT_SUCCESS);
}
