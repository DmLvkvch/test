function B1 = task2_2 (B)
  b = B(1:end/2,:);
  c = B(end/2+1:end,:);
  B1 = B;
  B1(1:end/2,:) = c;
  B1(end/2+1:end,:) = b;
endfunction

