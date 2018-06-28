
#include "impl_org_webrtc_RTCOAuthCredential.h"

#include <zsLib/String.h>

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
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webrtc::RTCOAuthCredential::WrapperImplType, WrapperImplType);
ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webrtc::RTCOAuthCredential::WrapperType, WrapperType);
//ZS_DECLARE_TYPEDEF_PTR(wrapper::impl::org::webrtc::RTCOAuthCredential::NativeType, NativeType);

//------------------------------------------------------------------------------
wrapper::impl::org::webrtc::RTCOAuthCredential::RTCOAuthCredential() noexcept
{
}

//------------------------------------------------------------------------------
wrapper::org::webrtc::RTCOAuthCredentialPtr wrapper::org::webrtc::RTCOAuthCredential::wrapper_create() noexcept
{
  auto pThis = make_shared<wrapper::impl::org::webrtc::RTCOAuthCredential>();
  pThis->thisWeak_ = pThis;
  return pThis;
}

//------------------------------------------------------------------------------
wrapper::impl::org::webrtc::RTCOAuthCredential::~RTCOAuthCredential()
{
}

//------------------------------------------------------------------------------
void wrapper::impl::org::webrtc::RTCOAuthCredential::wrapper_init_org_webrtc_RTCOAuthCredential() noexcept
{
}

//------------------------------------------------------------------------------
void wrapper::impl::org::webrtc::RTCOAuthCredential::wrapper_init_org_webrtc_RTCOAuthCredential(wrapper::org::webrtc::RTCOAuthCredentialPtr source) noexcept
{
  if (!source) {
    wrapper_init_org_webrtc_RTCOAuthCredential();
    return;
  }
  macKey = source->macKey;
  accessToken = source->accessToken;
}

#if 0
//------------------------------------------------------------------------------
static void apply(const NativeType &from, WrapperImplType &to)
{
  to.macKey = from.first;
  to.accessToken = from.second;
}

//------------------------------------------------------------------------------
static void apply(const WrapperImplType &from, NativeType &to)
{
  to.first = from.macKey;
  to.second = from.accessToken;
}

//------------------------------------------------------------------------------
WrapperImplTypePtr WrapperImplType::toWrapper(const NativeType &native) noexcept
{
  auto result = make_shared<WrapperImplType>();
  result->thisWeak_ = result;
  apply(native, *result);
  return result;
}

//------------------------------------------------------------------------------
WrapperImplTypePtr WrapperImplType::toWrapper(NativeTypePtr native) noexcept
{
  if (!native) return WrapperImplTypePtr();
  return toWrapper(*native);
}

//------------------------------------------------------------------------------
NativeTypePtr WrapperImplType::toNative(WrapperTypePtr wrapper) noexcept
{
  if (!wrapper) return NativeTypePtr();
  auto converted = ZS_DYNAMIC_PTR_CAST(WrapperImplType, wrapper);
  if (!converted) return NativeTypePtr();
  auto cloned = make_shared<NativeType>();
  apply(*converted, *cloned);
  return cloned;
}

#endif //0
