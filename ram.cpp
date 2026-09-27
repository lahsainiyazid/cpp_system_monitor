#include "ram.hpp"


ram get_ram_prc(){
  std::string label,unit;
  uint32_t value;
  ram a;
  a.tot_mem=0;
  a.av_mem=0;
  std::string info;
  std::ifstream read_ram("/proc/meminfo");
  while (read_ram >>label>>value>>unit){
    if(label=="MemTotal:"){
      a.tot_mem=value;
    }
    if(label=="MemAvailable:"){
        a.av_mem=value;
        }
     if(a.tot_mem!=0 && a.av_mem!=0){
      break;
    }
  }
  a.mem_prc=((float)a.tot_mem-a.av_mem)*100.0f/a.tot_mem;

return a;}

