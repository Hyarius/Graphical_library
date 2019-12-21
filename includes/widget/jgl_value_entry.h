#ifndef JGL_VALUE_ENTRY
#define JGL_VALUE_ENTRY

#include "jgl_widgets.h"
#include "jgl_widget_component.h"

class c_value_entry : public c_widget
{
private:
	w_box_component _box;
	w_value_entry_component _entry;

	bool _select;
	long _next_input;
	long _input_delay;

public:
	c_value_entry(float p_value = 0.001f, c_widget *p_parent = nullptr);
	~c_value_entry();

	float value(){return (_entry.value());}

	w_box_component &box(){return (_box);}
	w_value_entry_component &entry(){return (_entry);}

	// - box redirection function
	void set_tileset(c_tileset *p_tileset){_box.set_tileset(p_tileset);}
	void set_back(Color p_back){_box.set_back(p_back);}
	void set_front(Color p_front){_box.set_front(p_front);}
	void set_border(int p_border){_box.set_border(p_border);}
	c_tileset *tileset(){return (_box.tileset());}
	int border(){return (_box.border());}
	Color back(){return (_box.back());}
	Color front(){return (_box.front());}

	void select(){_select = true;_entry.set_selected(true);}
	void unselect(){_select = false;_entry.set_selected(false);}
	bool selected(){return (_select);}

	void set_geometry_imp(Vector2 p_anchor, Vector2 p_area);
	void move(Vector2 delta);

	void render();

	bool handle_mouse();

	bool handle_keyboard();
};

#endif
