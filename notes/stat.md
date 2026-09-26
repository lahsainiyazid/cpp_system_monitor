
    1-user: Normal processes executing in user mode
    
    2-nice: Niced (low priority) processes executing in user mode

    3-system: Processes executing in kernel mode

    4-idle: Twiddling thumbs (inactive time)

    5-iowait: Waiting for I/O to complete

    6-irq: Servicing hardware interrupts

    7-softirq: Servicing software interrupts

    8-steal: Time stolen by a hypervisor (in virtualized environments)

    9-guest: Running a virtual CPU for guest OS
    
    10-guest_nice: Running a niced guest OS
     
Cpu usage workflow:
1-We take a snapshot:
Idle->time the cpu does nothing Idle=idle+iowait 
guest is included in user (virtual user)
guest_nice is included in nice
so non_idle=user+nice+system+irq+softirq+steal 
total=Idle+non_idle
2-Now we compute deltas:
delta total and delta idle:
We wait around 1 s and compute: delta total=total(snapshot2)-total(snapshot1)
delta idle=idle(snapshot2)-idle(snapshot1)
Now we compute delta_non_idle=delta total -delta idle 
3-Compute the cpu usage:
cpu_usage=((delta non_idle)/(delta total))*100
