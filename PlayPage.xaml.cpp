// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "PlayPage.xaml.h"
#if __has_include("PlayPage.g.cpp")
#include "PlayPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::DirectGB::implementation
{
    PlayPage::PlayPage()
    {
        InitializeComponent();
    }

    int32_t PlayPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void PlayPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void PlayPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
