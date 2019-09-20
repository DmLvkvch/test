function C1 = task2_6 (C)
b = C.*(mod(C,2)==0);
c = C.*(mod(C,2)!=0);
c*=2;
C1 = b+c;
endfunction