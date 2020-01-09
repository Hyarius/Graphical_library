#ifndef JGL_DRAW_IMAGE_H
#define JGL_DRAW_IMAGE_H

void			draw_image(Vector2 p_tl, Vector2 p_tr, Vector2 p_dl, Vector2 p_dr,
						Uv p_uv_tl = Uv(0, 1), Uv p_uv_tr = Uv(1, 1), Uv p_uv_dl = Uv(0, 0), Uv p_uv_dr = Uv(1, 0),
						float p_alpha = 1.0f);

void			draw_image(Vector2 coord, Vector2 size,
						Uv p_uv_tl = Uv(0, 1), Uv p_uv_tr = Uv(1, 1), Uv p_uv_dl = Uv(0, 0), Uv p_uv_dr = Uv(1, 0),
						float p_alpha = 1.0f);

#endif
