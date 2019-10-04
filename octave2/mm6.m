function mm6 (A, xrange, yrange)
  qwe = size(A(:,1))
  for i =1:size(A(:,1))
    x = A(i,:)
    mm5(A(i,:), xrange, yrange);
  endfor
endfunction