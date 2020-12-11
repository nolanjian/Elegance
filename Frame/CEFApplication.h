#pragma once

#include "include/cef_app.h"

namespace Elegance
{
	class CEFApplication : public CefApp, public CefBrowserProcessHandler
	{
	public:
		CEFApplication();

		virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
			return this;
		}

		IMPLEMENT_REFCOUNTING(CEFApplication);
		DISALLOW_COPY_AND_ASSIGN(CEFApplication);
	protected:
	private:
	};
}