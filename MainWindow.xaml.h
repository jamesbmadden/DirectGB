#pragma once

#include "MainWindow.g.h"

namespace winrt::DirectGB::implementation {
  struct MainWindow : MainWindowT<MainWindow> {
    MainWindow();

    int32_t MyProperty();
    void MyProperty(int32_t value);

    private:
      winrt::Microsoft::UI::Windowing::AppWindow GetAppWindowForCurrentWindow();
      winrt::Microsoft::UI::Windowing::AppWindow m_mainAppWindow{ nullptr };
      HWND m_hWnd;
  };
}

namespace winrt::DirectGB::factory_implementation {
  struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow> {};
}
