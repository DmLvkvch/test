function [x, y] = all_lines_intersections(A)
  x = zeros(size(A(:,1)), 1);
  y = zeros(size(A(:,1)), 1);
  t = all2dets([A(:,1) A(:,2)]);
  tx = all2dets([-1*A(:,3) A(:,2)]);
  ty = all2dets([A(:,1) -1*A(:,3)]);
  x = tx./t
  y = ty./t
endfunction
