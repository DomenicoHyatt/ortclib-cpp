// Generated by zsLibEventingTool

#pragma once

#include "types.h"
#include "generated/org_ortc_MediaSource.h"


namespace wrapper {
  namespace impl {
    namespace org {
      namespace ortc {

        struct MediaSource : public wrapper::org::ortc::MediaSource
        {
          MediaSourceWeakPtr thisWeak_;
          MediaStreamTrackPtr track_;

          zsLib::Lock lock_;
          AnyPtr source_;

          MediaSource() noexcept;
          virtual ~MediaSource() noexcept;
          virtual void wrapper_init_org_ortc_MediaSource() noexcept override;

          // properties MediaSource
          virtual AnyPtr get_source() noexcept override;
          virtual void set_source(AnyPtr value) noexcept override;
          virtual AnyPtr get_track() noexcept override;

          static MediaSourcePtr createWithTrack(MediaStreamTrackPtr track) noexcept;
        };

      } // ortc
    } // org
  } // namespace impl
} // namespace wrapper

