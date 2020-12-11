#include "pch.h"
#include "CanvasImp.h"

namespace Elegance
{
	namespace Scene
	{
		CanvasImp::CanvasImp(HWND hwnd)
			: m_hwnd(hwnd)
		{

		}
		CanvasImp::~CanvasImp()
		{
		}
		bool CanvasImp::Run()
		{
			return false;
		}
		bool CanvasImp::Stop()
		{
			return false;
		}
	}
}
