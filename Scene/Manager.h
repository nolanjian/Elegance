#pragma once

#include "Scene/Scene.h"
#include "Scene/Canvas.h"
#include <memory>
#include <windows.h>

namespace Elegance
{
	namespace Scene
	{
		class SCENE_API Manager
		{
		public:
			Manager() {}
			Manager(const Manager&) = delete;
			Manager(const Manager&&) = delete;
			Manager& operator= (const Manager&) = delete;
			Manager& operator= (const Manager&&) = delete;

			static Manager& Get();

			virtual std::shared_ptr<Canvas> GetOrCreateCanvas(HWND hwnd) = 0;
			virtual void RemoveCanvas(HWND hwnd) = 0;

		protected:
		private:
		};
	}
}