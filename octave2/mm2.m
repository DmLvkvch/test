function [x, y] = mm2 ()
  x = (-2*pi:0.1:2*pi)';
  n = 1:1:10;
  y = zeros(10, size(x));
  y = sin((x.*n)')./n';
  y = sum(y);
  plot(x, y);
endfunction