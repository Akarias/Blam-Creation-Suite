



uintptr_t unk_143285930_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo5, _build_halo5_forge_1_194_6192_2, 0x143285930);
	return ~uintptr_t();
}
_PVFV& unk_143285930 = reference_symbol<_PVFV>("unk_143285930", unk_143285930_offset);

uintptr_t unk_143307FF8_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo5, _build_halo5_forge_1_194_6192_2, 0x143307FF8);
	return ~uintptr_t();
}
_PVFV& unk_143307FF8 = reference_symbol<_PVFV>("unk_143307FF8", unk_143307FF8_offset);

uintptr_t __scrt_common_main_seh_offset(e_engine_type engine_type, e_build build)
{
	OFFSET(_engine_type_halo5, _build_halo5_forge_1_194_6192_2, 0x1410EB6A8);
	return ~uintptr_t();
}
FunctionHookEx<__scrt_common_main_seh_offset, __int64()> __scrt_common_main_seh =
{
	"__scrt_common_main_seh",
	[]()
	{
		std::wstring output_directory = c_command_line::get_command_line_warg("blamboozle-output");
		if (output_directory.empty())
		{
			return __scrt_common_main_seh();
		}

		_PVFV func_address = (_PVFV)GetEngineVirtualAddress(_engine_type_halo5, 0x14001D8E0);

		char* data_address = GetEngineVirtualAddress(_engine_type_halo5, 0x14473EB88);

		constexpr uint32_t blacklist_indices[] =
		{
			19, 51, 52, 80, 82, 95, 353, 355, 357, 358, 365, 374, 510, 515, 567, 600,
			744, 745, 750, 751, 768, 776, 788, 845, 1117, 1118, 1127, 1363, 1368, 1369, 1372, 1373,
			1375, 1408, 1409, 1582, 1779, 1861, 1977, 1993, 2150, 2155, 4785, 4787, 4788, 4789, 4790, 5569,
			5570, 5639, 5640, 5641, 5642, 5651, 5652, 5653, 5654, 5655, 5656, 5657, 5658, 5659, 5660, 5661,
			5662, 5663, 5664, 5665, 5666, 5667, 5668, 5669, 5670, 5734, 5735, 5736, 5737, 6127, 6137, 6139,
			6141, 6143, 6189, 6191, 6199, 6201, 6203, 6205, 6217, 6227, 6229, 6235, 6237, 6265, 6285, 6287,
			6299, 6301, 6303, 6313, 6315, 6317, 6717, 6958, 7039, 7040, 7042, 7044, 7045, 7046, 7047, 7048,
			7049, 7050, 7051, 7052, 7053, 7054, 7055, 7056, 7057, 7058, 7059, 7060, 7061, 7062, 7063, 7064,
			7065, 7066, 7067, 7068, 7069, 7070, 7071, 7072, 7073, 7074, 7075, 7076, 7077, 7078, 7079, 7080,
			7081, 7082, 7083, 7084, 7085, 7101, 7102, 7103, 7104, 7105, 7106, 7112, 7113, 7114, 7115, 7116,
			7117, 7118, 7203, 7204, 7205, 7206, 7207, 7208, 7210, 7211, 7217, 7218, 7219, 7220, 7221, 7222,
			7224, 7225, 7226, 7227, 7228, 7229, 7230, 7232, 7233, 7234, 7235, 7236, 7237, 7238, 7239, 7240,
			7241, 7242, 7243, 7244, 7245, 7246, 7247, 7248, 7249, 7250, 7251, 7252, 7253, 7254, 7256, 7257,
			7258, 7259, 7260, 7261, 7262, 7263, 7264, 7265, 7266, 7267, 7268, 7269, 7270, 7271, 7272, 7273,
			7274, 7275, 7276, 7277, 7278, 7279, 7280, 7281, 7282, 7283, 7284, 7287, 7288, 7289, 7290, 7291,
			7292, 7297, 7298, 7299, 7300, 7301, 7302, 7304, 7305, 7307, 7308, 7309, 7310, 7311, 7312, 7313,
			7315, 7317, 7321, 7328, 7332, 7333, 7334, 7335, 7336, 7337, 7338, 7339, 7348, 7349, 7350, 7413,
			7414, 7415, 7482, 7483, 7486, 7487, 7492, 7499, 7500, 7501, 7502, 7503, 7504, 7505, 7506, 7507,
			7508, 7509, 7510, 7511, 7512, 7513, 7514, 7515, 7516, 7517, 7518, 7519, 7520, 7521, 7522, 7523,
			7524, 7525, 7526, 7527, 7528, 7529, 7530, 7531, 7532, 7533, 7534, 7535, 7536, 7537, 7538, 7539,
			7540, 7541, 7542, 7543, 7544, 7545, 7546, 7547, 7548, 7549, 7550, 7551, 7552, 7553, 7554, 7555,
			7556, 7557, 7558, 7559, 7560, 7561, 7562, 7563, 7564, 7565, 7566, 7567, 7568, 7569, 7570, 7571,
			7572, 7573, 7574, 7575, 7576, 7577, 7578, 7579, 7580, 7581, 7582, 7583, 7584, 7585, 7586, 7587,
			7588, 7589, 7590, 7591, 7592, 7593, 7594, 7595, 7596, 7597, 7598, 7599, 7600, 7601, 7602, 7605,
			7607, 7608, 7609, 7612, 7614, 7615, 7616, 7617, 7618, 7626, 7629, 7630, 7631, 7632, 7633, 7637,
			7638, 7642, 7643, 7644, 7662, 7663, 7675, 7676, 7677, 7678, 7691, 7693, 7697, 7701, 7702, 7705,
			7706, 7707, 7708, 7709, 7710, 7711, 7712, 7713, 7730, 7731, 7732, 7733, 7734, 7735, 7736, 7780,
			7781, 7782, 7783, 7784, 7785, 7802, 7809, 7810, 7821, 7822, 7823, 7824, 7826, 7829, 7830, 7831,
			7836, 7837, 7838, 7839, 7840, 7841, 7842, 7845, 7846, 7847, 7848, 7849, 7851, 7852, 7854, 7859,
			7860, 7861, 7862, 7863, 7864, 7865, 7866, 7867, 7868, 7869, 7870, 7871, 7872, 7873, 7874, 7875,
			7876, 7878, 7882, 7883, 7884, 7888, 7891, 7894, 7896, 7901, 7910, 7911, 7912, 7913, 7914, 7915,
			7916, 7918, 7919, 7922, 7923, 7924, 7925, 7926, 7930, 7932, 7933, 7934, 7935, 7936, 7937, 7938,
			7939, 7941, 7943, 7949, 7950, 7951, 7952, 7953, 7954, 7955, 7956, 7957, 7962, 7963, 7964, 7972,
			7973, 7984, 7985, 7987, 7990, 8002, 8003, 8004, 8028, 8029, 8030, 8031, 8032, 8033, 8041, 8042,
			8043, 8044, 8045, 8046, 8047, 8048, 8049, 8050, 8051, 8062, 8064, 8066, 8071, 8072, 8075, 8076,
			8077, 8079, 8080, 8081, 8087, 8088, 8096, 8097, 8098, 8099, 8100, 8101, 8102, 8103, 8107, 8108,
			8109, 8110, 8111, 8112, 8113, 8114, 8115, 8116, 8117, 8118, 8119, 8120, 8121, 8125, 8126, 8132,
			8136, 8137, 8138, 8139, 8140, 8141, 8142, 8143, 8154, 8155, 8156, 8159, 8160, 8161, 8162, 8178,
			8179, 8180, 8181, 8182, 8186, 8187, 8188, 8189, 8190, 8191, 8192, 8193, 8194, 8195, 8196, 8197,
			8198, 8199, 8200, 8201, 8202, 8203, 8204, 8267, 8268, 8271, 8274, 8276, 8280, 8281, 8283, 8288,
			8289, 8294, 8296, 8297, 8298, 8299, 8300, 8301, 8302, 8303, 8308, 8309, 8310, 8311, 8312, 8313,
			8314, 8315, 8330, 8333, 8334, 8335, 8336, 8337, 8338, 8341, 8343, 8344, 8345, 8346, 8347, 8348,
			8349, 8350, 8351, 8352, 8353, 8354, 8355, 8356, 8357, 8358, 8359, 8360, 8361, 8362, 8365, 8366,
			8367, 8368, 8369, 8370, 8371, 8372, 8373, 8374, 8375, 8376, 8377, 8378, 8379, 8380, 8396, 8397,
			8402, 8404, 8405, 8406, 8407, 8411, 8414, 8415, 8416, 8417, 8424, 8431, 8432, 8437, 8446, 8455,
			8456, 8457, 8462, 8470, 8472, 8474, 8475, 8476, 8477, 8478, 8497, 8500, 8501, 8508, 8515, 8516,
			8520, 8521, 8522, 8523, 8524, 8525, 8526, 8527, 8528, 8530, 8531, 8532, 8533, 8534, 8535, 8536,
			8537, 8538, 8540, 8541, 8543, 8544, 8545, 8546, 8547, 8548, 8549, 8550, 8551, 8552, 8553, 8554,
			8555, 8556, 8557, 8558, 8559, 8560, 8561, 8562, 8563, 8564, 8565, 8566, 8567, 8568, 8569, 8570,
			8571, 8572, 8573, 8574, 8575, 8576, 8577, 8578, 8579, 8580, 8581, 8582, 8583, 8584, 8585, 8586,
			8587, 8588, 8589, 8590, 8591, 8592, 8593, 8594, 8595, 8596, 8597, 8598, 8599, 8600, 8639, 8640,
			8642, 8647, 8650, 8653, 8654, 8655, 8656, 8657, 8658, 8659, 8660, 8661, 8662, 8663, 8664, 8665,
			8666, 8667, 8668, 8672, 8673, 8675, 8676, 8677, 8678, 8680, 8682, 8684, 8710, 8711, 8712, 8714,
			8717, 8718, 8719, 8720, 8724, 8725, 8726, 8727, 8728, 8729, 8730, 8731, 8736, 8737, 8740, 8742,
			8747, 8748, 8751, 8752, 8754, 8756, 8757, 8758, 8759, 8773, 8774, 8777, 8783, 8784, 8785, 8786,
			8787, 8788, 8789, 8791, 8796, 8803, 8806, 8807, 8810, 8814, 8819, 8820, 8821, 8826, 8833, 8837,
			8838, 8840, 8841, 8874, 8875, 8876, 8877, 8878, 8879, 8893, 8894, 8895, 8896, 8908, 8909, 8914,
			8929, 8931, 8932, 8933, 8934, 8935, 8936, 8937, 8938, 8939, 8940, 8941, 8942, 8943, 8944, 8945,
			8961, 8963, 8964, 8966, 8979, 8983, 8984, 8985, 8986, 8987, 8988, 8989, 8998, 9000, 9001, 9002,
			9003, 9009, 9010, 9011, 9012, 9013, 9019, 9031, 9038, 9039, 9040, 9045, 9049, 9050, 9057, 9066,
			9067, 9068, 9069, 9070, 9071, 9072, 9073, 9074, 9075, 9078, 9082, 9083, 9084, 9085, 9090, 9091,
			9092, 9096, 9097, 9098, 9099, 9100, 9101, 9102, 9103, 9107, 9108, 9109, 9110, 9111, 9112, 9113,
			9114, 9115, 9116, 9117, 9118, 9119, 9128, 9129, 9132, 9137, 9138, 9139, 9140, 9141, 9142, 9143,
			9144, 9145, 9149, 9150, 9151, 9152, 9153, 9154, 9155, 9156, 9157, 9158, 9159, 9160, 9161, 9162,
			9163, 9164, 9165, 9166, 9168, 9169, 9173, 9175, 9177, 10202, 10203, 10207, 10342, 10343, 10344, 10345,
			10346, 10607, 10608, 10844, 10966, 10967, 10975, 10977, 10978, 10980, 11099, 11100, 11116, 11194, 11241, 11243,
			11244, 11245, 11296, 11297, 11302, 11343, 11398, 11439, 11454, 11473, 11474, 11476, 11477, 11478, 11479, 11491,
			11500, 11502, 11504, 11509, 11510, 11511, 11512, 11513, 11580, 11587, 11601, 11602, 11609, 11610, 11611, 11612,
			11615, 11616, 11617, 11618, 11619, 11620, 11621, 11622, 11625, 11638, 11644, 11645, 11649, 11654, 11656, 11658,
			11663, 11686, 11687, 11690, 11691, 11692, 11694, 11697, 11698, 11699, 11700, 11701, 11702, 11703, 11706, 11712,
			11713, 11717, 11718, 11719, 11720, 11721, 11722, 11723, 11724, 11725, 11726, 11727, 11728, 11729, 11730, 11731,
			11732, 11733, 11734, 11735, 11736, 11737, 11744, 11747, 11748, 11757, 11762, 11768, 11769, 11770, 11772, 11774,
			11775, 11777, 11778, 11779, 11780, 11781, 11783, 11785, 11786, 11788, 11789, 11790, 11791, 11792, 11793, 11794,
			11795, 11816, 11817, 11818, 11819, 11839, 11840, 11844, 11845, 11846, 11847, 11851, 11853, 11854, 11865, 11866,
			11867, 11868, 11874, 11888, 11889, 11890, 11891, 11900, 11901, 11902, 11903, 11904, 11905, 11906, 11909, 11910,
			11911, 11912, 11913, 11915, 11916, 11917, 11919, 11920, 11921, 11922, 11923, 11924, 11925, 11926, 11927, 11928,
			11932, 11933, 11934, 11935, 11936, 11938, 11994, 11995, 11996, 11997, 11998, 11999, 12000, 12005, 12006, 12007,
			12008, 12009, 12010, 12012, 12013, 12014, 12015, 12016, 12017, 12018, 12019, 12020, 12021, 12022, 12023, 12024,
			12025, 12026, 12027, 12028, 12029, 12030, 12031, 12032, 12033, 12034, 12035, 12036, 12037, 12038, 12039, 12040,
			12041, 12042, 12043, 12044, 12045, 12047, 12048, 12049, 12050, 12051, 12052, 12053, 12054, 12055, 12056, 12057,
			12058, 12059, 12060, 12061, 12062, 12063, 12064, 12065, 12066, 12067, 12068, 12069, 12070, 12071, 12072, 12073,
			12074, 12075, 12076, 12077, 12078, 12079, 12080, 12081, 12082, 12083, 12084, 12085, 12086, 12087, 12088, 12089,
			12090, 12091, 12092, 12093, 12094, 12095, 12096, 12097, 12098, 12099, 12100, 12101, 12102, 12103, 12104, 12105,
			12106, 12107, 12108, 12109, 12110, 12111, 12112, 12113, 12114, 12115, 12116, 12117, 12118, 12119, 12120, 12121,
			12122, 12123, 12124, 12125, 12126, 12127, 12128, 12129, 12130, 12131, 12132, 12133, 12134, 12135, 12136, 12137,
			12138, 12139, 12141, 12142, 12143, 12144, 12145, 12146, 12147, 12148, 12149, 12150, 12151, 12152, 12153, 12154,
			12155, 12156, 12157, 12158, 12159, 12160, 12161, 12162, 12163, 12164, 12165, 12166, 12167, 12168, 12169, 12170,
			12171, 12172, 12173, 12174, 12175, 12176, 12177, 12178, 12184, 12185, 12187, 12188, 12189, 12190, 12197, 12198,
			12199, 12200, 12201, 12206, 12207, 12210, 12211, 12212, 12213, 12214, 12215, 12216, 12217, 12218, 12219, 12220,
			12221, 12222, 12223, 12224, 12225, 12226, 12227, 12228, 12229, 12230, 12231, 12232, 12233, 12234, 12235, 12236,
			12237, 12238, 12239, 12243, 12244, 12245, 12246, 12247, 12248, 12249, 12250, 12251, 12252, 12253, 12254, 12255,
			12256, 12257, 12258, 12259, 12260, 12261, 12262, 12263, 12264, 12265, 12266, 12267, 12268, 12269, 12270, 12271,
			12272, 12273, 12274, 12275, 12276, 12277, 12278, 12279, 12280, 12281, 12282, 12283, 12284, 12285, 12286, 12287,
			12288, 12289, 12290, 12291, 12292, 12293, 12294, 12295, 12296, 12297, 12298, 12299, 12300, 12301, 12302, 12303,
			12304, 12305, 12306, 12307, 12308, 12309, 12310, 12311, 12312, 12313, 12314, 12315, 12316, 12318, 12319, 12320,
			12321, 12322, 12323, 12324, 12325, 12326, 12327, 12328, 12329, 12330, 12331, 12332, 12333, 12334, 12335, 12336,
			12337, 12338, 12340, 12341, 12342, 12343, 12344, 12345, 12346, 12347, 12348, 12349, 12363, 12364, 12365, 12366,
			12426, 12427, 12428, 12430, 12431, 12432, 12433, 12434, 12435, 12443, 12455, 12463, 16015, 16298, 16299, 16300,
			16302, 16303, 16305, 16306, 16637, 19204, 19350, 19351, 19353, 19355, 19835, 19849, 20425, 20449, 20454, 20548,
			20557, 20559, 20560, 20564, 20571, 20574, 20578, 20579, 20589, 20611, 20613, 20620, 20625, 20627, 20628, 20637,
			20639, 20640, 20649, 20653, 20656, 20657, 20658, 20659, 20661, 20662, 20663, 20664, 20665, 20675, 20676, 20677,
			20678, 20679, 20680, 20681, 20682, 20685, 20686, 20688, 20689, 20690, 20706, 20708, 20724, 20729, 20731, 20732,
			20740, 20743, 20745, 20746, 20747, 20749, 20750, 20751, 20752, 20753, 20754, 20755, 20756, 20757, 20758, 20759,
			20760, 20761, 20762, 20763, 20764, 20766, 20767, 20768, 20769, 20770, 20771, 20772, 20773, 20774, 20778, 21067,
			21216, 21750, 21751, 21752, 21840, 21841, 21842, 21843, 21883, 21884, 22088, 22169, 22171, 22179, 22180, 22182,
			22183, 22184, 22186, 66529, 66530, 66531, 66540, 66548, 66555, 66570, 66578, 66587, 66589, 66604, 66606, 66607,
			66609, 66610, 66612, 66618, 66626, 66635, 66636, 66645, 66657, 66658, 66661, 66664, 66673, 66683, 66685, 66687,
			66688, 66693, 66694, 66696, 66699, 66700, 66701, 66702, 66705, 66706, 66707, 66740,
		};

		bool caused_error = false;
		uint32_t current_index = 0;
		for (_PVFV* current_pos = &unk_143285930; current_pos < &unk_143307FF8; current_pos++)
		{
			bool is_blacklisted = false;
			for (uint32_t blacklist_index : blacklist_indices)
			{
				if (current_index == blacklist_index)
				{
					goto next;
				}
			}

			if (_PVFV function = *current_pos)
			{
				try
				{
					function();
				}
				catch (...)
				{
					caused_error = true;
				}
			}

			next:
			current_index++;
		}

		blamboozle_run(output_directory.c_str(), L"halo5forge.exe", _engine_type_halo5);

		return __int64(caused_error ? 1 : 0);
}
};
c_data_patch<__scrt_common_main_seh_offset> __scrt_common_main_seh_patch =
{
	[](e_engine_type engine_type, e_build build, char*, DataPatchPackets& packets)
	{
		char* patch_address = GetEngineVirtualAddress(engine_type, 0x1410EB73B);

		static const uint8_t patch[] = { 0xC3 };
		packets.push_back(MAKE_DATAPATCHPACKET(patch_address, sizeof(patch)));
		memcpy_virtual(patch_address, patch, sizeof(patch));
	}
};


