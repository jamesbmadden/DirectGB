// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#pragma once

#include "PlayPage.g.h"

namespace winrt::DirectGB::implementation
{
    struct PlayPage : PlayPageT<PlayPage>
    {
        PlayPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::DirectGB::factory_implementation
{
    struct PlayPage : PlayPageT<PlayPage, implementation::PlayPage>
    {
    };
}
