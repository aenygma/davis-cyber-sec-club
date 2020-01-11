The purpose of this example is very simple.    

To introduce:  
1. the framework, particularly the `module_init` and `module_exit` functions.
2. the general rubric of a LKM module in C.

All this does is make a module, that loads into the kernel and unloads.  
It prints a debug message to the kernel ring buffer, visible via `dmesg` upon init/exit.


