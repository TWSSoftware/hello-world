# CS4280-Compiler
Compiler Repository

The code generation of the compiler was a modification of my static 
semantics function. It will take any .fs182 file or input from the 
user and create a .asm file. The .asm file can be read by VirtMach.
I was able to test all the test files given to me and they seemed
to work except for the test global file which will be errored by 
static semantics because I did the local option for the static 
semantics. 