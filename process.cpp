#include<iostream>
#include<vector>
#include<cstdint>
#include<filesystem>
#include<fstream>
#include<string>
struct process{
  uint16_t id,usage;
  double cpu,ram;
};
bool is_pid(std::string &name){
  if (name.empty()){
    return false;
  }
  else{
    for (size_t i=0;i<name.size();i++){
      if(name[i]<<'0'||name[i]>'9'){
        return false;
      }
    }
  return true;}
 get_cpu_usage(int pid){std::string=std::to_string(pid);
  
 }
}
int main (){
  std::vector<process>vec;
  std::cout<<"Successfuly created struct and vector of structs"<<std::endl;
  for (const auto &entry: std::filesystem::directory_iterator("/proc")){
   std::string file=entry.path().filename().string();
   if (! is_pid(file)){continue;}
   else{
   int pid=std::stoi(name);
   double cpu_usage=get_cpu_usage(pid);
   double ram_usage=get_ram_usage(pid);
   vec.push_back({pid,cpu_usage,ram_usage})

   }
  }
  return 0;
}
