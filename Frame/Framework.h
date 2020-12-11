#pragma once

#include "wx/wxprec.h"


#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/sizer.h"

namespace Elegance
{
	class Framework : public wxFrame
	{
	public:
		Framework(wxFrame* frame, const wxString& title, int x, int y, int w, int h);
		~Framework() {}

		// notifications
		void OnQuit(wxCommandEvent& event);
		void OnSize(wxSizeEvent& event);


		void InitLayout(int cx, int cy);

		wxDECLARE_EVENT_TABLE();

		HWND GetToolBarHWND();
		HWND GetLeftBarHWND();
		HWND GetCenterBarHWND();
		HWND GetRightBarHWND();

	protected:
	private:
		wxBoxSizer* m_pVerticalSizer = nullptr;
		wxPanel* m_pToolBar = nullptr;
		wxBoxSizer* m_pHorizontalSizer = nullptr;
		wxPanel* m_pLeftBar = nullptr;
		wxPanel* m_pCenterBar = nullptr;
		wxPanel* m_pRightBar = nullptr;
	};
}