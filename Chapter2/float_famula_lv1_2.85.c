

/*
Bias = (1 << (k-1)) -1

E = e-Bias  or E = 1-Bias

A.
    E   M      f       V
   10   1.11  0.11    7.0    
   e = bias + E = 100...0001 
   bits = 0 100...0001 1100..

B.
    n   1.11111  0.1111..   v = 2^(n+1) - 1   
    bits = 0 bias+n 111111...

C.  E = 1 - bias; M = 0b1.00000000 f= 0b0.0000
 val = 2 ^ (1 - bias)

 倒数：
 val = 2 ^ (bias - 1)

    E= bias - 1; M = 0b1.00000..  f = 0b0.000000
    e = E + bias = 2bias -1 = 2 ^ k -3;

    0 111111..01 000000...

*/  