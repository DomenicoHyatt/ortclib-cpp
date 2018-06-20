
#pragma once

#include "types.h"
#include "generated/org_ortc_MediaTrackSettings.h"

#include <ortc/IMediaStreamTrack.h>

namespace wrapper {
  namespace impl {
    namespace org {
      namespace ortc {

        struct MediaTrackSettings : public wrapper::org::ortc::MediaTrackSettings
        {
          ZS_DECLARE_TYPEDEF_PTR(::ortc::IMediaStreamTrackTypes::Settings, Settings);

          MediaTrackSettingsWeakPtr thisWeak_;

          MediaTrackSettings() noexcept;
          virtual ~MediaTrackSettings() noexcept;

          // methods MediaTrackSettings
          virtual void wrapper_init_org_ortc_MediaTrackSettings() noexcept override;
          virtual void wrapper_init_org_ortc_MediaTrackSettings(wrapper::org::ortc::MediaTrackSettingsPtr source) noexcept override;
          virtual void wrapper_init_org_ortc_MediaTrackSettings(wrapper::org::ortc::JsonPtr json) noexcept override;
          virtual wrapper::org::ortc::JsonPtr toJson() noexcept override;
          virtual String hash() noexcept override;

          static MediaTrackSettingsPtr toWrapper(SettingsPtr native) noexcept;
          static SettingsPtr toNative(MediaTrackSettingsPtr wrapper) noexcept;
        };

      } // ortc
    } // org
  } // namespace impl
} // namespace wrapper

