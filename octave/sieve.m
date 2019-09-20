function a = sieve (n)
  ## your answer here
  function a = filter_multiples (a, k)
      a = a(!((rem(a, k))==0 & a>k));
  endfunction
  
  a = 1:n;
  a(:) = filter_multiples(a,a(:)); 
  #i = 2;
  #while (i < length (a))
    #a = filter_multiples (a, a(i));
    #i++;
  #endwhile
endfunction