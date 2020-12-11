#pragma once

#include <include/cef_client.h>
#include <include/cef_base.h>

namespace Elegance
{
	class CEFClientHandler
		: public CefClient
		, public CefAudioHandler, public CefContextMenuHandler, public CefDialogHandler
		, public CefDisplayHandler, public CefDownloadHandler, public CefDragHandler
		, public CefFindHandler, public CefFocusHandler, public CefJSDialogHandler
		, public CefKeyboardHandler, public CefLifeSpanHandler, public CefLoadHandler
		, public CefRenderHandler, public CefRequestHandler
	{
	private:
		IMPLEMENT_REFCOUNTING(CEFClientHandler);
		DISALLOW_COPY_AND_ASSIGN(CEFClientHandler);
	public:
		CEFClientHandler();
		virtual ~CEFClientHandler();

		virtual CefRefPtr<CefAudioHandler> GetAudioHandler() override { return this; }
		virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() override { return this; }
		virtual CefRefPtr<CefDialogHandler> GetDialogHandler() override { return this; }
		virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override { return this; }
		virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() override { return this; }
		virtual CefRefPtr<CefDragHandler> GetDragHandler() override { return this; }
		virtual CefRefPtr<CefFindHandler> GetFindHandler() override { return this; }
		virtual CefRefPtr<CefFocusHandler> GetFocusHandler() override { return this; }
		virtual CefRefPtr<CefJSDialogHandler> GetJSDialogHandler() override { return this; }
		virtual CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() override { return this; }
		virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override { return this; }
		virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override { return this; }
		virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override { return this; }
		virtual CefRefPtr<CefRequestHandler> GetRequestHandler() { return nullptr; }

		virtual void OnAudioStreamStarted(CefRefPtr<CefBrowser> browser, const CefAudioParameters& params, int channels) override;
		virtual void OnAudioStreamPacket(CefRefPtr<CefBrowser> browser, const float** data, int frames, int64 pts) override;
		virtual void OnAudioStreamStopped(CefRefPtr<CefBrowser> browser) override;
		virtual void OnAudioStreamError(CefRefPtr<CefBrowser> browser, const CefString& message) override;

		virtual void OnBeforeDownload(CefRefPtr<CefBrowser> browser, CefRefPtr<CefDownloadItem> download_item, const CefString& suggested_name
			, CefRefPtr<CefBeforeDownloadCallback> callback) override;

		virtual void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
		virtual void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer, int width, int height) override;
		
		
	protected:
	private:
	};
}
