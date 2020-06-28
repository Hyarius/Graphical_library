#ifndef JGL_DATA_H
#define JGL_DATA_H

#include "jgl_includes.h"

namespace jgl
{
	struct Data
	{
		std::vector<void*> content;

		Data();
		Data(void* p_data);
		Data(int nb_param, ...);

		void operator = (void* p_data);
		void operator + (void* p_ptr);
		Data operator + (const Data& delta);
		void operator += (void* p_ptr);
		void operator += (const Data& delta);

		template <typename T>
		T acces(size_t index) { return (static_cast<T>(content[index])); }
	};
}
#endif
