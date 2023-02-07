#pragma once

#include "MainWindow.g.h"

namespace winrt::DirectGB::implementation {
  struct MainWindow : MainWindowT<MainWindow> {
    MainWindow();

    int32_t MyProperty();
    void MyProperty(int32_t value);
    void ToPlayPage();

    private:
      void SetBackground();
      void EnsureDispatcher();
      winrt::Microsoft::UI::Windowing::AppWindow GetAppWindowForCurrentWindow();
      winrt::Microsoft::UI::Windowing::AppWindow m_mainAppWindow{ nullptr };
      winrt::Microsoft::UI::Composition::SystemBackdrops::MicaController m_backdropController{ nullptr };
      winrt::Microsoft::UI::Composition::SystemBackdrops::SystemBackdropConfiguration m_backdropConfiguration{ nullptr };
      winrt::Windows::System::DispatcherQueueController m_dispatcherQueueController{ nullptr };
      HWND m_hWnd;
  };
}

namespace winrt::DirectGB::factory_implementation {
  struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow> {};
}
