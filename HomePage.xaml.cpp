#include "pch.h"
#include "HomePage.xaml.h"
#include <stdlib.h>
#include "Shobjidl.h"
#if __has_include("HomePage.g.cpp")
#include "HomePage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::DirectGB::implementation {
  HomePage::HomePage() {
    InitializeComponent();
  }

  void HomePage::OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e) {
    Window window = e.Parameter().as<Window>();
    m_window = window;
    winrt::com_ptr<IWindowNative> windowNative = window.as<IWindowNative>();

    //Get the HWND for the XAML Window
    windowNative->get_WindowHandle(&m_hWnd);
  }

  int32_t HomePage::MyProperty() {
    throw hresult_not_implemented();
  }

  void HomePage::MyProperty(int32_t /* value */) {
    throw hresult_not_implemented();
  }

  Windows::Foundation::IAsyncAction HomePage::loadRomButton_Click(IInspectable const&, RoutedEventArgs const&) {
    // open up a file picker
    auto picker = winrt::Windows::Storage::Pickers::FileOpenPicker();
    // set the suggested start page to the documents directory
    picker.SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId::DocumentsLibrary);
    
    // allow any file type to be used
    picker.FileTypeFilter().Append(L"*");

    picker.as<IInitializeWithWindow>()->Initialize(m_hWnd);
    auto file = co_await picker.PickSingleFileAsync();

    // now go to the play page
    MainWindow mainWindow = m_window.as<MainWindow>();
    mainWindow.ToPlayPage();
  }

  void HomePage::githubButton_Click(IInspectable const&, RoutedEventArgs const&) {
      
    // open up the browser to the GitHub page
    system("start https://github.com/jamesbmadden/DirectGB");

  }
}
