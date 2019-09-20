
function G = task7 (n)
  G = ones(n,n);
  for i = 2:length(G)
    if(mod(i, 2)==0)
      tmp = 2*ones(length(G)-i+1, length(G)-i+1);
      G(i:end, i:end) = tmp;
    else
      tmp = ones(length(G)-i+1, length(G)-i+1);
      G(i:end, i:end) = tmp;
    endif
    endfor
endfunction
