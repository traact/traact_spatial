/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#ifndef TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_CONVERT_H_
#define TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_CONVERT_H_

#include "spatial.h"

namespace traact::spatial {

enum class Axis { X, Y, Z, NX, NY, NZ };
enum class Handiness { LeftHanded, RightHanded };
enum class CoordinateSystems { Traact, OpenCV, OpenGL, Unity3D };

template<Axis right_axis, Axis up_axis, Axis forward_axis, Handiness handiness_system>
struct CoordinateSystem {
    static constexpr const Axis right{right_axis};
    static constexpr const Axis up{up_axis};
    static constexpr const Axis forward{forward_axis};
    static constexpr const Handiness handiness{handiness_system};
};

using OpenGLCoordinateSystem = CoordinateSystem<Axis::X, Axis::Y, Axis::NZ, Handiness::RightHanded>;
using OpenCVCoordinateSystem = CoordinateSystem<Axis::X, Axis::NY, Axis::Z, Handiness::RightHanded>;
using Unity3DCoordinateSystem = CoordinateSystem<Axis::X, Axis::Y, Axis::Z, Handiness::LeftHanded>;

using TraactCoordinateSystem = OpenCVCoordinateSystem;

const static inline std::set<std::string> CoordinateSystemNames{"Traact", "OpenCV", "OpenGL", "Unity3D"};
const static inline std::map<std::string, CoordinateSystems>
    CoordinateSystemValues{{"Traact", CoordinateSystems::Traact},
                           {"OpenCV", CoordinateSystems::OpenCV},
                           {"OpenGL", CoordinateSystems::OpenGL},
                           {"Unity3D", CoordinateSystems::Unity3D}};

template<typename From, typename To>
Pose6D convert(const Pose6D &pose);

template<typename T>
struct Convert{
    static typename T::NativeType fromTraact(const typename T::NativeType &value, CoordinateSystems to);
    static typename T::NativeType toTraact(const typename T::NativeType &value, CoordinateSystems from);
};

template<typename T>
typename T::NativeType Convert<T>::fromTraact(const typename T::NativeType &value, CoordinateSystems to){
    SPDLOG_ERROR("conversion from traact not implemented");
    return value;
};
template<typename T>
typename T::NativeType Convert<T>::toTraact(const typename T::NativeType &value, CoordinateSystems from){
    SPDLOG_ERROR("conversion from traact not implemented");
    return value;
}

template<>
struct Convert<Pose6DHeader>{
    static Pose6D fromTraact(const Pose6D &value, CoordinateSystems to);
    static Pose6D toTraact(const Pose6D &value, CoordinateSystems from);
};

}


#endif //TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_CONVERT_H_
