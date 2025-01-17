#include <string>
#include <vector>

#include "processor.h"
#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  float utilization{0};
  long active_ticks = LinuxParser::ActiveJiffies();
  long idle_ticks = LinuxParser::IdleJiffies();
  long duration_active{active_ticks - cached_acitve_ticks_};
  long duration_idle{idle_ticks - cached_idle_ticks_};
  long duration{duration_active + duration_idle};
  utilization = static_cast<float>(duration_active) / duration;
  cached_acitve_ticks_ = active_ticks;
  cached_idle_ticks_ = idle_ticks;
  return utilization;
}