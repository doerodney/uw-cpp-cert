// Copyright [2021] cpplint placation
#include "probe.h"

Probe::Probe(): active_instances(0), created_instances(0) {}

void Probe::Increment() {
  active_instances++;
  created_instances++;
}


void Probe::Decrement() {
  if (active_instances > 0) {
    active_instances--;
  }
}

std::ostream& operator<<(std::ostream& stream,Probe& probe) {
    stream << std::endl
           << std::string("Created Instances: ")
           << probe.created_instances
           << std::endl
           << std::string("Active Instances")
           << probe.active_instances
           << std::endl;
    return stream;
}
