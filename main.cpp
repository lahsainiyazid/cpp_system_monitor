#include<iostream>
#include<fstream>
#include<cstdint>
#include<thread>
#include<chrono>
struct snapshot {
   uint32_t user,nice,system,idle,iowait,irq,softirq,steal;
};


void get_from_cpu(){
  std::string info;
  std::ifstream cpu_file("/proc/cpuinfo");
  while (getline(cpu_file,info)){
    std::cout<<info<<std::endl;
  }
cpu_file.close();}
void get_cpu_stat(){
  std::string info;
  std::ifstream stat_file("/proc/stat");
  while(getline(stat_file,info)){
    
  }
stat_file.close();}
snapshot get_cpu_snpashot(){
  snapshot shot;
  std::string label;
  std::ifstream stats("/proc/stat");
  stats>>label;
  if (label=="cpu"){
   stats>>shot.user>>shot.nice>>shot.system>>shot.idle>>shot.iowait>>shot.irq>>shot.softirq>>shot.steal;
  }
stats.close();
return shot;}
  double cpu_usage_prct(snapshot shot1,snapshot shot2){
      uint32_t non_idle_1=(shot1.user+shot1.nice+shot1.system+shot1.irq+shot1.softirq+shot1.steal);
      uint32_t non_idle_2=(shot2.user+shot2.nice+shot2.system+shot2.irq+shot2.softirq+shot2.steal);
      uint32_t idle1=(shot1.idle+shot1.iowait);
      uint32_t idle2=(shot2.idle+shot2.iowait);
      uint32_t total_1=non_idle_1+idle1;
      uint32_t total_2=non_idle_2+idle2;
      uint32_t delta_non_idle=non_idle_2-non_idle_1;
      uint32_t delta_total=(total_2-total_1);
      return (delta_non_idle *100)/(delta_total);}
int main (){
  std::cout<<"Taking first snapshot"<<std::endl;
  snapshot shot1=get_cpu_snpashot();
  std::cout<<"Waiting for 1s +Taking second snapshot"<<std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  snapshot shot2=get_cpu_snpashot();
  double cpu_prct=cpu_usage_prct(shot1,shot2);
  std::cout<<"The cpu usage is of :"<<cpu_prct<<"%"<<std::endl;
  return 0;
}
