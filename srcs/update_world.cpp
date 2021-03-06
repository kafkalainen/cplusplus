#include "../headers/nerd.hpp"

void	toggle_transparency(t_inputs *input)
{
	if (input->transparency && input->transparency_toggle)
	{
		glDisable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	else if (!input->transparency && input->transparency_toggle)
	{
		glEnable(GL_CULL_FACE);
		glDisable(GL_BLEND);
	}
}

void	toggle_wireframe(t_inputs *input)
{
	if (input->wireframe && input->wireframe_toggle)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (!input->wireframe && input->wireframe_toggle)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void	update_world(GLFWwindow *window, t_camera *cam)
{
	cam->current_time = glfwGetTime();
	cam->delta_time = float(cam->current_time - cam->last_time);
	handle_mouse_movement(window, cam);
	handle_key_input(window, cam, cam->delta_time);
	compute_dir_right_up(cam);
	update_projection_matrix(cam);
	update_view_matrix(cam);
	cam->last_time = cam->current_time;
}
