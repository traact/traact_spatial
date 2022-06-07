/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#ifndef TRAACT_SPATIAL_MODULE_SRC_TRAACT_SPATIAL_SPATIALPLUGIN_H_
#define TRAACT_SPATIAL_MODULE_SRC_TRAACT_SPATIAL_SPATIALPLUGIN_H_

#include <traact/buffer/DataFactory.h>
#include <traact/datatypes.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <traact/traact_spatial_export.h>
#include <rttr/type>
#include<Eigen/StdVector>

namespace traact::spatial {

typedef typename Eigen::Affine3d Pose6D;
typedef typename Eigen::Vector2d Position2D;
typedef typename Eigen::Vector3d Position3D;
typedef typename std::vector<Eigen::Vector2d, Eigen::aligned_allocator < Eigen::Vector2d> >
Position2DList;
typedef typename std::vector<Eigen::Vector3d, Eigen::aligned_allocator < Eigen::Vector3d> >
Position3DList;

struct TRAACT_SPATIAL_EXPORT Pose6DHeader {
    /**
     * Definitions needed by traact and the user to use a datatype
     */
    static const char *MetaType;
    typedef Pose6D NativeType;
    static const char *NativeTypeName;
    const size_t size = sizeof(NativeType);

 RTTR_ENABLE()
};

struct TRAACT_SPATIAL_EXPORT Position2DListHeader {
    /**
     * Definitions needed by traact and the user to use a datatype
     */
    static const char *MetaType;
    typedef Position2DList NativeType;
    static const char *NativeTypeName;
    const size_t size = sizeof(NativeType);

 RTTR_ENABLE()
};

struct TRAACT_SPATIAL_EXPORT Position3DListHeader {
    /**
     * Definitions needed by traact and the user to use a datatype
     */
    static const char *MetaType;
    typedef Position3DList NativeType;
    static const char *NativeTypeName;
    const size_t size = sizeof(NativeType);

 RTTR_ENABLE()
};

class TRAACT_SPATIAL_EXPORT Pose6DFactoryObject : public buffer::TemplatedDefaultFactoryObject<Pose6DHeader> {
 RTTR_ENABLE(buffer::TemplatedDefaultFactoryObject<Pose6DHeader>, buffer::DataFactory)
};

class TRAACT_SPATIAL_EXPORT Position2DListFactoryObject : public buffer::TemplatedDefaultFactoryObject<
    Position2DListHeader> {
 RTTR_ENABLE(buffer::TemplatedDefaultFactoryObject<Position2DListHeader>, buffer::DataFactory)
};

class TRAACT_SPATIAL_EXPORT Position3DListFactoryObject : public buffer::TemplatedDefaultFactoryObject<
    Position3DListHeader> {
 RTTR_ENABLE(buffer::TemplatedDefaultFactoryObject<Position3DListHeader>, buffer::DataFactory)
};

}

#endif //TRAACT_SPATIAL_MODULE_SRC_TRAACT_SPATIAL_SPATIALPLUGIN_H_
