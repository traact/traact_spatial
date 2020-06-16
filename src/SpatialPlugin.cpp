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

#include <rttr/registration>
#include <rttr/type>
#include <traact/facade/Plugin.h>

#include "traact/spatial.h"
#include "traact/spatialBody.h"
#include "component/MultiplicationComponent.h"
#include "component/Pose6DPrint.h"
#include "component/PrintBodyList.h"
#include "traact/component/spatial/util/Pose6DTestSource.h"

namespace traact::spatial {


class SpatialPlugin : public traact::facade::Plugin {
 public:
  void fillDatatypeNames(std::vector<std::string> &datatype_names) override {
    datatype_names.emplace_back(Pose6DHeader::MetaType);
    datatype_names.emplace_back(BodyHeader::MetaType);
    datatype_names.emplace_back(BodyListHeader::MetaType);
  }
  void fillPatternNames(std::vector<std::string> &pattern_names) override {
    pattern_names.emplace_back("MultiplicationComponent");
    pattern_names.emplace_back("Pose6DPrint");
    pattern_names.emplace_back("Pose6DTestSource");
    pattern_names.emplace_back("PrintBodyList");
  }
  buffer::GenericFactoryObject::Ptr instantiateDataType(const std::string &datatype_name) override {
    if (datatype_name == std::string(Pose6DHeader::MetaType))
      return std::make_shared<Pose6DFactoryObject>();
    else if (datatype_name == std::string(BodyHeader::MetaType))
      return std::make_shared<BodyFactoryObject>();
    else if (datatype_name == std::string(BodyListHeader::MetaType))
      return std::make_shared<BodyListFactoryObject>();
    return nullptr;
  }
  pattern::Pattern::Ptr instantiatePattern(const std::string &pattern_name) override {
    if (pattern_name == "MultiplicationComponent")
      return component::spatial::core::MultiplicationComponent::getPattern();
    else if (pattern_name == "Pose6DPrint")
      return component::spatial::util::Pose6DPrint::getPattern();
    else if (pattern_name == "Pose6DTestSource")
      return component::spatial::util::Pose6DTestSource::getPattern();
    else if (pattern_name == "PrintBodyList")
      return component::spatial::util::PrintBodyList::getPattern();

    return nullptr;
  }
  component::Component::Ptr instantiateComponent(const std::string &pattern_name,
                                                 const std::string &new_component_name) override {

    if (pattern_name == "MultiplicationComponent")
      return std::make_shared<component::spatial::core::MultiplicationComponent>(new_component_name);
    else if (pattern_name == "Pose6DPrint")
      return std::make_shared<component::spatial::util::Pose6DPrint>(new_component_name);
    else if (pattern_name == "Pose6DTestSource")
      return std::make_shared<component::spatial::util::Pose6DTestSource>(new_component_name);
    else if (pattern_name == "PrintBodyList")
      return std::make_shared<component::spatial::util::PrintBodyList>(new_component_name);

    return nullptr;
  }
};

}

// It is not possible to place the macro multiple times in one cpp file. When you compile your plugin with the gcc toolchain,
// make sure you use the compiler option: -fno-gnu-unique. otherwise the unregistration will not work properly.
RTTR_PLUGIN_REGISTRATION // remark the different registration macro!
{

  using namespace rttr;
  registration::class_<traact::spatial::SpatialPlugin>("SpatialPlugin").constructor<>()
      (
          policy::ctor::as_std_shared_ptr
      );
}