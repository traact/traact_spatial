/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#ifndef TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_CONVERT_H_
#define TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_CONVERT_H_

#include "spatial.h"

namespace traact::spatial {

    enum class Axis { X, Y, Z, NX, NY, NZ};
    enum class Handiness {LeftHanded, RightHanded};

    template<Axis right_axis, Axis up_axis,Axis forward_axis, Handiness handiness_system>
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

    template<typename From, typename To>
    Pose6D convert(const Pose6D & pose);
}

#endif //TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_CONVERT_H_
