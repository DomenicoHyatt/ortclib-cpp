
#include "impl_org_ortc_RTCIceGatherer.h"
#include "impl_org_ortc_RTCIceCandidate.h"
#include "impl_org_ortc_RTCIceParameters.h"
#include "impl_org_ortc_RTCIceGatherOptions.h"
#include "impl_org_ortc_RTCIceGathererStateChangeEvent.h"
#include "impl_org_ortc_RTCIceGathererCandidateEvent.h"
#include "impl_org_ortc_RTCIceGathererCandidateCompleteEvent.h"
#include "impl_org_ortc_RTCIceGathererIceErrorEvent.h"
#include "impl_org_ortc_Helper.h"

using ::zsLib::String;
using ::zsLib::Optional;
using ::zsLib::Any;
using ::zsLib::AnyPtr;
using ::zsLib::AnyHolder;
using ::zsLib::Promise;
using ::zsLib::PromisePtr;
using ::zsLib::PromiseWithHolder;
using ::zsLib::PromiseWithHolderPtr;
using ::zsLib::eventing::SecureByteBlock;
using ::zsLib::eventing::SecureByteBlockPtr;
using ::std::shared_ptr;
using ::std::weak_ptr;
using ::std::make_shared;
using ::std::list;
using ::std::set;
using ::std::map;

namespace wrapper { namespace impl { namespace org { namespace ortc { ZS_DECLARE_SUBSYSTEM(org_ortc_wrapper); } } } }

ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::RTCIceGatherer::NativeType, NativeType);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::RTCIceGatherer::NativeTypeSubscription, NativeTypeSubscription);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::RTCIceGatherer::WrapperImplType, WrapperImplType);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::ortc::RTCIceGatherer::WrapperType, WrapperType);

//------------------------------------------------------------------------------
wrapper::impl::org::ortc::RTCIceGatherer::RTCIceGatherer() noexcept
{
}

//------------------------------------------------------------------------------
wrapper::org::ortc::RTCIceGathererPtr wrapper::org::ortc::RTCIceGatherer::wrapper_create() noexcept
{
  auto pThis = make_shared<wrapper::impl::org::ortc::RTCIceGatherer>();
  pThis->thisWeak_ = pThis;
  return pThis;
}

//------------------------------------------------------------------------------
wrapper::impl::org::ortc::RTCIceGatherer::~RTCIceGatherer() noexcept
{
}

//------------------------------------------------------------------------------
shared_ptr< PromiseWithHolderPtr< wrapper::org::ortc::RTCStatsReportPtr > > wrapper::impl::org::ortc::RTCIceGatherer::getStats(wrapper::org::ortc::RTCStatsTypeSetPtr statTypes) noexcept
{
  return Helper::getStats(native_, statTypes);
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::RTCIceGatherer::wrapper_init_org_ortc_RTCIceGatherer(wrapper::org::ortc::RTCIceGatherOptionsPtr options) noexcept
{
  auto native = RTCIceGatherOptions::toNative(options);
  ZS_ASSERT(native);

  native_ = NativeType::create(thisWeak_.lock(), *native);
}

//------------------------------------------------------------------------------
wrapper::org::ortc::RTCIceGathererPtr wrapper::impl::org::ortc::RTCIceGatherer::createAssociatedGatherer() noexcept
{
  return RTCIceGatherer::toWrapper(native_->createAssociatedGatherer(::ortc::IICEGathererDelegatePtr()));
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::RTCIceGatherer::gather() noexcept
{
  native_->gather();
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::RTCIceGatherer::gather(wrapper::org::ortc::RTCIceGatherOptionsPtr options) noexcept
{
  auto native = RTCIceGatherOptions::toNative(options);
  if (!native) {
    gather();
    return;
  }
  native_->gather(*native);
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::RTCIceGatherer::close() noexcept
{
  native_->close();
}

//------------------------------------------------------------------------------
uint64_t wrapper::impl::org::ortc::RTCIceGatherer::get_objectId() noexcept
{
  return native_->getID();
}

//------------------------------------------------------------------------------
wrapper::org::ortc::RTCIceComponent wrapper::impl::org::ortc::RTCIceGatherer::get_component() noexcept
{
  return Helper::toWrapper(native_->component());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::RTCIceGathererState wrapper::impl::org::ortc::RTCIceGatherer::get_state() noexcept
{
  return Helper::toWrapper(native_->state());
}

//------------------------------------------------------------------------------
wrapper::org::ortc::RTCIceParametersPtr wrapper::impl::org::ortc::RTCIceGatherer::get_localParameters() noexcept
{
  return RTCIceParameters::toWrapper(native_->getLocalParameters());
}

//------------------------------------------------------------------------------
shared_ptr< list< wrapper::org::ortc::RTCIceCandidatePtr > > wrapper::impl::org::ortc::RTCIceGatherer::get_localCandidates() noexcept
{
  auto result = make_shared< list< wrapper::org::ortc::RTCIceCandidatePtr > >();

  auto nativeList = native_->getLocalCandidates();
  if (nativeList) {
    for (auto iter = nativeList->begin(); iter != nativeList->end(); ++iter) {
      auto wrapper = RTCIceCandidate::toWrapper(make_shared<::ortc::IICETypes::Candidate>(*iter));
      if (!wrapper) continue;
      result->push_back(wrapper);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
void wrapper::impl::org::ortc::RTCIceGatherer::wrapper_onObserverCountChanged(size_t count) noexcept
{
  subscriptionCount_ = count;
  subscribe();
}

//------------------------------------------------------------------------------
void WrapperImplType::onICEGathererStateChange(
  IICEGathererPtr gatherer,
  IICEGatherer::States state
)
{
  onStateChange(RTCIceGathererStateChangeEvent::toWrapper(state));
}

//------------------------------------------------------------------------------
void WrapperImplType::onICEGathererLocalCandidate(
  IICEGathererPtr gatherer,
  CandidatePtr candidate
)
{
  onLocalCandidate(RTCIceGathererCandidateEvent::toWrapper(candidate));
}

//------------------------------------------------------------------------------
void WrapperImplType::onICEGathererLocalCandidateComplete(
  IICEGathererPtr gatherer,
  CandidateCompletePtr candidate
) 
{
  onLocalCandidateComplete(RTCIceGathererCandidateCompleteEvent::toWrapper(candidate));
}

//------------------------------------------------------------------------------
void WrapperImplType::onICEGathererLocalCandidateGone(
  IICEGathererPtr gatherer,
  CandidatePtr candidate
) 
{
  onLocalCandidateGone(RTCIceGathererCandidateEvent::toWrapper(candidate));
}

//------------------------------------------------------------------------------
void WrapperImplType::onICEGathererError(
  IICEGathererPtr gatherer,
  ErrorEventPtr errorEvent
) 
{
  onError(RTCIceGathererIceErrorEvent::toWrapper(errorEvent));
}

//------------------------------------------------------------------------------
WrapperImplTypePtr WrapperImplType::toWrapper(NativeTypePtr track) noexcept
{
  if (!track) return WrapperImplTypePtr();

  auto result = make_shared<WrapperImplType>();
  result->thisWeak_ = result;
  result->native_ = track;
  result->defaultSubscription_ = false;
  result->subscribe();
  return result;
}

//------------------------------------------------------------------------------
NativeTypePtr WrapperImplType::toNative(WrapperTypePtr wrapper) noexcept
{
  if (!wrapper) return NativeTypePtr();
  auto result = std::dynamic_pointer_cast<WrapperImplType>(wrapper);
  if (!result) return NativeTypePtr();
  return result->native_;
}

//------------------------------------------------------------------------------
void WrapperImplType::subscribe() noexcept
{
  if (defaultSubscription_) return;
  if (!native_) return;

  zsLib::AutoLock lock(lock_);
  if (subscriptionCount_ < 1) {
    if (!subscription_) return;
    subscription_->cancel();
    return;
  }
  if (subscription_) return;
  subscription_ = native_->subscribe(thisWeak_.lock());
}
