#ifndef JGL_UNIQUE_STRING_H
#define JGL_UNIQUE_STRING_H

#include "jgl_includes.h"
#include "jgl_define.h"
#include "jgl_glyph.h"

namespace jgl
{
	extern Glyph nullchar;

	std::vector<class Unique_string> unique_strsplit(class Unique_string input, class Unique_string c, bool regroup);

	class Unique_string
	{
	protected:
		jgl::Array<Glyph> _content;

	public:
		Unique_string();
		Unique_string(const Glyph value);
		Unique_string(const char* str);
		Unique_string(const std::string str);
		Unique_string(const Unique_string& old);
		~Unique_string();

		size_t size() const { return (_content.size()); }
		size_t push_size() const { return (_content.push_size()); }
		size_t max_size() const { return (_content.max_size()); }

		jgl::Array<Glyph>& content() { return (_content); }

		void push_back(const Glyph element) { _content.push_back(element); }
		void push_front(const Glyph element) { _content.insert(0, element); }
		void append(const Glyph element) { push_back(element); }
		void append(const Unique_string element) { for (size_t i = 0; i < element.size(); i++)push_back(element[i]); }
		Glyph& operator[](const size_t i);
		const Glyph& operator[](size_t i) const;
		void clear() { _content.clear(); }

		void resize(size_t new_size) { _content.resize(new_size); }

		Unique_string operator + (const Unique_string delta);
		Unique_string operator += (const Unique_string delta);
		void operator = (const Unique_string delta);

		void print_info();

		bool empty() { return (_content.empty()); }
		bool find(Glyph to_find);
		bool contain(Unique_string to_find);
		void pop_back() { _content.pop_back(); }
		void erase(size_t index) { _content.erase(index); }

		std::vector<jgl::Unique_string> split(jgl::Unique_string delim, bool regroup = true) { return (unique_strsplit(*this, delim, regroup)); }
		jgl::Unique_string substr(size_t start, size_t end);
		void substr(jgl::Unique_string& result, size_t start, size_t end);

		void insert(size_t index, Glyph insert_value) { _content.insert(index, insert_value); }
		void insert(size_t index, Unique_string insert_value) {
			for (size_t i = 0; i < insert_value.size(); i++)
				_content.insert(index, insert_value[i]);
		}

		std::string std();

		bool operator == (const Unique_string other);
		bool operator != (const Unique_string other);
	};
	Unique_string operator + (const char* str, Unique_string delta);
}

std::ostream& operator<<(std::ostream& os, jgl::Unique_string value);

#endif