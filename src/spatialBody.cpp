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

#include <traact/facade/Plugin.h>

#include "traact/spatialBody.h"

namespace traact::spatial {

const char * BodyHeader::NativeTypeName =  "traact::spatial::Body";
const char * BodyHeader::MetaType =  "spatial:Body";

const char * BodyListHeader::NativeTypeName =  "traact::spatial::BodyList";
const char * BodyListHeader::MetaType =  "spatial:BodyList";

std::map<BodyJointType, BodyJointType> BodyUtils::JointToParent =
    {{BodyJointType::PELVIS, BodyJointType::PELVIS},
     {BodyJointType::SPINE_NAVAL, BodyJointType::PELVIS},
     {BodyJointType::SPINE_CHEST, BodyJointType::SPINE_NAVAL},
     {BodyJointType::NECK, BodyJointType::SPINE_CHEST},
     {BodyJointType::HEAD, BodyJointType::NECK},
     {BodyJointType::EYE_LEFT, BodyJointType::HEAD},
     {BodyJointType::EYE_RIGHT, BodyJointType::HEAD},
     {BodyJointType::NOSE, BodyJointType::HEAD},
     {BodyJointType::EAR_LEFT, BodyJointType::HEAD},
     {BodyJointType::EAR_RIGHT, BodyJointType::HEAD},

     {BodyJointType::CLAVICLE_LEFT, BodyJointType::SPINE_CHEST},
     {BodyJointType::SHOULDER_LEFT, BodyJointType::CLAVICLE_LEFT},
     {BodyJointType::ELBOW_LEFT, BodyJointType::SHOULDER_LEFT},
     {BodyJointType::WRIST_LEFT, BodyJointType::ELBOW_LEFT},
     {BodyJointType::HAND_LEFT, BodyJointType::WRIST_LEFT},
     {BodyJointType::HANDTIP_LEFT, BodyJointType::HAND_LEFT},
     {BodyJointType::THUMB_LEFT, BodyJointType::WRIST_LEFT},

     {BodyJointType::CLAVICLE_RIGHT, BodyJointType::SPINE_CHEST},
     {BodyJointType::SHOULDER_RIGHT, BodyJointType::CLAVICLE_RIGHT},
     {BodyJointType::ELBOW_RIGHT, BodyJointType::SHOULDER_RIGHT},
     {BodyJointType::WRIST_RIGHT, BodyJointType::ELBOW_RIGHT},
     {BodyJointType::HAND_RIGHT, BodyJointType::WRIST_RIGHT},
     {BodyJointType::HANDTIP_RIGHT, BodyJointType::HAND_RIGHT},
     {BodyJointType::THUMB_RIGHT, BodyJointType::WRIST_RIGHT},




     {BodyJointType::HIP_LEFT, BodyJointType::PELVIS},
     {BodyJointType::KNEE_LEFT, BodyJointType::HIP_LEFT},
     {BodyJointType::ANKLE_LEFT, BodyJointType::KNEE_LEFT},
     {BodyJointType::FOOT_LEFT, BodyJointType::ANKLE_LEFT},

     {BodyJointType::HIP_RIGHT, BodyJointType::PELVIS},
     {BodyJointType::KNEE_RIGHT, BodyJointType::HIP_RIGHT},
     {BodyJointType::ANKLE_RIGHT, BodyJointType::KNEE_RIGHT},
     {BodyJointType::FOOT_RIGHT, BodyJointType::ANKLE_RIGHT},
    };


}

namespace traact::buffer {
template<>
spatial::BodyHeader::NativeType &GenericBufferTypeConversion::asMutable<spatial::BodyHeader::NativeType,
                                                                          spatial::BodyHeader>(void *obj,
                                                                                                 void *header) {
  return *static_cast<spatial::BodyHeader::NativeType *>(obj);
}

template<>
const spatial::BodyHeader::NativeType &GenericBufferTypeConversion::asImmutable<spatial::BodyHeader::NativeType,
                                                                                  spatial::BodyHeader>(void *obj,
                                                                                                         void *header) {
  return *static_cast<spatial::BodyHeader::NativeType *>(obj);
}

template<>
spatial::BodyListHeader::NativeType &GenericBufferTypeConversion::asMutable<spatial::BodyListHeader::NativeType,
                                                                        spatial::BodyListHeader>(void *obj,
                                                                                             void *header) {
  return *static_cast<spatial::BodyListHeader::NativeType *>(obj);
}

template<>
const spatial::BodyListHeader::NativeType &GenericBufferTypeConversion::asImmutable<spatial::BodyListHeader::NativeType,
                                                                                spatial::BodyListHeader>(void *obj,
                                                                                                     void *header) {
  return *static_cast<spatial::BodyListHeader::NativeType *>(obj);
}


}

