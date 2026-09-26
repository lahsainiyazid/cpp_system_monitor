We exploit the Linux concept that "everything is a file" using C++ fstream to read system data.
/proc          -> Contains runtime system information (virtual filesystem), including process folders and system status.
/proc/cpuinfo  -> Has static CPU hardware info (model name, core count, cache size).
/proc/stat     -> Provides cumulative CPU time across all states since the system booted.
