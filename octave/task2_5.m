function [sumH, meanH, meanH1] = task2_5(Height)
  sumH = zeros(5, 1);
  meanH = zeros(5, 1);
  meanH1 = zeros(5, 1);
  for i = 1:5
    x = Height(:,2) == i;
    x = Height(x(:,1)==1);
    sumH(i,1) = sum(x);
    meanH(i, 1) = mean(x);
    meanH1(i, 1) = mean(x(x>1 & x<2));
  endfor
endfunction
