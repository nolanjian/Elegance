#include "Application.h"
#

namespace Elegance
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	bool Application::OnInit()
	{
		if (!wxApp::OnInit())
		{
			return false;
		}

		if (!m_pFramework)
		{
			m_pFramework = new Framework(nullptr, "Elegance", 0, 0, 0, 0);
		}
		if (m_pFramework)
		{
			m_pFramework->Show(true);
		}

		return true;
	}
	int Application::OnExit()
	{
		wxApp::OnExit();
		return 0;
	}
}