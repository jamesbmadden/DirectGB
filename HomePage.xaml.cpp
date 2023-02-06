#include "pch.h"
#include "HomePage.xaml.h"
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

  void HomePage::loadRomButton_Click(IInspectable const&, RoutedEventArgs const&) {
    // myButton().Content(box_value(L"Clicked"));
  }

  void HomePage::githubButton_Click(IInspectable const&, RoutedEventArgs const&) {
      
    

  }
}
