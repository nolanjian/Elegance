#pragma once
#include "Scene/Scene.h"
#include <windows.h>

namespace Elegance
{
	namespace Scene
	{
		class SCENE_API Canvas
		{
		public:
			virtual ~Canvas() {}
			Canvas() {}
			Canvas(HWND hwnd) {}
			Canvas(const Canvas&) = delete;
			Canvas(const Canvas&&) = delete;
			Canvas& operator= (const Canvas&) = delete;
			Canvas& operator= (const Canvas&&) = delete;

			virtual bool Run() = 0;
			virtual bool Stop() = 0;
		};
	}
}