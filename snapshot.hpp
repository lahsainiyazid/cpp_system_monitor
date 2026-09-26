#pragma once 
#include<cstdint>
#include<fstream>
struct snapshot {
   uint32_t user,nice,system,idle,iowait,irq,softirq,steal;
};
snapshot get_cpu_snapshot();
double get_cpu_usage_prc(snapshot shot1,snapshot shot2);
