#include "pch.h"
#include "Scene/ManagerImp.h"
#include "Scene/CanvasImp.h"
#include <memory>

namespace Elegance
{
	namespace Scene
	{
		std::shared_ptr<Canvas> ManagerImp::GetOrCreateCanvas(HWND hwnd)
		{
			if (m_mapCanvas.find(hwnd) == m_mapCanvas.end())
			{
				m_mapCanvas[hwnd] = std::make_shared<CanvasImp>(hwnd);
			}

			return m_mapCanvas[hwnd];
		}
		void ManagerImp::RemoveCanvas(HWND hwnd)
		{
			m_mapCanvas.erase(hwnd);
		}
	}
}
