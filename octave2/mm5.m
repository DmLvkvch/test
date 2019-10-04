function mm5 (coef_line, xrange, yrange)
  vertl = [1 0 -xrange(1)];
  vertr = [1 0 -xrange(2)];
  horu =  [0 1 -yrange(2)];
  hord =  [0 1 -yrange(1)];
  [x, y] = all_lines_intersections([coef_line;vertl;vertr;horu; hord]);
  n = 2;
  t1 = x(2:end,1);
  t2 = y(2:end,1);
  eps = 0.01;
  #here was bug - 100<100.000???
  #in task5 it works [0.528849   0.663419   0.548161], [-100 10], [-10 100]
  tmp1 = ((t1>=xrange(1)+eps | t1>=xrange(1)-eps)  & (t1<=xrange(2)+eps | t1<=xrange(2)-eps))
  t1 = t1(tmp1==1)
  t2 = t2(tmp1==1)
  tmp2 = ((t2>=yrange(1)+eps | t2>=yrange(1)-eps) & (t2<=yrange(2)+eps | t2<=yrange(2)-eps))
  t1 = t1(tmp2==1)
  t2 = t2(tmp2==1)
  plot(t1, t2, "b;;");
  hold on
endfunction