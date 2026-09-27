#include<iostream>
#include<thread>
#include<chrono>
#include "snapshot.hpp"
#include"ram.hpp"
 int main (){
  std::cout<<"Taking first snapshot"<<std::endl;
  snapshot shot1=get_cpu_snapshot();
  std::cout<<"Waiting for 1s +Taking second snapshot"<<std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  snapshot shot2=get_cpu_snapshot();
  double cpu_prct=get_cpu_usage_prc(shot1,shot2);
  std::cout<<"The cpu usage is of :"<<cpu_prct<<"%"<<std::endl;
  ram a;
  a=get_ram_prc();
  std::cout<<"The ram prc is of: "<<a.mem_prc<<"%"<<std::endl;
  return 0;
}
