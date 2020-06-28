#include "jgl.h"

namespace jgl
{
	static size_t count_word_len(jgl::String& input, jgl::String& delim, size_t start)
	{
		size_t result = 0;

		for (result = start; result < input.size(); result++)
		{
			if (input[result] == delim[0])
			{
				size_t j = 0;
				while (j < delim.size() &&
					result + j < input.size() &&
					input[result + j] == delim[j])
					j++;
				if (j == delim.size())
					return (result - start);
				result += j - 1;
			}
		}
		return (result - start);
	}

	static size_t unique_count_word_len(jgl::Unique_string& input, jgl::Unique_string& delim, size_t start)
	{
		size_t result = 0;

		for (result = start; result < input.size(); result++)
		{
			if (input[result] == delim[0])
			{
				size_t j = 0;
				while (j < delim.size() &&
					result + j < input.size() &&
					input[result + j] == delim[j])
					j++;
				if (j == delim.size())
					return (result - start);
				result += j - 1;
			}
		}
		return (result - start);
	}

	jgl::Array<jgl::String> strsplit(jgl::String input, jgl::String delim, bool regroup)
	{
		jgl::Array<jgl::String>	tab(40);

		strsplit(tab, input, delim, regroup);

		return (tab);
	}

	void strsplit(jgl::Array<jgl::String>& tab, jgl::String input, jgl::String delim, bool regroup)
	{
		jgl::String new_word;
		size_t index = 0;
		size_t nb_word = 0;
		tab.clear();

		while (index < input.size())
		{
			size_t word_len = count_word_len(input, delim, index);
			if (word_len != 0 || regroup == true)
			{
				new_word = input.substr(index, index + word_len);
				if (new_word.size() == 0)
					jgl::error_exit(1, "Bad len here");
				tab.push_back(new_word);
			}
			index += word_len + delim.size();
			nb_word++;
		}
	}
	jgl::Array<jgl::Unique_string> unique_strsplit(jgl::Unique_string input, jgl::Unique_string c, bool regroup)
	{
		jgl::Array<jgl::Unique_string> tab;

		unique_strsplit(tab, input, c, regroup);

		return (tab);
	}

	void unique_strsplit(jgl::Array<jgl::Unique_string>& tab, jgl::Unique_string input, jgl::Unique_string delim, bool regroup)
	{
		jgl::Unique_string new_word;
		size_t index = 0;
		size_t nb_word = 0;
		tab.clear();

		while (index < input.size())
		{
			size_t word_len = unique_count_word_len(input, delim, index);
			if (word_len != 0 || regroup == true)
			{
				input.substr(new_word, index, index + word_len);
				tab.push_back(new_word);
			}
			index += word_len + delim.size();
			nb_word++;
		}
	}

	void check_sdl_error(jgl::String file, int line)
	{
		jgl::Array<jgl::String>tab = file.split("\\");
		if (tab.size() == 1)
			tab = file.split("/");
		jgl::String file_name = tab[tab.size() - 1];
		jgl::String text = SDL_GetError();
		if (text.size() != 0)
			error_exit(1, file_name + " - line [" + std::to_string(line) + "] : " + text);
	}

	void				error_exit(int num, jgl::String error)
	{
		std::cout << error << std::endl;
		if (g_application != nullptr)
			g_application->quit();
		jgl::quit_jgl();
		VLDDisable();
		exit(num);
	}

	void error_exit(int num, const char* str)
	{
		std::cout << str << std::endl;
		if (g_application != nullptr)
			g_application->quit();
		jgl::quit_jgl();
		VLDDisable();
		exit(num);
	}

	jgl::String normalize_string(jgl::String str, jgl::Glyph c, size_t size)
	{
		jgl::String result;

		result = str;

		while (result.size() < size)
			result.insert(0, c);

		return (result);
	}

	jgl::String normalize_float(float num, int after_point, jgl::Glyph c, size_t size)
	{
		jgl::String result;

		result = ftoa(num, after_point);
		while (result.size() < size)
			result.insert(0, c);

		return (result);
	}

	void reverse(jgl::String& base)
	{
		size_t i = 0, j = base.size() - 1;
		Glyph temp;
		while (i < j)
		{
			temp = base[i];
			base[i] = base[j];
			base[j] = temp;
			i++; j--;
		}
	}

	jgl::String itoa(int x, int d)
	{
		std::string result = std::to_string(x);
		size_t i = result.size();

		if (d > 0)
		{
			while (i < (size_t)d)
			{
				result.insert(0, " ");
				i++;
			}
		}

		return (jgl::String(result));
	}

	// Converts a floating point number tostring.
	jgl::String ftoa(float n, int afterpoint, int length)
	{
		std::string text;
		std::stringstream out;

		if (n > 0 || n < -1)
			afterpoint += 2;
		out << std::setprecision(afterpoint) << n;
		text = out.str();
		while (length != -1 && text.length() < static_cast<size_t>(length))
			text.insert(text.begin(), ' ');
		out.seekp(0);
		out << text;
		return jgl::String(out.str());
	}
	// Converts a floating point number tostring.
	jgl::String ftoa(double n, int afterpoint, int length)
	{
		return (ftoa((float)n, afterpoint, length));
	}


	float stof(jgl::String text)
	{
		std::string tmp = text->std();
		return (std::stof(tmp));
	}
	int stoi(jgl::String text)
	{
		std::string tmp = text->std();
		return (std::stoi(tmp));
	}

	bool string_is_numeric(jgl::String text)
	{
		return (text->contain("0123456789."));
	}

	bool is_middle(float min, float value, float max)
	{
		if (min > value)
			return (false);
		if (value > max)
			return (false);
		return (true);
	}

	void remove_char(jgl::String& src, jgl::String to_remove)
	{
		jgl::String result;
		for (size_t i = 0; i < src.size(); i++)
		{
			Glyph target = '\0';
			for (size_t j = 0; j < to_remove.size(); j++)
				if (to_remove[j] == src[i])
					target = to_remove[j];

			if (target == '\0')
				result.push_back(src[i]);
		}
		src = result;
	}

	jgl::Array<Vector2> 		calc_line_2d(float x1, float y1, float x2, float y2)
	{
		jgl::Array<Vector2> result;
		const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
		if (steep)
		{
			std::swap(x1, y1);
			std::swap(x2, y2);
		}
		if (x1 > x2)
		{
			std::swap(x1, x2);
			std::swap(y1, y2);
		}

		float dx = x2 - x1;
		float dy = fabs(y2 - y1);

		float error = dx / 2.0f;
		int ystep = (y1 < y2) ? 1 : -1;
		int y = (int)y1;

		int maxX = (int)x2;

		for (int x = (int)x1; x < maxX; x++)
		{
			if (steep)
				result.push_back(Vector2(y, x));
			else
				result.push_back(Vector2(x, y));

			error -= dy;
			if (error < 0)
			{
				y += ystep;
				error += dx;
			}
		}
		return (result);
	}

	int generate_nbr(int min, int max)
	{
		return((rand() % (max - min)) + min);
	}

	Pixel				convert_screen_to_opengl(Pixel source)
	{
		float x = (source.x) / (g_application->active_viewport()->area().x / 2.0f) - 1.0f;
		float y = -((source.y) / (g_application->active_viewport()->area().y / 2.0f) - 1.0f);
		return (Pixel(x, y, 0.0f));
	}

	SDL_Surface* create_surface_color(Color p_color)
	{
		SDL_Surface* surface;
		Uint32			rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rmask = 0xff000000;
		gmask = 0x00ff0000;
		bmask = 0x0000ff00;
		amask = 0x000000ff;
#else
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = 0xff000000;
#endif

		surface = SDL_CreateRGBSurface(0, 1, 1, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format,
			(Uint8)(p_color.r * 255), (Uint8)(p_color.g * 255),
			(Uint8)(p_color.b * 255), (Uint8)(p_color.a * 255)));

		return (surface);
	}

	float				degree_to_radian(float angle)
	{
		return ((angle * static_cast<float>(M_PI)) / 180.0f);
	}

	float				radian_to_degree(float radian)
	{
		return ((radian * 180.0f) / static_cast<float>(M_PI));
	}

	float clamp_float(float min, float value, float max)
	{
		if (value < min)
			return (min);
		if (value > max)
			return (max);
		return (value);
	}

	int clamp_int(int min, int value, int max)
	{
		if (value < min)
			return (min);
		if (value > max)
			return (max);
		return (value);
	}

	bool point_in_rectangle(Vector2 target, Vector2 pos, Vector2 size)
	{
		if (target.x > pos.x&& target.x <= pos.x + size.x &&
			target.y > pos.y&& target.y <= pos.y + size.y)
			return (true);
		return (false);
	}
}