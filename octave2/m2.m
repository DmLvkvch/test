function X = m2 (x)
      X = zeros(size(x(:,1)), size(x(:,1)));
    X = x.-x';
endfunction