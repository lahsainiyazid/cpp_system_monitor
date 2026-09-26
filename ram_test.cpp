#include<iostream>
#include <fstream>
#include<string>
#include <cstdint>

struct ram{
  uint32_t total_mem,free_mem;
  float mem_prc;
};
void get_ram_info(){
  std::string info;
  std::ifstream read_ram("/proc/meminfo");
  while (getline(read_ram,info)){
    std::cout<<info<<std::endl;
  }
}
ram get_prc(){
  std::string label,unit;
  uint32_t value;
  ram a;
  a.total_mem=0;
  a.free_mem=0;
  std::string info;
  std::ifstream read_ram("/proc/meminfo");
  while (read_ram >>label>>value>>unit){
    if(label=="MemTotal:"){
      a.total_mem=value;
    }
    if(label=="MemAvailable:"){
        a.free_mem=value;
        }
    if(a.total_mem!=0 && a.free_mem!=0){
      break;
    }
  }
  a.mem_prc=((float)a.total_mem-a.free_mem)*100.0f/a.total_mem;

return a;}




int main (){
  get_ram_info();
  ram a=get_prc();
  std::cout<<"Ram prct usage is "<<a.mem_prc;
  return 0;
}
