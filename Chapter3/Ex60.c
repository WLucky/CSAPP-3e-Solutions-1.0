/*
A. 
    x       %rdi
    n       %esi
    result  %rax
    mask    %rdx
B.  
    result = %eax = 0
    mask = %edx = 1
C.  
    mask != 0
D.  
    mask << n
E.  
    (mask & x) | result
F. 

*/

long loop(long x, int n)
{
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask = mask << n)
    {
        result |= (mask & x);
    }
    return result;
}