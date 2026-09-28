There is no single file for ranked processes in linux so the solution is :
loop through all current processes ->push to vector ->sort by usage->Return top processes.
1-Loop through all processes we use <filesystem> 

