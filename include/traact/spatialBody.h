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

#ifndef TRAACTMULTI_TRAACT_SPATIAL_INCLUDE_TRAACT_SPATIALBODY_H_
#define TRAACTMULTI_TRAACT_SPATIAL_INCLUDE_TRAACT_SPATIALBODY_H_

#include <traact/spatial.h>
#include <map>

namespace traact::spatial {

enum class TRAACT_SPATIAL_EXPORT BodyJointType {
  PELVIS = 0,
  SPINE_NAVAL,
  SPINE_CHEST,
  NECK,
  CLAVICLE_LEFT,
  SHOULDER_LEFT,
  ELBOW_LEFT,
  WRIST_LEFT,
  HAND_LEFT,
  HANDTIP_LEFT,
  THUMB_LEFT,
  CLAVICLE_RIGHT,
  SHOULDER_RIGHT,
  ELBOW_RIGHT,
  WRIST_RIGHT,
  HAND_RIGHT,
  HANDTIP_RIGHT,
  THUMB_RIGHT,
  HIP_LEFT,
  KNEE_LEFT,
  ANKLE_LEFT,
  FOOT_LEFT,
  HIP_RIGHT,
  KNEE_RIGHT,
  ANKLE_RIGHT,
  FOOT_RIGHT,
  HEAD,
  NOSE,
  EYE_LEFT,
  EAR_LEFT,
  EYE_RIGHT,
  EAR_RIGHT,
  COUNT
};

class TRAACT_SPATIAL_EXPORT BodyUtils {
 public:
  static std::map<BodyJointType, BodyJointType> JointToParent;

};

struct TRAACT_SPATIAL_EXPORT BodyJoint {
  Pose6DHeader::NativeType pose;
  int confidenceLevel{0};
};

struct TRAACT_SPATIAL_EXPORT Body {
  int id{-1};
  std::map<BodyJointType, BodyJoint> bodyJoints;
};

struct TRAACT_SPATIAL_EXPORT BodyHeader {
  /**
   * Definitions needed by traact and the user to use a datatype
   */
  static const char * MetaType;
  typedef Body NativeType;
  static const char * NativeTypeName;
  const size_t size = sizeof(NativeType);
};

struct TRAACT_SPATIAL_EXPORT BodyListHeader {
  /**
   * Definitions needed by traact and the user to use a datatype
   */
  static const char * MetaType;
  typedef std::vector<Body> NativeType;
  static const char * NativeTypeName;
  const size_t size = sizeof(NativeType);
};



class TRAACT_SPATIAL_EXPORT BodyFactoryObject : public buffer::TemplatedDefaultFactoryObject<BodyHeader> {

};

class TRAACT_SPATIAL_EXPORT BodyListFactoryObject : public buffer::TemplatedDefaultFactoryObject<BodyListHeader> {

};

}

#endif //TRAACTMULTI_TRAACT_SPATIAL_INCLUDE_TRAACT_SPATIALBODY_H_
