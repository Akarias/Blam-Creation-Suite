#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(user_interface_hud_globals_definition, USER_INTERFACE_HUD_GLOBALS_DEFINITION_TAG, user_interface_hud_globals_definition_block_block );

TAG_BLOCK_FROM_STRUCT(user_interface_hud_globals_definition_block, 1, user_interface_hud_globals_definition_struct_definition_struct_definition );

TAG_STRUCT(user_interface_hud_globals_definition_struct_definition)
{
	FIELD( _field_explanation, "Motion sensor globals" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "pad0", 3 ),
	FIELD( _field_real, "active camo appears as enemy when lower than#active Camo users show up as enemy when active camo is lower than this value (multiplayer)" ),
	FIELD( _field_real, "height classified as above#relative height at which something is above (meters)" ),
	FIELD( _field_real, "height classified as below#relative height at which something is below (meters)" ),
	FIELD( _field_real, "threshold speed#speed at which stuff is visible on the sensor (meters/sec)" ),
	FIELD( _field_real, "upwards movement scaling#multiplier for vertical speed upwards (multiplier)" ),
	FIELD( _field_real, "downwards movement scaling#multiplier for vertical speed downwards (multiplier)" ),
	FIELD( _field_real, "crouching movement scaling#multiplier for speed when crouching (multiplier)" ),
	FIELD( _field_real, "normal detection range extension#how far off the edge of the radar we can detect things (multiplier)" ),
	FIELD( _field_real, "vehicle detection range extension#how far off the edge of the radar we can detect vehicles (multiplier)" ),
	FIELD( _field_real, "vehicle radar range#special range boost used for large flying vehicles (meters)" ),
	FIELD( _field_real, "mech radar range#override for mech/mantis" ),
	FIELD( _field_real, "vehicle navigation marker range detection#range at which hud nav markers will show (meters)" ),
	FIELD( _field_real, "vehicle contested flash time#rate at which a contested vehicle flashes (seconds)" ),
	FIELD( _field_real, "activecamo xray animation cooldown #duration to wait before showing another animation (seconds)" ),
	FIELD( _field_real, "dead people visible time#time for which we will see dead team mates (seconds)" ),
	FIELD( _field_long_integer, "Motion Tracker Fade Frames#The number of frames that a non moving target will fade out over on the motion tracker." ),
	FIELD( _field_long_integer, "Armor Mod Display Counter#The number of seconds to show the players armor mod in the HUD (seconds)." ),
	FIELD( _field_real, "Broadsword Parallax Velocity Override" ),
	FIELD( _field_real, "Pelican Parallax Velocity Override" ),
	FIELD( _field_explanation, "Fanfare and Messaging globals" ),
	FIELD( _field_real, "fanfare display time #time to display the fanfares (seconds)" ),
	FIELD( _field_real, "fanfare speed up display time #time to display when higher priority fanfare queues up (seconds)" ),
	FIELD( _field_real, "medal score message lifetime #message time of the medal score message (seconds)" ),
	FIELD( _field_real, "medal score message restart time #time to reset message to when messages collide (seconds)" ),
	FIELD( _field_explanation, "Remote motion sensor globals" ),
	FIELD( _field_real, "remote sensor range#absolute range. (meters)" ),
	FIELD( _field_real, "remote sensor weak distance#distance at which the remote sensor starts to fail (meters)" ),
	FIELD( _field_real, "remote sensor failure distance#distance at which the remote sensor completely fails (meters)" ),
	FIELD( _field_explanation, "Damage globals" ),
	FIELD( _field_real, "shield bar recent damage duration#time taken to drain an entire bar of visible damage. less damage drains faster (seconds)" ),
	FIELD( _field_real, "damage indicator response duration#duration which the damage indicator icons will show in the HUD (seconds)" ),
	FIELD( _field_real, "damage flash response duration#used to determine how long to show the fullscreen damage flash (seconds)" ),
	FIELD( _field_tag_reference, "tiled mesh seen when hit in 1st person" ),
	FIELD( _field_real, "number of tiles across the screen" ),
	FIELD( _field_real, "mesh alpha multiplier" ),
	FIELD( _field_real, "mesh alpha gradient" ),
	FIELD( _field_real, "mesh alpha at centre (0..1)" ),
	FIELD( _field_real, "mesh alpha at screen edge (0..1)" ),
	FIELD( _field_array, "screen transform basis" ),
	FIELD( _field_explanation, "Reticule globals" ),
	FIELD( _field_real, "Reticule maximum spread angle:degrees#Maximum spread for all weapon reticules. This should be set to the largest spread angle of all the weapons." ),
	FIELD( _field_explanation, "Sounds" ),
	FIELD( _field_tag_reference, "banned vehicle entrance sound" ),
	FIELD( _field_explanation, "High Contrast globals" ),
	FIELD( _field_byte_flags, "High Contrast Flags" ),
	FIELD( _field_pad, "pad1", 3 ),
	FIELD( _field_explanation, "Dynamic Contrast Settings" ),
	FIELD( _field_real, "Minimum Threshold#Minimum brightness value at which the dynamic contrast activates." ),
	FIELD( _field_real, "Maximum Threshold#Brightness value at which the dynamic contrast is fully activated." ),
	FIELD( _field_real, "Clamp Threshold#Clamped brightness value. Can be used to limit the intensity of the dynamic contrast, or enable over strength contrast." ),
	FIELD( _field_explanation, "Double Draw Settings" ),
	FIELD( _field_real, "Darken Factor#Opacity of the black layer." ),
	FIELD( _field_real, "Brighten Factor#Overbrightness factor to apply to the additive layer." ),
	FIELD( _field_explanation, "Text" ),
	FIELD( _field_block, "string references", &string_file_references_block ),
	FIELD( _field_tag_reference, "Interact Message Appear Sound" ),
	FIELD( _field_tag_reference, "Interact Message Disappear Sound " ),
	FIELD( _field_real, "medal fanfare animation lifetime #animation time of the medal fanfare (seconds)" ),
	FIELD( _field_real, "medal fanfare animation in lifetime #animation in time of the medal fanfare (seconds)" ),
	FIELD( _field_real, "medal fanfare animation out begin time #the time to begin the animation out sequence (seconds)" ),
	FIELD( _field_real, "event fanfare animation lifetime #animation time of the medal fanfare (seconds)" ),
	FIELD( _field_real, "event fanfare animation in lifetime #animation in time of the medal fanfare (seconds)" ),
	FIELD( _field_real, "event fanfare animation out begin time #the time to begin the animation out sequence (seconds)" ),
	FIELD( _field_explanation, "Player Training" ),
	FIELD( _field_block, "player training data", &player_training_entry_data_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

