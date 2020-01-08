#ifndef JGL_APPLICATION_H
#define JGL_APPLICATION_H

#include "jgl_includes.h"
#include "jgl_vector.h"
#include "jgl_color.h"

extern string color_shader_vert;
extern string color_shader_frag;
extern string texture_shader_vert;
extern string texture_shader_frag;

class c_application
{
private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
	SDL_GLContext _context;
	c_viewport *_viewport;
	Vector2 _win_size;

	GLuint _program_color;
	GLuint _program_sprite;

	GLuint _vertex_array;

	GLuint _vertex_buffer;
	GLuint _color_buffer;
	GLuint _texture_buffer;
	GLuint _alpha_buffer;

	GLuint _textureID;

	class c_window *_central_widget;
	bool play;
	SDL_Event _event;

public:
	c_application(string name, Vector2 p_size = Vector2(), Color p_color = Color(50, 50, 50));

	SDL_Window *window();

	SDL_Renderer *renderer();
	SDL_GLContext &context(){return (_context);}

	GLuint program_color(){return (_program_color);}
	GLuint program_sprite(){return (_program_sprite);}

	GLuint vertex_array(){return (_vertex_array);}

	GLuint vertex_buffer(){return (_vertex_buffer);}
	GLuint color_buffer(){return (_color_buffer);}
	GLuint texture_buffer(){return (_texture_buffer);}
	GLuint alpha_buffer(){return (_alpha_buffer);}

	GLuint textureID(){return (_textureID);}

	SDL_Event *event();

	c_viewport *viewport(){return (_viewport);}

	void quit();

	class c_window *central_widget();

	void set_background(Color p_color = Color(50, 50, 50));

	void resize(Vector2 p_size);

	Vector2 &size();

	void select();

	void clear();

	void render();

	int run();
};

GLuint		load_shaders(
				string p_vertex_file_path,
				string p_fragment_file_path
			);

#endif
