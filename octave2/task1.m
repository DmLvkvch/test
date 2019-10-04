function y = task1 (a, x)
  deg = 0:1:length(a)-1
  poly = zeros(1, length(a))
  poly = x.^deg
  y = a.*poly
  y = sum(y)
endfunction