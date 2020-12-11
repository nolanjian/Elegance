#include "Framework.h"


wxBEGIN_EVENT_TABLE(Elegance::Framework, wxFrame)
EVT_SIZE(Elegance::Framework::OnSize)
wxEND_EVENT_TABLE()

namespace Elegance
{
	Framework::Framework(wxFrame* frame, const wxString& title, int x, int y, int w, int h)
		: wxFrame(frame, wxID_ANY, title, wxPoint(x, y), wxSize(w, h), wxDEFAULT_FRAME_STYLE | wxMAXIMIZE)
	{
		// create the status line
		const int widths[] = { -1, 60 };
		CreateStatusBar(2);
		SetStatusWidths(2, widths);
		SetStatusText("no selection", 0);

		RECT rect;
		SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
		int cx = rect.right - rect.left;
		int cy = rect.bottom - rect.top;
		//auto rat = cx * 1.0 / (cy * 1.0);
		//cx *= 0.8;
		//cy = cx * 1.0 / rat;

		InitLayout(cx, cy);
		Fit();

		wxSize minSize(cx * 0.5, cy * 0.5);
		SetMinSize(minSize);
	}

	void Framework::OnQuit(wxCommandEvent& event)
	{
		Close(true);
	}

	void Framework::OnSize(wxSizeEvent& event)
	{
		wxSize sc = GetClientSize();
		InitLayout(sc.x, sc.y);
		Layout();
	}

	void Framework::InitLayout(int cx, int cy)
	{
		if (!m_pVerticalSizer)
		{
			m_pVerticalSizer = new wxBoxSizer(wxVERTICAL);
			SetSizer(m_pVerticalSizer);
			m_pVerticalSizer->SetSizeHints(this);
		}

		if (!m_pToolBar)
		{
			m_pToolBar = new wxPanel(this);
			m_pVerticalSizer->Add(m_pToolBar);
		}
		m_pToolBar->SetMinClientSize(wxSize(cx, cy * 1.0 / 5.0));

		if (!m_pHorizontalSizer)
		{
			m_pHorizontalSizer = new wxBoxSizer(wxHORIZONTAL);
			m_pVerticalSizer->Add(m_pHorizontalSizer);
		}

		if (!m_pLeftBar)
		{
			m_pLeftBar = new wxPanel(this);
			m_pHorizontalSizer->Add(m_pLeftBar);
		}
		m_pLeftBar->SetMinClientSize(wxSize(cx * 1.0 / 6.0, cy * 4.0 / 5.0));

		if (!m_pCenterBar)
		{
			m_pCenterBar = new wxPanel(this);
			m_pHorizontalSizer->Add(m_pCenterBar);
		}
		m_pCenterBar->SetMinClientSize(wxSize(cx * 4.0 / 6.0, cy * 4.0 / 5.0));

		if (!m_pRightBar)
		{
			m_pRightBar = new wxPanel(this);
			m_pHorizontalSizer->Add(m_pRightBar);
		}
		m_pRightBar->SetMinClientSize(wxSize(cx * 1.0 / 6.0, cy * 4.0 / 5.0));
	}

	HWND Elegance::Framework::GetToolBarHWND()
	{
		if (m_pToolBar)
		{
			return m_pToolBar->GetHWND();
		}
		return 0;
	}
	HWND Elegance::Framework::GetLeftBarHWND()
	{
		if (m_pLeftBar)
		{
			return m_pLeftBar->GetHWND();
		}
		return 0;
	}
	HWND Elegance::Framework::GetCenterBarHWND()
	{
		if (m_pCenterBar)
		{
			return m_pCenterBar->GetHWND();
		}
		return 0;
	}
	HWND Elegance::Framework::GetRightBarHWND()
	{
		if (m_pRightBar)
		{
			return m_pRightBar->GetHWND();
		}
		return 0;
	}
}


