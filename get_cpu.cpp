#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>

struct cpu {
  std::string name;
};

void get_model_name(){
  std::string info;
  cpu infos;
 std::ifstream cpu_file("/proc/cpuinfo");
   while (getline(cpu_file,info)){
     if (info.find("model name")==0){
       infos.name=info;
     }
   }
  std::cout<<infos.name<<std::endl;
cpu_file.close();}

void get_from_cpu(){
  std::string info;
  std::ifstream cpu_file("/proc/cpuinfo");
  std::unordered_map<size_t,std::string>infos;
  while (getline(cpu_file,info)){
    std::cout<<info<<std::endl;
  }
cpu_file.close();}

int main (){
  std::cout<<"Reading model_name file:"<<std::endl;
  get_model_name();
  std::cout<<"Reading from cpu file"<<std::endl;
  get_from_cpu();
  return 0;
}
