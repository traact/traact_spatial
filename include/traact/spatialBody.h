/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#ifndef TRAACTMULTI_TRAACT_SPATIAL_INCLUDE_TRAACT_SPATIALBODY_H_
#define TRAACTMULTI_TRAACT_SPATIAL_INCLUDE_TRAACT_SPATIALBODY_H_

#include "spatial.h"
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

using BodyList = std::vector<Body>;

CREATE_TRAACT_HEADER_TYPE(BodyHeader, traact::spatial::Body, "spatial:Body", TRAACT_SPATIAL_EXPORT)
CREATE_TRAACT_HEADER_TYPE(BodyListHeader, traact::spatial::BodyList, "spatial:BodyList", TRAACT_SPATIAL_EXPORT)

}

#define CREATE_SPATIAL_BODY_COMPONENTS(external_component) \
CREATE_TEMPLATED_TRAACT_COMPONENT_FACTORY(external_component, traact::spatial, BodyHeader) \
CREATE_TEMPLATED_TRAACT_COMPONENT_FACTORY(external_component, traact::spatial, BodyListHeader) \

#define REGISTER_SPATIAL_BODY_COMPONENTS(external_component) \
REGISTER_TEMPLATED_DEFAULT_COMPONENT(external_component, BodyHeader) \
REGISTER_TEMPLATED_DEFAULT_COMPONENT(external_component, BodyListHeader) \

#endif //TRAACTMULTI_TRAACT_SPATIAL_INCLUDE_TRAACT_SPATIALBODY_H_
