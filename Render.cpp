#include "pch.h"
#include "Render.h"
#include <d3d12.h>
#include <dxgi1_6.h>

using namespace winrt;

class Render {

  private:
    // objects for DirectX
    winrt::com_ptr<IDXGISwapChain3> m_swapChain;

  public:
    // just a test method :)
    static winrt::param::hstring getTitle() {
      return L"DirectGB";
    }

};