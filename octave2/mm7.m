function mm6 (A, xrange, yrange)
  mm6(A, xrange, yrange);
  [x_, y_] = all_lines_intersections(A);
  x_ = reshape(x_, 1, size(A)(1)*size(A)(1));
  y_ = reshape(y_, 1, size(A)(1)*size(A)(1));
  t1 = x_;
  t2 = y_;
  eps = 0.01;
  #here was bug - 100<100.000???
  #in task5 it works [0.528849   0.663419   0.548161], [-100 10], [-10 100]
  tmp1 = ((t1>=xrange(1)+eps | t1>=xrange(1)-eps)  & (t1<=xrange(2)+eps | t1<=xrange(2)-eps))
  t1 = t1(tmp1==1)
  t2 = t2(tmp1==1)
  tmp2 = ((t2>=yrange(1)+eps | t2>=yrange(1)-eps) & (t2<=yrange(2)+eps | t2<=yrange(2)-eps))
  t1 = t1(tmp2==1)
  t2 = t2(tmp2==1)
  plot(t1, t2, "ro;;");
  hold on
endfunction
