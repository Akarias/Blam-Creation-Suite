#pragma once

struct nicename("global_pixel_shader") tag_group('glps') s_global_pixel_shader_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		struct nicename("Unknown") s_unknown1_definition
		{
			struct nicename("Unknown") s_unknown2_definition
			{
				uint32_t __unknown0;
			};

			uint32_t __unknown0;
			s_tag_block_definition<s_unknown2_definition> __unknown1;
		};

		s_tag_block_definition<s_unknown1_definition> __unknown0;
		Undefined32 __unknown1;
	};

	struct nicename("Pixel Shaders") s_pixel_shaders_definition
	{
		struct nicename("Unknown") s_unknown3_definition
		{
			DEPRECATED_string_id __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		struct nicename("Unknown") s_unknown4_definition
		{
			DEPRECATED_string_id __unknown0;
			int8_t __unknown1;
			int8_t __unknown2;
			int8_t __unknown3;
			int8_t __unknown4;
		};

		Undefined32 __unknown0;
		DataReference __unknown1;
		DataReference __unknown2;
		DataReference __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
		s_tag_block_definition<s_unknown3_definition> __unknown10;
		int32_t __unknown11;
		Undefined32 __unknown12;
		int32_t __unknown13;
		s_tag_block_definition<s_unknown4_definition> __unknown14;
		int32_t __unknown15;
		Undefined32 __unknown16;
		int32_t __unknown17;
		Undefined32 __unknown18;
		Undefined32 __unknown19;
		Undefined32 __unknown20;
		Undefined32 __unknown21;
	};

	s_tag_block_definition<s_unknown_definition> __unknown0;
	Undefined32 __unknown1;
	s_tag_block_definition<s_pixel_shaders_definition> nicename("Pixel Shaders") pixel_shaders_block;
};

