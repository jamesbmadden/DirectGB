#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#include <winrt/Microsoft.UI.Interop.h>
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Composition;
using namespace Microsoft::UI::Composition::SystemBackdrops;

namespace winrt::DirectGB::implementation {
  MainWindow::MainWindow() {
    InitializeComponent();

    this->Title(L"DirectGB");

    m_mainAppWindow = GetAppWindowForCurrentWindow();

    // add the mica controller!
    SetBackground();

    int dip = GetDpiForWindow(m_hWnd) / 96;

    // set the size of the window
    // make sure its adjusted for the dpi
    Windows::Graphics::SizeInt32 size;
    size.Height = 448 * dip;
    size.Width = 300 * dip;

    m_mainAppWindow.ResizeClient(size);

    // disable the default titlebar and replace it
    m_mainAppWindow.TitleBar().ExtendsContentIntoTitleBar(true);
    m_mainAppWindow.TitleBar().ButtonBackgroundColor(Microsoft::UI::Colors::Transparent());
    m_mainAppWindow.TitleBar().ButtonInactiveBackgroundColor(Microsoft::UI::Colors::Transparent());
    // use the 48px title bar instead of the default 32px one to match modern apps
    m_mainAppWindow.TitleBar().PreferredHeightOption(Microsoft::UI::Windowing::TitleBarHeightOption::Tall);
    // disable resizing
    Microsoft::UI::Windowing::OverlappedPresenter presenter = Microsoft::UI::Windowing::OverlappedPresenter::Create();
    presenter.IsResizable(false);
    presenter.IsMaximizable(false);
    m_mainAppWindow.SetPresenter(presenter);

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
    // enable resizing on this page
    Microsoft::UI::Windowing::OverlappedPresenter presenter = Microsoft::UI::Windowing::OverlappedPresenter::Create();
    m_mainAppWindow.SetPresenter(presenter);
  }

  // apply a mica background
  void MainWindow::SetBackground() {

    // only if mica is supported
    if (MicaController::IsSupported()) {

      // make sure we have a Dispatcher Queue
      EnsureDispatcher();

      m_backdropController = MicaController();
      SystemBackdropConfiguration config = SystemBackdropConfiguration();
      // set this window as the target for the controller
      m_backdropController.SetSystemBackdropConfiguration(config);
      m_backdropController.AddSystemBackdropTarget(this->try_as<ICompositionSupportsSystemBackdrop>());

    }

  }

  void MainWindow::EnsureDispatcher() {

    // if there already is one, we're good
    if (nullptr != winrt::Windows::System::DispatcherQueue::GetForCurrentThread() || nullptr != m_dispatcherQueueController) {
      return;
    }

    // otherwise, make one!
    DispatcherQueueOptions options { sizeof(DispatcherQueueOptions), DQTYPE_THREAD_CURRENT, DQTAT_COM_NONE };

    ::ABI::Windows::System::IDispatcherQueueController* ptr{ nullptr };
    winrt::check_hresult(CreateDispatcherQueueController(options, &ptr));
    m_dispatcherQueueController = { ptr, take_ownership_from_abi };

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
