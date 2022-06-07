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

struct TRAACT_SPATIAL_EXPORT BodyHeader {
    /**
     * Definitions needed by traact and the user to use a datatype
     */
    static const char *MetaType;
    typedef Body NativeType;
    static const char *NativeTypeName;
    const size_t size = sizeof(NativeType);
};

struct TRAACT_SPATIAL_EXPORT BodyListHeader {
    /**
     * Definitions needed by traact and the user to use a datatype
     */
    static const char *MetaType;
    typedef std::vector<Body> NativeType;
    static const char *NativeTypeName;
    const size_t size = sizeof(NativeType);
};

class TRAACT_SPATIAL_EXPORT BodyFactoryObject : public buffer::TemplatedDefaultFactoryObject<BodyHeader> {

};

class TRAACT_SPATIAL_EXPORT BodyListFactoryObject : public buffer::TemplatedDefaultFactoryObject<BodyListHeader> {

};

}

#endif //TRAACTMULTI_TRAACT_SPATIAL_INCLUDE_TRAACT_SPATIALBODY_H_
