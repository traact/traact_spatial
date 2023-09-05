/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#include "traact/spatial_convert.h"

namespace traact::spatial {



template<>
Pose6D convert<OpenCVCoordinateSystem, OpenGLCoordinateSystem> (const Pose6D & pose){
    using VectorType = Eigen::Matrix<Scalar, 3,1>;
    VectorType euler_angles = pose.rotation().eulerAngles(0, 1, 2);
    Eigen::Matrix<Scalar, 3,3> rotation = (Eigen::AngleAxis<Scalar>( euler_angles[0], VectorType::UnitX())
        * Eigen::AngleAxisf(-euler_angles[1], VectorType::UnitY()) // invert rotation direction around y-axis
        * Eigen::AngleAxisf(-euler_angles[2], VectorType::UnitZ())).matrix(); // invert rotation direction around y-axis
    Eigen::Quaternion<Scalar> result_rotation = Eigen::Quaternion<Scalar>(rotation);

    auto& translation = pose.translation();
    Eigen::Translation3f opengl_position(translation[0] ,
                                         -translation[1] ,
                                         -translation[2]
    );
    Eigen::Affine3f result_pose = opengl_position * result_rotation;

    return result_pose;
}

template<>
Pose6D convert<OpenGLCoordinateSystem, OpenCVCoordinateSystem> (const Pose6D & pose){
    return convert<OpenCVCoordinateSystem, OpenGLCoordinateSystem>(pose);
}

// TODO implement conversions
template<>
Pose6D convert<OpenCVCoordinateSystem, Unity3DCoordinateSystem> (const Pose6D & pose){
    return pose;
}
template<>
Pose6D convert<Unity3DCoordinateSystem, OpenCVCoordinateSystem> (const Pose6D & pose){
    return convert<Unity3DCoordinateSystem, OpenCVCoordinateSystem>(pose);
}





Pose6D Convert<Pose6DHeader>::fromTraact (const typename Pose6DHeader::NativeType& value, CoordinateSystems to) {
    switch (to) {

        case CoordinateSystems::Traact:
        case CoordinateSystems::OpenCV: return value;
        case CoordinateSystems::OpenGL: return convert<TraactCoordinateSystem, OpenGLCoordinateSystem>(value);
        case CoordinateSystems::Unity3D:return convert<TraactCoordinateSystem, Unity3DCoordinateSystem>(value);
        default:
            throw std::logic_error("invalid coordinate system type");
    }
}

Pose6D Convert<Pose6DHeader>::toTraact(const typename Pose6DHeader::NativeType &value,
                                       traact::spatial::CoordinateSystems from)  {
    switch (from) {

        case CoordinateSystems::Traact:
        case CoordinateSystems::OpenCV: return value;
        case CoordinateSystems::OpenGL: return convert<OpenGLCoordinateSystem, TraactCoordinateSystem>(value);
        case CoordinateSystems::Unity3D:return convert<Unity3DCoordinateSystem, TraactCoordinateSystem>(value);
        default:
            throw std::logic_error("invalid coordinate system type");
    }
}



}