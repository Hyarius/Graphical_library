#include "jgl.h"

int				g_fps = 60;
int				nb_frame;
int				beginsecond = 0;
unsigned int	framedelay = 1000 / g_fps;
int				frame_actual;
Uint32			framestart;

int				get_frame_state(int div)
{
	int value = (int)(((double)(nb_frame) / (double)(g_fps)) * div) % (div);
	return ((value == div ? div - 1 : value));
}

void			check_frame(bool draw)
{
	Vector2			coord;
	static string	str = "FPS";

	coord = Vector2(50, 50);
	framedelay = 1000 / g_fps;
	frame_actual = SDL_GetTicks();
	if (draw == true)
		draw_text(str, coord, 12);
	if (beginsecond == 0)
		beginsecond = frame_actual;
	if (frame_actual - beginsecond > 1000)
	{
		str = "FPS = " + to_string(nb_frame);
		nb_frame = 0;
		beginsecond = 0;
	}
	else
		nb_frame++;
	if (framedelay > frame_actual - framestart)
		SDL_Delay(framedelay - (frame_actual - framestart));
	framestart = SDL_GetTicks();
}
