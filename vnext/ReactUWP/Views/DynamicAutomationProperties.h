// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <winrt/Windows.UI.Xaml.h>

#include "DynamicAutomationProperties.g.h"

#ifndef PROJECT_ROOT_NAMESPACE
#define PROJECT_ROOT_NAMESPACE react::uwp
#else
namespace winrt::Microsoft::ReactNative {}
namespace winrt::react::uwp {
using namespace winrt::Microsoft::ReactNative;
}
#endif

namespace winrt::PROJECT_ROOT_NAMESPACE::implementation {

//
// DynamicAutomationProperties provides attached properties for the various
// accessibility related properties in RN that will be used by
// DynamicAutomationPeer
//
struct DynamicAutomationProperties : DynamicAutomationPropertiesT<DynamicAutomationProperties> {
  using Super = DynamicAutomationPropertiesT<DynamicAutomationProperties>;

 public:
  DynamicAutomationProperties() = delete;

  // Attached Properties

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityRoleProperty();
  static void SetAccessibilityRole(
      winrt::Windows::UI::Xaml::UIElement const &element,
      winrt::PROJECT_ROOT_NAMESPACE::AccessibilityRoles const &value);
  static AccessibilityRoles GetAccessibilityRole(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityStateSelectedProperty();
  static void SetAccessibilityStateSelected(winrt::Windows::UI::Xaml::UIElement const &element, bool value);
  static bool GetAccessibilityStateSelected(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityStateDisabledProperty();
  static void SetAccessibilityStateDisabled(winrt::Windows::UI::Xaml::UIElement const &element, bool value);
  static bool GetAccessibilityStateDisabled(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityStateCheckedProperty();
  static void SetAccessibilityStateChecked(winrt::Windows::UI::Xaml::UIElement const &element, bool value);
  static bool GetAccessibilityStateChecked(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityStateUncheckedProperty();
  static void SetAccessibilityStateUnchecked(winrt::Windows::UI::Xaml::UIElement const &element, bool value);
  static bool GetAccessibilityStateUnchecked(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityStateBusyProperty();
  static void SetAccessibilityStateBusy(winrt::Windows::UI::Xaml::UIElement const &element, bool value);
  static bool GetAccessibilityStateBusy(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityStateExpandedProperty();
  static void SetAccessibilityStateExpanded(winrt::Windows::UI::Xaml::UIElement const &element, bool value);
  static bool GetAccessibilityStateExpanded(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityStateCollapsedProperty();
  static void SetAccessibilityStateCollapsed(winrt::Windows::UI::Xaml::UIElement const &element, bool value);
  static bool GetAccessibilityStateCollapsed(winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityInvokeEventHandlerProperty();
  static void SetAccessibilityInvokeEventHandler(
      Windows::UI::Xaml::UIElement const &element,
      winrt::PROJECT_ROOT_NAMESPACE::AccessibilityInvokeEventHandler const &value);
  static winrt::PROJECT_ROOT_NAMESPACE::AccessibilityInvokeEventHandler GetAccessibilityInvokeEventHandler(
      winrt::Windows::UI::Xaml::UIElement const &element);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityActionsProperty();

  static void SetAccessibilityActions(
      Windows::UI::Xaml::UIElement const &element,
      Windows::Foundation::Collections::IVector<PROJECT_ROOT_NAMESPACE::AccessibilityAction> const &value);

  static Windows::Foundation::Collections::IVector<PROJECT_ROOT_NAMESPACE::AccessibilityAction> GetAccessibilityActions(
      Windows::UI::Xaml::UIElement const &element);

  static void DispatchAccessibilityAction(
      Windows::UI::Xaml::UIElement const &element,
      std::wstring_view const &actionName);

  static winrt::Windows::UI::Xaml::DependencyProperty AccessibilityActionEventHandlerProperty();
  static void SetAccessibilityActionEventHandler(
      Windows::UI::Xaml::UIElement const &element,
      winrt::PROJECT_ROOT_NAMESPACE::AccessibilityActionEventHandler const &value);
  static winrt::PROJECT_ROOT_NAMESPACE::AccessibilityActionEventHandler GetAccessibilityActionEventHandler(
      winrt::Windows::UI::Xaml::UIElement const &element);
};

} // namespace winrt::PROJECT_ROOT_NAMESPACE::implementation

namespace winrt::PROJECT_ROOT_NAMESPACE::factory_implementation {
struct DynamicAutomationProperties
    : DynamicAutomationPropertiesT<DynamicAutomationProperties, implementation::DynamicAutomationProperties> {};
} // namespace winrt::PROJECT_ROOT_NAMESPACE::factory_implementation

namespace react::uwp {
// Issue #2172: Calling static members on
// winrt::react::uwp::DynamicAutomationProperties fails to call
// down into winrt::react::uwp::implementation::DynamicAutomationProperties
// because of how we're
// using cppwinrt. This workaround is so that consumers in react::uwp can just
// call DynamicAutomationProperties

using DynamicAutomationProperties = winrt::PROJECT_ROOT_NAMESPACE::implementation::DynamicAutomationProperties;
} // namespace react::uwp
