#pragma once

#include "HomePage.g.h"

namespace winrt::DirectGB::implementation {
  struct HomePage : HomePageT<HomePage> {
    HomePage();

    int32_t MyProperty();
    void MyProperty(int32_t value);

    Windows::Foundation::IAsyncAction loadRomButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    void githubButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    void OnNavigatedTo(Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e);

    private:
      HWND m_hWnd;
      Microsoft::UI::Xaml::Window m_window;
  };
}

namespace winrt::DirectGB::factory_implementation {
  struct HomePage : HomePageT<HomePage, implementation::HomePage> {};
}
