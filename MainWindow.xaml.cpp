#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#include <winrt/Microsoft.UI.Interop.h>
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::DirectGB::implementation {
  MainWindow::MainWindow() {
    InitializeComponent();

    this->Title(L"DirectGB");

    m_mainAppWindow = GetAppWindowForCurrentWindow();

    int dpi = 2;

    // set the size of the window
    Windows::Graphics::SizeInt32 size;
    size.Height = 400 * dpi;
    size.Width = 300 * dpi;

    m_mainAppWindow.ResizeClient(size);

    // disable the default titlebar and replace it
    m_mainAppWindow.TitleBar().ExtendsContentIntoTitleBar(true);
    m_mainAppWindow.TitleBar().ButtonBackgroundColor(Microsoft::UI::Colors::Transparent());

    ContentFrame().Navigate(xaml_typename<winrt::DirectGB::HomePage>(), *this);
  }

  int32_t MainWindow::MyProperty() {
    throw hresult_not_implemented();
  }

  void MainWindow::MyProperty(int32_t /* value */) {
    throw hresult_not_implemented();
  }

  // change to the play page
  void MainWindow::ToPlayPage() {
    ContentFrame().Navigate(xaml_typename<winrt::DirectGB::PlayPage>(), *this);
  }

  winrt::Microsoft::UI::Windowing::AppWindow MainWindow::GetAppWindowForCurrentWindow() {
    // Get access to IWindowNative
    winrt::DirectGB::MainWindow thisWindow = *this;
    winrt::com_ptr<IWindowNative> windowNative = thisWindow.as<IWindowNative>();

    //Get the HWND for the XAML Window
    windowNative->get_WindowHandle(&m_hWnd);

    // Get the WindowId for our window
    winrt::Microsoft::UI::WindowId windowId;
    windowId = winrt::Microsoft::UI::GetWindowIdFromWindow(m_hWnd);

    // Get the AppWindow for the WindowId
    Microsoft::UI::Windowing::AppWindow appWindow = Microsoft::UI::Windowing::AppWindow::GetFromWindowId(windowId);

    return appWindow;
  }
}
