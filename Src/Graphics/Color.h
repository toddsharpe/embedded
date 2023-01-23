#pragma once

#include <cstdint>

namespace Graphics
{
	struct RGB565
	{
		union
		{
			struct
			{
				uint16_t Red : 5;
				uint16_t Green : 6;
				uint16_t Blue : 5;
			};
			uint16_t AsUint16;
		};
	};
	static_assert(sizeof(RGB565) == sizeof(uint16_t), "Invalid color struct");

	namespace RGB565Colors
	{
		static constexpr RGB565 White = {.AsUint16 = 0xFFFF };
		static constexpr RGB565 Black = {.AsUint16 = 0x0000 };
		static constexpr RGB565 Blue = {.AsUint16 = 0x001F };
		static constexpr RGB565 Red = {.AsUint16 = 0xF800 };
		static constexpr RGB565 Magenta = {.AsUint16 = 0xF81F };
		static constexpr RGB565 Green = {.AsUint16 = 0x07E0 };
		static constexpr RGB565 Cyan = {.AsUint16 = 0x7FFF };
	}

	typedef RGB565 RGB565R;

	namespace RGB565RColors
	{
		//To support 16bit transfers, colors were converted to little endian, bytes reversed.
		static constexpr RGB565R White = {.AsUint16 = 0xFFFF };
		static constexpr RGB565R Black = {.AsUint16 = 0x0000 };
		static constexpr RGB565R Blue = {.AsUint16 = 0x1F00 };
		static constexpr RGB565R Red = {.AsUint16 = 0x00F8 };
		static constexpr RGB565R Magenta = {.AsUint16 = 0x1FF8 };
		static constexpr RGB565R Green = {.AsUint16 = 0xE007 };
		static constexpr RGB565R Cyan = {.AsUint16 = 0xFF7F };
	}

	//Select color mode
	//TODO(tsharpe): There's got to be a better way to do this without templating the entire graphics/ui library
	#if defined(COLOR_RGB565)
		typedef RGB565 Color;
		namespace Colors = RGB565Colors;
	#elif defined(COLOR_RGB565R)
		typedef RGB565R Color;
		namespace Colors = RGB565RColors;
	#else
		#error "No color mode selected"
	#endif
}
