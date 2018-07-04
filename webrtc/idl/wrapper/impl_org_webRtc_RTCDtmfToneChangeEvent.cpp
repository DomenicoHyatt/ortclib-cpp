
#include "impl_org_webRtc_RTCDtmfToneChangeEvent.h"

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
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webRtc::RTCDtmfToneChangeEvent::WrapperImplType, WrapperImplType);
ZS_DECLARE_TYPEDEF_PTR(WrapperImplType::WrapperType, WrapperType);

//------------------------------------------------------------------------------
wrapper::impl::org::webRtc::RTCDtmfToneChangeEvent::RTCDtmfToneChangeEvent() noexcept
{
}

//------------------------------------------------------------------------------
wrapper::org::webRtc::RTCDtmfToneChangeEventPtr wrapper::org::webRtc::RTCDtmfToneChangeEvent::wrapper_create() noexcept
{
  auto pThis = make_shared<wrapper::impl::org::webRtc::RTCDtmfToneChangeEvent>();
  pThis->thisWeak_ = pThis;
  return pThis;
}

//------------------------------------------------------------------------------
wrapper::impl::org::webRtc::RTCDtmfToneChangeEvent::~RTCDtmfToneChangeEvent() noexcept
{
  thisWeak_.reset();
}

//------------------------------------------------------------------------------
String wrapper::impl::org::webRtc::RTCDtmfToneChangeEvent::get_tone() noexcept
{
  String result {};
  return result;
}

//------------------------------------------------------------------------------
WrapperImplTypePtr WrapperImplType::toWrapper(const String &tone) noexcept
{
  auto result = make_shared<WrapperImplType>();
  result->thisWeak_ = result;
  result->tone_ = tone;
  return result;
}
