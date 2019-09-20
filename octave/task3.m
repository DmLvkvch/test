function C = task3()
  x = 1:1:9;
  x = x';
  C = zeros(9,9);
  C .+=x;
endfunction

