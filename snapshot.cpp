#include "snapshot.hpp"


snapshot get_cpu_snapshot(){
  snapshot shot;
  std::string label;
  std::ifstream stats("/proc/stat");
  stats>>label;
  if (label=="cpu"){
   stats>>shot.user>>shot.nice>>shot.system>>shot.idle>>shot.iowait>>shot.irq>>shot.softirq>>shot.steal;
  }
stats.close();
return shot;}
  double get_cpu_usage_prc(snapshot shot1,snapshot shot2){
      uint32_t non_idle_1=(shot1.user+shot1.nice+shot1.system+shot1.irq+shot1.softirq+shot1.steal);
      uint32_t non_idle_2=(shot2.user+shot2.nice+shot2.system+shot2.irq+shot2.softirq+shot2.steal);
      uint32_t idle1=(shot1.idle+shot1.iowait);
      uint32_t idle2=(shot2.idle+shot2.iowait);
      uint32_t total_1=non_idle_1+idle1;
      uint32_t total_2=non_idle_2+idle2;
      uint32_t delta_non_idle=non_idle_2-non_idle_1;
      uint32_t delta_total=(total_2-total_1);
      return (delta_non_idle *100)/(delta_total);}

