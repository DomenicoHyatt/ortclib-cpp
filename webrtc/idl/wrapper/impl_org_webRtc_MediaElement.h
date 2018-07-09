
#pragma once

#include "types.h"
#include "generated/org_webRtc_MediaElement.h"

#ifdef __cplusplus_winrt
#include <windows.ui.xaml.controls.h>
#endif //__cplusplus_winrt

#ifdef CPPWINRT_VERSION
#include <winrt/Windows.UI.Xaml.Controls.h>
#endif // CPPWINRT_VERSION

namespace wrapper {
  namespace impl {
    namespace org {
      namespace webRtc {

        struct MediaElement : public wrapper::org::webRtc::MediaElement
        {
          ZS_DECLARE_TYPEDEF_PTR(wrapper::org::webRtc::MediaElement, WrapperType);
          ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::MediaElement, WrapperImplType);

          AnyPtr element_{};
          MediaElementWeakPtr thisWeak_;

          MediaElement() noexcept;
          virtual ~MediaElement() noexcept;


          // methods MediaElement
          void wrapper_init_org_webRtc_MediaElement(AnyPtr element) noexcept override;

          // properties MediaElement
          AnyPtr get_element() noexcept override;

#ifdef WINUWP
#ifdef __cplusplus_winrt
          ZS_NO_DISCARD() static wrapper::org::webRtc::MediaElementPtr toWrapper(Windows::UI::Xaml::Controls::MediaElement^ element) noexcept;
          ZS_NO_DISCARD() static Windows::UI::Xaml::Controls::MediaElement^ toNative_cx(wrapper::org::webRtc::MediaElementPtr element) noexcept;
#endif //__cplusplus_winrt
#ifdef CPPWINRT_VERSION
          ZS_NO_DISCARD() static wrapper::org::webRtc::MediaElementPtr toWrapper(winrt::Windows::UI::Xaml::Controls::MediaElement const & element) noexcept;
          ZS_NO_DISCARD() static winrt::Windows::UI::Xaml::Controls::MediaElement toNative_winrt(wrapper::org::webRtc::MediaElementPtr element) noexcept;
#endif // CPPWINRT_VERSION
#else
#ifdef _WIN32
          ZS_NO_DISCARD() static wrapper::org::webRtc::MediaElementPtr toWrapper(HWND element) noexcept;
          ZS_NO_DISCARD() static element toNative(wrapper::org::webRtc::MediaElementPtr element) noexcept;
#endif //_WIN32
#endif //WINUWP

        };

      } // webRtc
    } // org
  } // namespace impl
} // namespace wrapper

