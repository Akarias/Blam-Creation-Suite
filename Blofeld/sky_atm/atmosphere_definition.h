#pragma once

namespace blofeld
{

extern s_tag_struct solo_fog_parameters_struct_definition_struct_definition;
extern s_tag_struct fog_light_struct_definition_struct_definition;
extern s_tag_struct VolumeFogParametersDefinition_struct_definition;
extern s_tag_struct LightShaftParametersDefinition_struct_definition;

extern s_tag_struct atmosphere_definition_block_struct_definition;
extern s_tag_block_definition atmosphere_definition_block;
extern s_tag_struct soloFogFunctionBlock_struct_definition;
extern s_tag_block_definition soloFogFunctionBlock;

constexpr unsigned long ATMOSPHERE_FOG_TAG = 'fogg';

extern s_tag_group atmosphere_fog_group;
} // namespace blofeld
