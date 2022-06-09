/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#ifndef TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_H_
#define TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_H_

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <traact/traact.h>
#include <traact/traact_spatial_export.h>

namespace traact::spatial {

using Pose6D = Eigen::Transform<traact::Scalar, 3,2>;
using Rotation3D = Eigen::Quaternion<traact::Scalar >;
using Translation3D = Eigen::Translation<traact::Scalar, 3>;
using Position2D = Eigen::Vector<traact::Scalar, 2>;
using Position3D = Eigen::Vector<traact::Scalar, 3>;
using Position2DList = std::vector<Eigen::Vector<traact::Scalar, 2>>;
using Position3DList = std::vector<Eigen::Vector<traact::Scalar, 3>>;

CREATE_TRAACT_HEADER_TYPE(Pose6DHeader, traact::spatial::Pose6D, "spatial:Pose6D", TRAACT_SPATIAL_EXPORT)
CREATE_TRAACT_HEADER_TYPE(Rotation3DHeader, traact::spatial::Rotation3D, "spatial:Rotation3D", TRAACT_SPATIAL_EXPORT)
CREATE_TRAACT_HEADER_TYPE(Translation3DHeader, traact::spatial::Translation3D, "spatial:Translation3D", TRAACT_SPATIAL_EXPORT)
CREATE_TRAACT_HEADER_TYPE(Position2DHeader, traact::spatial::Position2D, "spatial:Position2D", TRAACT_SPATIAL_EXPORT)
CREATE_TRAACT_HEADER_TYPE(Position3DHeader, traact::spatial::Position3D, "spatial:Position3D", TRAACT_SPATIAL_EXPORT)
CREATE_TRAACT_HEADER_TYPE(Position2DListHeader, traact::spatial::Position2DList, "spatial:Position2DList", TRAACT_SPATIAL_EXPORT)
CREATE_TRAACT_HEADER_TYPE(Position3DListHeader, traact::spatial::Position3DList, "spatial:Position3DList", TRAACT_SPATIAL_EXPORT)



}// namespace traact::spatial

#define REGISTER_SPATIAL_COMPONENTS(external_component) \
REGISTER_COMPONENT(external_component<traact::spatial::Pose6DHeader>) \
REGISTER_COMPONENT(external_component<traact::spatial::Rotation3DHeader>) \
REGISTER_COMPONENT(external_component<traact::spatial::Translation3DHeader>) \
REGISTER_COMPONENT(external_component<traact::spatial::Position2DHeader>) \
REGISTER_COMPONENT(external_component<traact::spatial::Position3DHeader>)\
REGISTER_COMPONENT(external_component<traact::spatial::Position2DListHeader>)\
REGISTER_COMPONENT(external_component<traact::spatial::Position3DListHeader>)


#endif//TRAACT_SPATIAL_SRC_TRAACT_SPATIAL_H_
