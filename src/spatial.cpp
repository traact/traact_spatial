/*  BSD 3-Clause License
 *
 *  Copyright (c) 2020, FriederPankratz <frieder.pankratz@gmail.com>
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/


#include "traact/spatial.h"
#include <rttr/registration>
#include <traact/component/facade/ApplicationAsyncSource.h>
#include <traact/component/facade/ApplicationSyncSink.h>
namespace traact::spatial {

const char * Pose6DHeader::NativeTypeName =  "Eigen::Affine3d";
const char * Pose6DHeader::MetaType =  "spatial:Pose6D";

    const char * Position2DListHeader::NativeTypeName =  "std::vector<Eigen::Vector2d>";
    const char * Position2DListHeader::MetaType =  "spatial:Position2DList";

    const char * Position3DListHeader::NativeTypeName =  "std::vector<Eigen::Vector3d, Eigen::aligned_allocator<Eigen::Vector3d>>";
    const char * Position3DListHeader::MetaType =  "spatial:Position3DList";

}

namespace traact::buffer {
template<>
spatial::Pose6DHeader::NativeType &BufferTypeConversion::asMutable<spatial::Pose6DHeader::NativeType,
                                                                          spatial::Pose6DHeader>(void *obj,
                                                                                                 void *header) {
  return *static_cast<spatial::Pose6DHeader::NativeType *>(obj);
}

template<>
const spatial::Pose6DHeader::NativeType &BufferTypeConversion::asImmutable<spatial::Pose6DHeader::NativeType,
                                                                                  spatial::Pose6DHeader>(void *obj,
                                                                                                         void *header) {
  return *static_cast<spatial::Pose6DHeader::NativeType *>(obj);
}

template<>
const Eigen::Translation3d &BufferTypeConversion::asImmutable<Eigen::Translation3d,
                                                                     spatial::Pose6DHeader>(void *obj, void *header) {
  auto tmp = static_cast<spatial::Pose6DHeader::NativeType *>(obj);
  Eigen::Translation3d tmp2(tmp->translation());
  return std::move(tmp2);
}

    template<>
    spatial::Position2DListHeader::NativeType &BufferTypeConversion::asMutable<spatial::Position2DListHeader::NativeType,
            spatial::Position2DListHeader>(void *obj,
                                   void *header) {
        return *static_cast<spatial::Position2DListHeader::NativeType *>(obj);
    }

    template<>
    const spatial::Position2DListHeader::NativeType &BufferTypeConversion::asImmutable<spatial::Position2DListHeader::NativeType,
            spatial::Position2DListHeader>(void *obj,
                                   void *header) {
        return *static_cast<spatial::Position2DListHeader::NativeType *>(obj);
    }

    template<>
    spatial::Position3DListHeader::NativeType &BufferTypeConversion::asMutable<spatial::Position3DListHeader::NativeType,
            spatial::Position3DListHeader>(void *obj,
                                           void *header) {
        return *static_cast<spatial::Position3DListHeader::NativeType *>(obj);
    }

    template<>
    const spatial::Position3DListHeader::NativeType &BufferTypeConversion::asImmutable<spatial::Position3DListHeader::NativeType,
            spatial::Position3DListHeader>(void *obj,
                                           void *header) {
        return *static_cast<spatial::Position3DListHeader::NativeType *>(obj);
    }


template TRAACT_SPATIAL_EXPORT spatial::Pose6DHeader::NativeType &BufferTypeConversion::asMutable<spatial::Pose6DHeader::NativeType, spatial::Pose6DHeader>(void*, void* );
template TRAACT_SPATIAL_EXPORT const spatial::Pose6DHeader::NativeType &BufferTypeConversion::asImmutable<spatial::Pose6DHeader::NativeType, spatial::Pose6DHeader>(void*, void*);
template TRAACT_SPATIAL_EXPORT const Eigen::Translation3d &BufferTypeConversion::asImmutable<Eigen::Translation3d, spatial::Pose6DHeader>(void*, void*);

    template TRAACT_SPATIAL_EXPORT spatial::Position2DListHeader::NativeType &BufferTypeConversion::asMutable<spatial::Position2DListHeader::NativeType, spatial::Position2DListHeader>(void*, void* );
    template TRAACT_SPATIAL_EXPORT const spatial::Position2DListHeader::NativeType &BufferTypeConversion::asImmutable<spatial::Position2DListHeader::NativeType, spatial::Position2DListHeader>(void*, void*);

    template TRAACT_SPATIAL_EXPORT spatial::Position3DListHeader::NativeType &BufferTypeConversion::asMutable<spatial::Position3DListHeader::NativeType, spatial::Position3DListHeader>(void*, void* );
    template TRAACT_SPATIAL_EXPORT const spatial::Position3DListHeader::NativeType &BufferTypeConversion::asImmutable<spatial::Position3DListHeader::NativeType, spatial::Position3DListHeader>(void*, void*);
}

// It is not possible to place the macro multiple times in one cpp file. When you compile your plugin with the gcc toolchain,
// make sure you use the compiler option: -fno-gnu-unique. otherwise the unregistration will not work properly.
RTTR_PLUGIN_REGISTRATION // remark the different registration macro!
{

    using namespace rttr;
    registration::class_<traact::spatial::Pose6DFactoryObject>("Pose6DFactoryObject").constructor<>()();
    registration::class_<traact::spatial::Position2DListFactoryObject>("Position2DListFactoryObject").constructor<>()();
    registration::class_<traact::spatial::Position3DListFactoryObject>("Position3DListFactoryObject").constructor<>()();
    registration::class_<traact::component::facade::ApplicationAsyncSource<traact::spatial::Pose6DHeader> >("ApplicationAsyncSource_Eigen::Affine3d").constructor<std::string>()();
    registration::class_<traact::component::facade::ApplicationSyncSink<traact::spatial::Pose6DHeader> >("ApplicationSyncSink_Eigen::Affine3d").constructor<std::string>()();
}