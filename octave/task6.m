function F = task6(n, a, b)
  F = a*eye(n);
  y = b*eye(n);
  z = b*eye(n);
  if(n!=0)
    y(1,:) = [];
    y(end+1,:) = zeros(n,1);
    z = rot90(y,2);
    F = F+y+z;
  endif
endfunction