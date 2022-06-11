/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/


#include "traact/spatialBody.h"

namespace traact::spatial {

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

namespace traact::component::facade {
CREATE_SPATIAL_BODY_COMPONENTS(ApplicationAsyncSource)
CREATE_SPATIAL_BODY_COMPONENTS(ApplicationSyncSink)
}

BEGIN_TRAACT_PLUGIN_REGISTRATION
    REGISTER_DEFAULT_TRAACT_TYPE(traact::spatial::BodyHeader)
    REGISTER_DEFAULT_TRAACT_TYPE(traact::spatial::BodyListHeader)
    REGISTER_SPATIAL_BODY_COMPONENTS(traact::component::facade::ApplicationAsyncSource)
    REGISTER_SPATIAL_BODY_COMPONENTS(traact::component::facade::ApplicationSyncSink)
END_TRAACT_PLUGIN_REGISTRATION
