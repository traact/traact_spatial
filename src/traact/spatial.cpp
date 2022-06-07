/**
 *   Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com>
 *
 *   License in root folder
**/


#include "traact/spatial.h"
#include <rttr/registration>
#include <traact/component/facade/ApplicationAsyncSource.h>
#include <traact/component/facade/ApplicationSyncSink.h>
namespace traact::spatial {

const char *Pose6DHeader::NativeTypeName = "Eigen::Affine3d";
const char *Pose6DHeader::MetaType = "spatial:Pose6D";

const char *Position2DListHeader::NativeTypeName = "std::vector<Eigen::Vector2d>";
const char *Position2DListHeader::MetaType = "spatial:Position2DList";

const char
    *Position3DListHeader::NativeTypeName = "std::vector<Eigen::Vector3d, Eigen::aligned_allocator<Eigen::Vector3d>>";
const char *Position3DListHeader::MetaType = "spatial:Position3DList";

}


// It is not possible to place the macro multiple times in one cpp file. When you compile your plugin with the gcc toolchain,
// make sure you use the compiler option: -fno-gnu-unique. otherwise the unregistration will not work properly.
RTTR_PLUGIN_REGISTRATION // remark the different registration macro!
{

    using namespace rttr;
    registration::class_<traact::spatial::Pose6DFactoryObject>("Pose6DFactoryObject").constructor<>()();
    registration::class_<traact::spatial::Position2DListFactoryObject>("Position2DListFactoryObject").constructor<>()();
    registration::class_<traact::spatial::Position3DListFactoryObject>("Position3DListFactoryObject").constructor<>()();
    registration::class_<traact::component::facade::ApplicationAsyncSource<traact::spatial::Pose6DHeader> >(
        "ApplicationAsyncSource_Eigen::Affine3d").constructor<std::string>()();
    registration::class_<traact::component::facade::ApplicationSyncSink<traact::spatial::Pose6DHeader> >(
        "ApplicationSyncSink_Eigen::Affine3d").constructor<std::string>()();
}