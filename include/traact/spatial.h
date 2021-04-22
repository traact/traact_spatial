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

#ifndef TRAACT_SPATIAL_MODULE_SRC_TRAACT_SPATIAL_SPATIALPLUGIN_H_
#define TRAACT_SPATIAL_MODULE_SRC_TRAACT_SPATIAL_SPATIALPLUGIN_H_

#include <traact/buffer/BufferFactory.h>
#include <traact/buffer/BufferTypeConversion.h>
#include <traact/datatypes.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include <traact/traact_spatial_export.h>
#include <rttr/type>
#include<Eigen/StdVector>

namespace traact::spatial {

    typedef typename Eigen::Affine3d Pose6D;
    typedef typename  std::vector<Eigen::Vector2d, Eigen::aligned_allocator<Eigen::Vector2d> > Position2DList;
    typedef typename  std::vector<Eigen::Vector3d, Eigen::aligned_allocator<Eigen::Vector3d> > Position3DList;

struct TRAACT_SPATIAL_EXPORT Pose6DHeader {
  /**
   * Definitions needed by traact and the user to use a datatype
   */
  static const char * MetaType;
  typedef Pose6D NativeType;
  static const char * NativeTypeName;
  const size_t size = sizeof(NativeType);

  RTTR_ENABLE()
};

struct TRAACT_SPATIAL_EXPORT Position2DListHeader {
    /**
     * Definitions needed by traact and the user to use a datatype
     */
    static const char * MetaType;
    typedef Position2DList NativeType;
    static const char * NativeTypeName;
    const size_t size = sizeof(NativeType);

RTTR_ENABLE()
};

    struct TRAACT_SPATIAL_EXPORT Position3DListHeader {
        /**
         * Definitions needed by traact and the user to use a datatype
         */
        static const char * MetaType;
        typedef Position3DList NativeType;
        static const char * NativeTypeName;
        const size_t size = sizeof(NativeType);

    RTTR_ENABLE()
    };



class TRAACT_SPATIAL_EXPORT Pose6DFactoryObject : public buffer::TemplatedDefaultFactoryObject<Pose6DHeader> {
  RTTR_ENABLE(buffer::TemplatedDefaultFactoryObject<Pose6DHeader>, buffer::BufferFactory)
};

class TRAACT_SPATIAL_EXPORT Position2DListFactoryObject : public buffer::TemplatedDefaultFactoryObject<Position2DListHeader> {
RTTR_ENABLE(buffer::TemplatedDefaultFactoryObject<Position2DListHeader>, buffer::BufferFactory)
};

    class TRAACT_SPATIAL_EXPORT Position3DListFactoryObject : public buffer::TemplatedDefaultFactoryObject<Position3DListHeader> {
    RTTR_ENABLE(buffer::TemplatedDefaultFactoryObject<Position3DListHeader>, buffer::BufferFactory)
    };

}

#endif //TRAACT_SPATIAL_MODULE_SRC_TRAACT_SPATIAL_SPATIALPLUGIN_H_
