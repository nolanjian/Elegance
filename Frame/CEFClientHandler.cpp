#include "CEFClientHandler.h"

namespace Elegance
{
	CEFClientHandler::CEFClientHandler()
	{

	}

	CEFClientHandler::~CEFClientHandler()
	{
	}

	void CEFClientHandler::OnAudioStreamStarted(CefRefPtr<CefBrowser> browser, const CefAudioParameters& params, int channels)
	{
	}
	void CEFClientHandler::OnAudioStreamPacket(CefRefPtr<CefBrowser> browser, const float** data, int frames, int64 pts)
	{
	}
	void CEFClientHandler::OnAudioStreamStopped(CefRefPtr<CefBrowser> browser)
	{
	}
	void CEFClientHandler::OnAudioStreamError(CefRefPtr<CefBrowser> browser, const CefString& message)
	{
	}

	void CEFClientHandler::OnBeforeDownload(CefRefPtr<CefBrowser> browser, CefRefPtr<CefDownloadItem> download_item, const CefString& suggested_name, CefRefPtr<CefBeforeDownloadCallback> callback)
	{
	}

	void CEFClientHandler::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect)
	{
	}
	void CEFClientHandler::OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer, int width, int height)
	{
	}

}