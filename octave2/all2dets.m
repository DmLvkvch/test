function Y = all2dets (X)
  Y = zeros(size(X(:,1)), size(X(:,1)));
  tmp = X(:,1)*X(:,2)';
  Y = tmp-tmp';
endfunction

