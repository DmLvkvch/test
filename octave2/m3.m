function L1 = m3(L)
  len = size(L, 1);       
L1 = zeros(len, 2);
col1 = -L(:,1)./L(:,2);
col2 = -L(:,3)./L(:,2);
L1(:,1) = col1;
L1(:,2) = col2;
endfunction    
