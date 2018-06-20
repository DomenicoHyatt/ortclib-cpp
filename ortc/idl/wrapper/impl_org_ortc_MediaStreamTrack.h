
#pragma once

#include "types.h"
#include "generated/org_ortc_MediaStreamTrack.h"

#include <ortc/IMediaStreamTrack.h>

namespace wrapper {
  namespace impl {
    namespace org {
      namespace ortc {

        struct MediaStreamTrack : public wrapper::org::ortc::MediaStreamTrack,
                                  public ::ortc::IMediaStreamTrackDelegate
        {
          ZS_DECLARE_TYPEDEF_PTR(::ortc::IMediaStreamTrack, NativeType);
          ZS_DECLARE_TYPEDEF_PTR(::ortc::IMediaStreamTrack, IMediaStreamTrack);
          ZS_DECLARE_TYPEDEF_PTR(::ortc::IMediaStreamTrackSubscription, NativeTypeSubscription);
          ZS_DECLARE_TYPEDEF_PTR(MediaStreamTrack, WrapperImplType);
          ZS_DECLARE_TYPEDEF_PTR(wrapper::org::ortc::MediaStreamTrack, WrapperType);

          MediaStreamTrackWeakPtr thisWeak_;
          NativeTypePtr native_;
          zsLib::Lock lock_;
          std::atomic<size_t> subscriptionCount_{};
          bool defaultSubscription_ {true};
          NativeTypeSubscriptionPtr subscription_;
          MediaSourcePtr mediaSource_;

          MediaStreamTrack() noexcept;
          virtual ~MediaStreamTrack() noexcept;

          // methods MediaStreamTrack
          virtual wrapper::org::ortc::MediaStreamTrackPtr clone() noexcept override;
          virtual void stop() noexcept override;
          virtual wrapper::org::ortc::MediaTrackCapabilitiesPtr getCapabilities() noexcept override;
          virtual wrapper::org::ortc::MediaTrackConstraintsPtr getConstraints() noexcept override;
          virtual wrapper::org::ortc::MediaTrackSettingsPtr getSettings() noexcept override;
          virtual PromisePtr applyConstraints(wrapper::org::ortc::MediaTrackConstraintsPtr constraints) noexcept override;

          // properties MediaStreamTrack
          virtual uint64_t get_objectId() noexcept override;
          virtual wrapper::org::ortc::MediaStreamTrackKind get_kind() noexcept override;
          virtual String get_id() noexcept override;
          virtual String get_deviceId() noexcept override;
          virtual String get_label() noexcept override;
          virtual bool get_enabled() noexcept override;
          virtual void set_enabled(bool value) noexcept override;
          virtual bool get_muted() noexcept override;
          virtual void set_muted(bool value) noexcept override;
          virtual bool get_remote() noexcept override;
          virtual wrapper::org::ortc::MediaStreamTrackState get_readyState() noexcept override;
          virtual wrapper::org::ortc::MediaSourcePtr get_source() noexcept override;

          virtual void wrapper_onObserverCountChanged(size_t count) noexcept override;

          // IMediaStreamTrackDelegate
          virtual void onMediaStreamTrackMute(
                                              IMediaStreamTrackPtr track,
                                              bool isMuted
                                              ) noexcept override;

          virtual void onMediaStreamTrackEnded(IMediaStreamTrackPtr track) noexcept override;
          virtual void onMediaStreamTrackOverConstrained(
                                                         IMediaStreamTrackPtr track,
                                                         OverconstrainedErrorPtr error
                                                         ) noexcept override;

          static WrapperImplTypePtr toWrapper(NativeTypePtr track) noexcept;
          static NativeTypePtr toNative(WrapperTypePtr wrapper) noexcept;

          void subscribe() noexcept;
        };


      } // ortc
    } // org
  } // namespace impl
} // namespace wrapper

