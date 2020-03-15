#include "jgl.h"

Mouse *g_mouse;

Mouse::Mouse()
{
	int x, y;

	SDL_GetMouseState(&(x), &(y));
	pos = Vector2(x, y);
	old_pos = Vector2(x, y);
	rel_pos = Vector2(0, 0);
	wheel = 0.0f;
	button[MOUSE_LEFT] = MOUSE_NULL;
	button[MOUSE_RIGHT] = MOUSE_NULL;
	button[MOUSE_MIDDLE] = MOUSE_NULL;
}

void		Mouse::actualize_mouse(SDL_Event *event)
{
	int x, y;
	Uint32 mousestate;

	old_pos = pos;
	mousestate = SDL_GetMouseState(&(x), &(y));
	pos = Vector2(x, y);

	if (old_pos.x != -1)
		rel_pos = pos - old_pos;

	if (event != NULL && event->type == SDL_MOUSEWHEEL)
		wheel = static_cast<float>(event->wheel.y);
	else
		wheel = 0.0f;

	button[MOUSE_LEFT] = (mousestate & SDL_BUTTON(SDL_BUTTON_LEFT) ? MOUSE_DOWN : (button[MOUSE_LEFT] == MOUSE_DOWN ? MOUSE_UP : MOUSE_NULL));
	button[MOUSE_RIGHT] = (mousestate & SDL_BUTTON(SDL_BUTTON_RIGHT) ? MOUSE_DOWN : (button[MOUSE_RIGHT] == MOUSE_DOWN ? MOUSE_UP : MOUSE_NULL));
	button[MOUSE_MIDDLE] = (mousestate & SDL_BUTTON(SDL_BUTTON_MIDDLE) ? MOUSE_DOWN : (button[MOUSE_MIDDLE] == MOUSE_DOWN ? MOUSE_UP : MOUSE_NULL));

	if (old_pos != Vector2())
		rel_pos = pos - old_pos;

	if (rel_pos != Vector2(0, 0))
		motion = true;

	if (button[MOUSE_LEFT] == MOUSE_NULL && button[MOUSE_RIGHT] == MOUSE_NULL)
		motion = false;
}

mouse_state			Mouse::get_button(mouse_button type)
{
	int value = static_cast<int>(type);
	mouse_state result = static_cast<mouse_state>(button[value]);
	//button[value] = static_cast<int>(mouse_state::null);
	return (result);
}

void Mouse::place(Vector2 coord)
{
	pos = coord;
	old_pos = coord;
	rel_pos = Vector2(0, 0);
	SDL_WarpMouseInWindow(g_application->window(), static_cast<int>(coord.x), static_cast<int>(coord.y));
}

Mouse *get_mouse()
{
	return (g_mouse);
}
