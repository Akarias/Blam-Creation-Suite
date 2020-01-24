#pragma once

struct nicename("Ai Dialogue Globals") group('adlg') s_ai_dialogue_globals_definition
{
	struct s_unknown_0_block_definition;
	struct nicename("Vocalizations") s_vocalization_block_definition;
	struct nicename("Patterns") s_pattern_block_definition;
	struct nicename("Dialog Data") s_dialog_datum_block_definition;
	struct nicename("Involuntary Data") s_involuntary_datum_block_definition;
	struct s_unknown_5_block_definition;

	float __unknown; 
	float __unknown2; 
	float __unknown3; 
	float __unknown4; 
	Undefined32 __unknown5; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	Undefined32 __unknown8; 
	float __unknown9; 
	string_id nicename("Radio Effect") radio_effect; 
	s_tag_block_definition<s_unknown_0_block_definition> __unknown_0_block; 
	s_tag_block_definition<s_vocalization_block_definition> nicename("Vocalizations") vocalizations_block; 
	s_tag_block_definition<s_pattern_block_definition> nicename("Patterns") patterns_block; 
	Undefined32 __unknown10; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	s_tag_block_definition<s_dialog_datum_block_definition> nicename("Dialog Data") dialog_data_block; 
	s_tag_block_definition<s_involuntary_datum_block_definition> nicename("Involuntary Data") involuntary_data_block; 
	s_tag_block_definition<s_unknown_5_block_definition> __unknown_5_block; 

	struct s_unknown_0_block_definition
	{
		string_id __unknown; 
	};

	struct nicename("vocalization") s_vocalization_block_definition
	{
		struct nicename("Responses") s_respons_block_definition;

		string_id nicename("Vocalization") vocalization; 
		int16_t nicename("Parent Index") parent_index; 
		int16_t nicename("Priority") priority; 
		int32_t nicename("Flags") flags; 
		int16_t nicename("Glance Behavior") glance_behavior; 
		int16_t nicename("Glance Recipient") glance_recipient; 
		int16_t nicename("Perception Type") perception_type; 
		int16_t nicename("Max Combat Status") max_combat_status; 
		int16_t nicename("Animation Impulse") animation_impulse; 
		int16_t nicename("Overlap Priority") overlap_priority; 
		float nicename("Sound Repetition Delay") sound_repetition_delay; 
		float nicename("Allowable Queue Delay") allowable_queue_delay; 
		float nicename("Pre Vocalization Delay") pre_vocalization_delay; 
		float nicename("Notification Delay") notification_delay; 
		float nicename("Post Vocalization Delay") post_vocalization_delay; 
		float nicename("Repeat Delay") repeat_delay; 
		float nicename("Weight") weight; 
		float nicename("Speaker Freeze Time") speaker_freeze_time; 
		float nicename("Listener Freeze Time") listener_freeze_time; 
		int16_t nicename("Speaker Emotion") speaker_emotion; 
		int16_t nicename("Listener Emotion") listener_emotion; 
		float nicename("Skip Fraction1") skip_fraction1; 
		float nicename("Skip Fraction2") skip_fraction2; 
		float nicename("Skip Fraction3") skip_fraction3; 
		float nicename("Skip Fraction4") skip_fraction4; 
		Undefined32 __unknown; 
		string_id nicename("Sample Line") sample_line; 
		s_tag_block_definition<s_respons_block_definition> nicename("Responses") responses_block; 

		struct nicename("respons") s_respons_block_definition
		{
			string_id nicename("Vocalization Name") vocalization_name; 
			uint16_t nicename("Flags") flags; 
			int16_t nicename("Vocalization Index") vocalization_index; 
			int16_t nicename("Response Type") response_type; 
			int16_t nicename("Import Dialogue Index") import_dialogue_index; 
		};
	};

	struct nicename("pattern") s_pattern_block_definition
	{
		int16_t nicename("Dialog Type") dialog_type; 
		int16_t nicename("Vocalizations Index") vocalizations_index; 
		string_id nicename("Vocalization Name") vocalization_name; 
		int16_t nicename("Speaker Type") speaker_type; 
		uint16_t nicename("Flags") flags; 
		int16_t nicename("Hostility") hostility; 
		uint16_t __unknown; 
		int16_t __unknown2; 
		int16_t nicename("Cause Type") cause_type; 
		string_id nicename("Cause AI Type name") cause_ai_type_name; 
		string_id nicename("Equipment") equipment; 
		int32_t __unknown3; 
		int16_t __unknown4; 
		int16_t __unknown5; 
		int32_t __unknown6; 
		int16_t nicename("Spacial Relationship") spacial_relationship; 
		int16_t __unknown7; 
		int16_t __unknown8; 
		int16_t __unknown9; 
		int16_t nicename("Subject Type") subject_type; 
		int16_t __unknown10; 
		string_id nicename("Subject AI Type Name") subject_ai_type_name; 
	};

	struct nicename("dialog_datum") s_dialog_datum_block_definition
	{
		int16_t nicename("Start Index") start_index; 
		int16_t nicename("Length") length; 
	};

	struct nicename("involuntary_datum") s_involuntary_datum_block_definition
	{
		int16_t nicename("Involuntary Vocalization Index") involuntary_vocalization_index; 
		int16_t __unknown; 
	};

	struct s_unknown_5_block_definition
	{
		int32_t __unknown; 
	};
};