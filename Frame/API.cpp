#include "API.h"
#include "Application.h"
#include "CEFApplication.h"


/// CEF
//////////////////////////////////////////////////////////////////////////
#include "include/cef_app.h"

wxIMPLEMENT_APP_NO_MAIN(Elegance::Application);

extern "C" {

	WXFRAME_API int RunApp(int argc, char* argv[])
	{
		CefEnableHighDPISupport();

		HINSTANCE hInstance = ::GetModuleHandle(NULL);
		std::wstring wstCMD = ::GetCommandLineW();

		CefMainArgs main_args(hInstance);

		// Parse command-line arguments.
		CefRefPtr<CefCommandLine> command_line = CefCommandLine::CreateCommandLine();
		command_line->InitFromString(wstCMD);

		// Create a ClientApp of the correct type.
		CefRefPtr<CefApp> app = new Elegance::CEFApplication();

		if (!command_line->HasSwitch("type"))
		{
			MessageBoxA(nullptr, "browser", "browser", MB_OK);
		}
		else
		{
			const std::string& process_type = command_line->GetSwitchValue("type");
			MessageBoxA(nullptr, process_type.c_str(), process_type.c_str(), MB_OK);
		}

		// Execute the secondary process, if any.
		int exit_code = CefExecuteProcess(main_args, app, nullptr);
		if (exit_code >= 0)
			return exit_code;

		// Browser Process here
		CefSettings settings;
		settings.multi_threaded_message_loop = true;

		if (!CefInitialize(main_args, settings, app, nullptr))
			return false;

		wxEntry();

		CefShutdown();

		return 0;
	}
}
