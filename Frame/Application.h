#pragma once

#include "wx/wxprec.h"

#include <wx/app.h>

#include "framework.h"

namespace Elegance 
{
	class Application : public wxApp
	{
	public:
		Application();
		virtual ~Application();

		virtual bool OnInit() override;
		virtual int OnExit() override;

	private:
		Framework* m_pFramework = nullptr;
	};
}