#pragma once
#include "Scene/Manager.h"
#include "Scene/Canvas.h"
#include <map>

namespace Elegance
{
	namespace Scene
	{
		class ManagerImp : public Manager
		{
		public:
			virtual std::shared_ptr<Canvas> GetOrCreateCanvas(HWND hwnd) override;
			virtual void RemoveCanvas(HWND hwnd) override;
		protected:
		private:
			std::map<HWND, std::shared_ptr<Canvas>> m_mapCanvas;
		};
	}
}