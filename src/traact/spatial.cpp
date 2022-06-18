/** Copyright (C) 2022  Frieder Pankratz <frieder.pankratz@gmail.com> **/

#include "traact/spatial.h"

namespace  traact::component::facade {
    CREATE_SPATIAL_COMPONENTS(ApplicationAsyncSource)
    CREATE_SPATIAL_COMPONENTS(ApplicationSyncSink)
}

BEGIN_TRAACT_PLUGIN_REGISTRATION
    REGISTER_DEFAULT_TRAACT_TYPE(traact::spatial::Pose6DHeader)
    REGISTER_SPATIAL_COMPONENTS(traact::component::facade::ApplicationAsyncSource)
    REGISTER_SPATIAL_COMPONENTS(traact::component::facade::ApplicationSyncSink)
//    REGISTER_DEFAULT_TRAACT_TYPE(traact::spatial::Position2DHeader)
//    REGISTER_DEFAULT_TRAACT_TYPE(traact::vision::Position2DListHeader)
//    REGISTER_DEFAULT_TRAACT_TYPE(traact::spatial::Position3DHeader)
//    REGISTER_DEFAULT_TRAACT_TYPE(traact::spatial::Position3DListHeader)
END_TRAACT_PLUGIN_REGISTRATION


