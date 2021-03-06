#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_STRUCT(render_vertex_buffer_descriptor_struct)
	{
		{ _field_legacy, _field_long_integer, "vertex count*" },
		{ _field_legacy, _field_short_integer, "declaration*" },
		{ _field_legacy, _field_short_integer, "stride*" },
		{ _field_legacy, _field_data, "vertices*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(render_index_buffer_descriptor_struct)
	{
		{ _field_legacy, _field_long_integer, "primitive type*" },
		{ _field_legacy, _field_char_integer, "is index32*" },
		{ _field_legacy, _field_pad, "index buffer descicriptor padding", 3 },
		{ _field_legacy, _field_data, "index_data*" },
		{ _field_legacy, _field_terminator }
	};

} // namespace blofeld

