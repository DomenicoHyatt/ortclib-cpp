
#pragma once

#include "types.h"
#include "generated/org_webRtc_MillisecondIntervalRange.h"

#include "impl_org_webRtc_pre_include.h"
#include "rtc_base/scoped_ref_ptr.h"
#include "impl_org_webRtc_post_include.h"

namespace wrapper {
  namespace impl {
    namespace org {
      namespace webRtc {

        struct MillisecondIntervalRange : public wrapper::org::webRtc::MillisecondIntervalRange
        {
          ZS_DECLARE_TYPEDEF_PTR(wrapper::org::webRtc::MillisecondIntervalRange, WrapperType);
          ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::MillisecondIntervalRange, WrapperImplType);
          ZS_DECLARE_TYPEDEF_PTR(::rtc::IntervalRange, NativeType);

          MillisecondIntervalRangeWeakPtr thisWeak_;

          MillisecondIntervalRange() noexcept;
          virtual ~MillisecondIntervalRange() noexcept;


          // methods MillisecondIntervalRange
          void wrapper_init_org_webRtc_MillisecondIntervalRange() noexcept override;
          void wrapper_init_org_webRtc_MillisecondIntervalRange(wrapper::org::webRtc::MillisecondIntervalRangePtr source) noexcept override;

          ZS_NO_DISCARD() static WrapperImplTypePtr toWrapper(const NativeType &native) noexcept;
          ZS_NO_DISCARD() static WrapperImplTypePtr toWrapper(NativeTypePtr native) noexcept;

          ZS_NO_DISCARD() static NativeTypePtr toNative(WrapperTypePtr wrapper) noexcept;
        };

      } // webRtc
    } // org
  } // namespace impl
} // namespace wrapper

