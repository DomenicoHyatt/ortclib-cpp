
#pragma once

#include "types.h"
#include "generated/org_ortc_adapter_MediaStream.h"

#include <ortc/adapter/IMediaStream.h>

namespace wrapper {
  namespace impl {
    namespace org {
      namespace ortc {
        namespace adapter {

          struct MediaStream : public wrapper::org::ortc::adapter::MediaStream,
                               public ::ortc::adapter::IMediaStreamDelegate
          {
            MediaStreamWeakPtr thisWeak_;

            ZS_DECLARE_TYPEDEF_PTR(::ortc::adapter::IMediaStream, IMediaStream);
            ZS_DECLARE_TYPEDEF_PTR(::ortc::IMediaStreamTrack, IMediaStreamTrack);
            ZS_DECLARE_TYPEDEF_PTR(::ortc::adapter::IMediaStreamDelegate, IMediaStreamDelegate);
            ZS_DECLARE_TYPEDEF_PTR(::ortc::adapter::IMediaStreamSubscription, IMediaStreamSubscription);

            IMediaStreamPtr native_;
            zsLib::Lock lock_;
            std::atomic<size_t> subscriptionCount_ {};
            bool defaultSubscription_ {true};
            IMediaStreamSubscriptionPtr subscription_;

            MediaStream() noexcept;
            virtual ~MediaStream() noexcept;

            // methods RTCStatsProvider
            virtual shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::RTCStatsReportPtr > > getStats(wrapper::org::ortc::RTCStatsTypeSetPtr statTypes) noexcept override;

            // methods MediaStream
            virtual void wrapper_init_org_ortc_adapter_MediaStream() noexcept override;
            virtual void wrapper_init_org_ortc_adapter_MediaStream(wrapper::org::ortc::adapter::MediaStreamPtr source) noexcept override;
            virtual void wrapper_init_org_ortc_adapter_MediaStream(shared_ptr< list< wrapper::org::ortc::MediaStreamTrackPtr > > tracks) noexcept override;
            virtual wrapper::org::ortc::MediaStreamTrackPtr getTrackById(String id) noexcept override;
            virtual void addTrack(wrapper::org::ortc::MediaStreamTrackPtr track) noexcept override;
            virtual void removeTrack(wrapper::org::ortc::MediaStreamTrackPtr track) noexcept override;
            virtual wrapper::org::ortc::adapter::MediaStreamPtr clone() noexcept override;

            // properties MediaStream
            virtual uint64_t get_objectId() noexcept override;
            virtual String get_id() noexcept override;
            virtual bool get_active() noexcept override;
            virtual shared_ptr< list< wrapper::org::ortc::MediaStreamTrackPtr > > get_tracks() noexcept override;
            virtual shared_ptr< list< wrapper::org::ortc::MediaStreamTrackPtr > > get_audioTracks() noexcept override;
            virtual shared_ptr< list< wrapper::org::ortc::MediaStreamTrackPtr > > get_videoTracks() noexcept override;
            virtual uint64_t get_count() noexcept override;

            virtual void wrapper_onObserverCountChanged(size_t count) noexcept override;

            virtual void onMediaStreamAddTrack(
                                               IMediaStreamPtr stream,
                                               IMediaStreamTrackPtr track
                                               ) noexcept override;
            virtual void onMediaStreamRemoveTrack(
                                                  IMediaStreamPtr stream,
                                                  IMediaStreamTrackPtr track
                                                  ) noexcept override;


            static ::wrapper::impl::org::ortc::adapter::MediaStreamPtr toWrapper(IMediaStreamPtr native) noexcept;
            static IMediaStreamPtr toNative(::wrapper::org::ortc::adapter::MediaStreamPtr wrapper) noexcept;

            void subscribe() noexcept;
          };

        } // adapter
      } // ortc
    } // org
  } // namespace impl
} // namespace wrapper

