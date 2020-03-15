#ifndef JGL_INCLUDES_H
#define JGL_INCLUDES_H

#pragma warning(disable:4996)

#ifdef __APPLE__
#	include <stdlib.h>
#elif defined _WIN32
#	include <io.h>
#endif
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <string>
#include <stdio.h>
#include <map>
#include <stdint.h>
#include <time.h>
#include <tuple>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <SDL.h>
//#ifdef __APPLE__
//#	include <OpenGL/gl3.h>
//#	include <OpenGL/gl3ext.h>
//#elif defined _WIN32
#	include <glew.h>
#	include <SDL_opengl.h>
//#endif
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#endif
