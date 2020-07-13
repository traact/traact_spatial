/*  BSD 3-Clause License
 *
 *  Copyright (c) 2020, FriederPankratz <frieder.pankratz@gmail.com>
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/


#include "traact/spatial.h"
#include <rttr/registration>
namespace traact::spatial {

const char * Pose6DHeader::NativeTypeName =  "Eigen::Affine3d";
const char * Pose6DHeader::MetaType =  "spatial:Pose6D";

}

namespace traact::buffer {
template<>
spatial::Pose6DHeader::NativeType &GenericBufferTypeConversion::asMutable<spatial::Pose6DHeader::NativeType,
                                                                          spatial::Pose6DHeader>(void *obj,
                                                                                                 void *header) {
  return *static_cast<spatial::Pose6DHeader::NativeType *>(obj);
}

template<>
const spatial::Pose6DHeader::NativeType &GenericBufferTypeConversion::asImmutable<spatial::Pose6DHeader::NativeType,
                                                                                  spatial::Pose6DHeader>(void *obj,
                                                                                                         void *header) {
  return *static_cast<spatial::Pose6DHeader::NativeType *>(obj);
}

template<>
const Eigen::Translation3d &GenericBufferTypeConversion::asImmutable<Eigen::Translation3d,
                                                                     spatial::Pose6DHeader>(void *obj, void *header) {
  auto tmp = static_cast<spatial::Pose6DHeader::NativeType *>(obj);
  Eigen::Translation3d tmp2(tmp->translation());
  return std::move(tmp2);
}

template TRAACT_SPATIAL_EXPORT spatial::Pose6DHeader::NativeType &GenericBufferTypeConversion::asMutable<spatial::Pose6DHeader::NativeType, spatial::Pose6DHeader>(void*, void* );
template TRAACT_SPATIAL_EXPORT const spatial::Pose6DHeader::NativeType &GenericBufferTypeConversion::asImmutable<spatial::Pose6DHeader::NativeType, spatial::Pose6DHeader>(void*, void*);
template TRAACT_SPATIAL_EXPORT const Eigen::Translation3d &GenericBufferTypeConversion::asImmutable<Eigen::Translation3d, spatial::Pose6DHeader>(void*, void*);

}

RTTR_PLUGIN_REGISTRATION // remark the different registration macro!
{
/*
  using namespace rttr;
  registration::class_<traact::spatial::Pose6DFactoryObject>("Pose6DFactoryObject").constructor<>()
      (
          //policy::ctor::as_std_shared_ptr
      );
      */
}