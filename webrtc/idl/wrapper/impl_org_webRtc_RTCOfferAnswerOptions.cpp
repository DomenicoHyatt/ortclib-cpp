
#include "impl_org_webRtc_RTCOfferAnswerOptions.h"

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

// borrow definitions from class
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::RTCOfferAnswerOptions::WrapperImplType, WrapperImplType);
ZS_DECLARE_TYPEDEF_PTR(WrapperImplType::WrapperType, WrapperType);
ZS_DECLARE_TYPEDEF_PTR(WrapperImplType::NativeType, NativeType);

//------------------------------------------------------------------------------
wrapper::impl::org::webRtc::RTCOfferAnswerOptions::~RTCOfferAnswerOptions() noexcept
{
}

//------------------------------------------------------------------------------
void WrapperImplType::apply(const NativeType &from, WrapperType &to) noexcept
{
  to.voiceActivityDetection = from.voice_activity_detection;
}

//------------------------------------------------------------------------------
void WrapperImplType::apply(const WrapperType &from, NativeType &to) noexcept
{
  to.voice_activity_detection = from.voiceActivityDetection;
}
