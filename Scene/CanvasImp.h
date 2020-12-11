#pragma once

#include "Scene/CanvasImp.h"
#include "Scene/ManagerImp.h"

namespace Elegance
{
	namespace Scene
	{
		class CanvasImp : public Canvas
		{
			friend class ManagerImp;
		public:
			CanvasImp(HWND hwnd);
			virtual ~CanvasImp();

			virtual bool Run() override;
			virtual bool Stop() override;

		protected:
		private:
			HWND m_hwnd = NULL;
		};
	}
}