#ifndef JGL_H
#define JGL_H

#define FPS 60.0f;

#include "jgl_includes.h"
#include "jgl_perlin.h"
#include "jgl_define.h"

#ifdef _WIN32
	#include "jgl_dirent.h"
#else
	#include "dirent.h"
#endif

#include "jgl_enum.h"
#include "jgl_reference_count.h"
#include "jgl_array.h"
#include "jgl_locked_queue.h"
#include "jgl_glyph.h"
#include "jgl_unique_string.h"
#include "jgl_pool.h"
#include "jgl_string.h"
#include "jgl_data.h"
#include "jgl_vector.h"
#include "jgl_matrix.h"
#include "jgl_color.h"
#include "jgl_geometry.h"
#include "jgl_basics_functions.h"
#include "jgl_share_object.h"
#include "jgl_system.h"
#include "jgl_application.h"
#include "jgl_viewport.h"
#include "jgl_camera.h"
#include "jgl_text.h"
#include "jgl_draw_image.h"
#include "jgl_draw_primitive.h"
#include "jgl_image.h"
#include "jgl_tileset.h"
#include "jgl_mesh.h"
#include "jgl_algorithm.h"
#include "jgl_engine.h"
#include "jgl_widgets.h"

#include "jgl_contener.h"
#include "jgl_text_label.h"
#include "jgl_value_label.h"
#include "jgl_frame.h"
#include "jgl_button.h"
#include "jgl_text_entry.h"
#include "jgl_value_entry.h"
#include "jgl_check_box.h"
#include "jgl_check_entry.h"
#include "jgl_hour_entry.h"
#include "jgl_tab.h"
#include "jgl_vscrollable_bar.h"
#include "jgl_hscrollable_bar.h"
#include "jgl_image_label.h"
#include "jgl_render_widget.h"
#include "jgl_progressive_bar.h"

#include "jgl_file_handler.h"
#include "jgl_log_handler.h"
#include "jgl_json_handler.h"
#include "jgl_fps_handler.h"

#include "jgl_file_menu.h"

#include "jgl_window.h"
#include "jgl_plot.h"

#include "jgl_network.h"

#endif
