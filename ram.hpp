#pragma once 
#include<fstream>
#include<string>
#include<cstdint>

//We define our ram struct:
struct ram {
  uint32_t tot_mem,av_mem; //tot->total memory,av->available memory 
  float mem_prc;
};
//We define our functions signatures:
ram get_ram_prc();


