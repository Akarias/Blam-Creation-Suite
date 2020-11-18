

uintptr_t hs_doc_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180780830);
	return ~uintptr_t();
}
c_function_hook_ex<hs_doc_offset, int()> hs_doc;


//__int64 sub_1807015E0()

uintptr_t console_initialize_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1807015E0);
	return ~uintptr_t();
}
c_function_hook_ex<console_initialize_offset, signed int()> console_initialize = { "console_initialize", []()
{
	c_console::write_line_verbose("console_initialize called");
	return console_initialize();
} };

uintptr_t console_open_offset(e_engine_type engine_type, e_build build)
{
	//OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180701760);
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1807EC5C0);

	return ~uintptr_t();
}
c_function_hook_ex<console_open_offset, signed int()> console_open = { "console_open", []()
{
	c_console::write_line_verbose("console_open called");
	return console_open();
} };

uintptr_t console_close_offset(e_engine_type engine_type, e_build build)
{
	//OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x180701800);
	return ~uintptr_t();
}
c_function_hook_ex<console_close_offset, signed int()> console_close = { "console_close", []()
{
	c_console::write_line_verbose("console_close called");
	return console_close();
} };

uintptr_t enable_console_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo1, _build_mcc_1_1389_0_0, 0x1821C8831);
	return ~uintptr_t();
}
char& enable_console = reference_symbol<char>("enable_console", enable_console_offset);

volatile uint32_t request_console_open = false;
volatile uint32_t request_console_close = false;

void update_console()
{
	if (is_valid(enable_console))
	{
		enable_console = true;
	}
	if (is_valid(console_open))
	{
		if (request_console_open)
		{
			request_console_open = 0;
			console_open();
		}
	}
	if (is_valid(console_close))
	{
		if (request_console_close)
		{
			request_console_close = 0;
			console_close();
		}
	}
}
static void draw_console_debug_gui()
{
	ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(600, 600), ImGuiCond_FirstUseEver);

	if (ImGui::Begin("Halo 1 Console/Scripting Debug"))
	{
		if (is_valid(console_open))
		{
			if (ImGui::Button("Console Open"))
			{
				_InterlockedIncrement(&request_console_open);
			}
		}
		if (is_valid(console_close))
		{
			if (ImGui::Button("Console Close"))
			{
				_InterlockedIncrement(&request_console_close);
			}
		}
		if (is_valid(hs_doc))
		{
			if (ImGui::Button("Dump Halo Script Documentation"))
			{
				hs_doc();
			}
		}
	}
	ImGui::End();
}


