/*

 Copyright (c) 2014, Hookflash Inc. / Hookflash Inc.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

#pragma once

#include <ortc/types.h>
#include <ortc/TrackDescription.h>

namespace ortc
{
  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  //---------------------------------------------------------------------------
  #pragma mark
  #pragma mark IRTPReceiver
  #pragma mark
  
  interaction IRTPReceiver
  {
    ZS_DECLARE_STRUCT_PTR(Capabilities)

    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark Options
    #pragma mark

    enum Options
    {
      Option_Unknown,
    };

    static const char *toString(Options option);

    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark Capabilities
    #pragma mark

    struct Capabilities
    {
      typedef std::list<Options> OptionsList;

      OptionsList mOptions;

      static CapabilitiesPtr create();
      ElementPtr toDebug() const;

    protected:
      Capabilities() {}
      Capabilities(const Capabilities &) {}
    };

    static ElementPtr toDebug(IRTPReceiverPtr transport);

    static IRTPReceiverPtr create(
                                  IDTLSTransportPtr rtpTransport,
                                  IDTLSTransportPtr rtcpTransport = IDTLSTransportPtr()
                                  );

    virtual PUID getID() const = 0;

    static CapabilitiesPtr getCapabilities();

    virtual TrackDescriptionPtr createParams(CapabilitiesPtr capabilities = CapabilitiesPtr()) = 0;

    static TrackDescriptionPtr filterParams(
                                            TrackDescriptionPtr params,
                                            CapabilitiesPtr capabilities
                                            );

    virtual TrackDescriptionPtr getDescription() = 0;
    virtual void setDescription(TrackDescriptionPtr) = 0;

    virtual void attach(
                        IDTLSTransportPtr rtpTransport,
                        IDTLSTransportPtr rtcpTransport = IDTLSTransportPtr()
                        );

    virtual void start(TrackDescriptionPtr trackDescription) = 0;
    virtual void stop() = 0;
  };
}
