/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#include "spatial_convert.h"

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

}