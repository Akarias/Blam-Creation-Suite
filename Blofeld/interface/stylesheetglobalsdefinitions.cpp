#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(style_sheet_list, STYLE_SHEET_LIST_TAG, style_sheet_list_block_block );

TAG_BLOCK_FROM_STRUCT(style_sheet_list_block, 1, style_sheet_list_struct_definition_struct_definition );

TAG_BLOCK(UserInterfaceStyleSheetLanguagesBlock, k_language_count)
{
	FIELD( _field_long_enum, "language^" ),
	FIELD( _field_block, "font style sheets", &UserInterfaceStyleSheetsFontBlock_block ),
	FIELD( _field_block, "visual style sheets", &UserInterfaceStyleSheetsVisualBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetsFontBlock, k_maximumNumberOfStyleSheets)
{
	FIELD( _field_string_id, "style sheet name^" ),
	FIELD( _field_block, "font id", &UserInterfaceStyleSheetFontIdBlock_block ),
	FIELD( _field_block, "text case", &UserInterfaceStyleSheetTextCaseBlock_block ),
	FIELD( _field_block, "justification", &UserInterfaceStyleSheetJustificationBlock_block ),
	FIELD( _field_block, "alignment", &UserInterfaceStyleSheetAlignmentBlock_block ),
	FIELD( _field_block, "scale", &UserInterfaceStyleSheetScaleBlock_block ),
	FIELD( _field_block, "fixed height", &UserInterfaceStyleSheetFixedHeightBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetFontIdBlock, 1)
{
	FIELD( _field_long_enum, "font id" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetTextCaseBlock, 1)
{
	FIELD( _field_long_enum, "text case" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetJustificationBlock, 1)
{
	FIELD( _field_long_enum, "justification" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetAlignmentBlock, 1)
{
	FIELD( _field_long_enum, "alignment" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetScaleBlock, 1)
{
	FIELD( _field_real, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetFixedHeightBlock, 1)
{
	FIELD( _field_real, "height" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetsVisualBlock, k_maximumNumberOfStyleSheets)
{
	FIELD( _field_string_id, "style sheet name^" ),
	FIELD( _field_block, "drop shadow style", &UserInterfaceStyleSheetDropShadowStyleBlock_block ),
	FIELD( _field_block, "text color", &UserInterfaceStyleSheetColorBlock_block ),
	FIELD( _field_block, "drop shadow color", &UserInterfaceStyleSheetColorBlock_block ),
	FIELD( _field_string_id, "gradient name" ),
	FIELD( _field_string_id, "dropshadow name" ),
	FIELD( _field_string_id, "outer glow name" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetDropShadowStyleBlock, 1)
{
	FIELD( _field_long_enum, "drop shadow style" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetColorBlock, 1)
{
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetGradientBlock, 32)
{
	FIELD( _field_string_id, "gradient name^" ),
	FIELD( _field_real_argb_color, "color1" ),
	FIELD( _field_real_argb_color, "color2" ),
	FIELD( _field_real_argb_color, "color3" ),
	FIELD( _field_real_argb_color, "color4" ),
	FIELD( _field_real, "angle" ),
	FIELD( _field_real, "scale" ),
	FIELD( _field_real_vector_2d, "offset" ),
	FIELD( _field_long_integer, "number of colors" ),
	FIELD( _field_long_enum, "gradient shape" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetDropshadowBlock, 32)
{
	FIELD( _field_string_id, "dropshadow name^" ),
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_real, "angle" ),
	FIELD( _field_real, "distance" ),
	FIELD( _field_real, "spread" ),
	FIELD( _field_real, "size" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(UserInterfaceStyleSheetOuterGlowBlock, 32)
{
	FIELD( _field_string_id, "outer glow name^" ),
	FIELD( _field_real_argb_color, "color" ),
	FIELD( _field_real, "spread" ),
	FIELD( _field_real, "size" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(style_sheet_list_struct_definition)
{
	FIELD( _field_block, "style sheet languages", &UserInterfaceStyleSheetLanguagesBlock_block ),
	FIELD( _field_block, "gradients", &UserInterfaceStyleSheetGradientBlock_block ),
	FIELD( _field_block, "dropshadows", &UserInterfaceStyleSheetDropshadowBlock_block ),
	FIELD( _field_block, "outer glows", &UserInterfaceStyleSheetOuterGlowBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

