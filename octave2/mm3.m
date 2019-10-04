function mm3

  A = rand(2, 10);
  x = A(1,:);
  y = A(2,:);
  m = ones(1, 10);
  plot(x, y, "ro;A;")
  hold on

  xc = sum(x);
  yc = sum(y);
  M = sum(m);
  xc = xc/M;
  yc = yc/M;
  plot(xc, yc, "bo;mc;");

  newx = x-xc;
  newy = y-yc;
  plot(newx, newy, "go;B;");
  
  hold on
  newxc = sum(newx)/M;
  newyc = sum(newy)/M;
  plot(newxc, newyc, "yo;newmc;");
  
  hold on
  deg = 5;
  rot = [cos(deg2rad(deg)) sin(deg2rad(deg));
        -sin(deg2rad(deg)) cos(deg2rad(deg))];
  C = zeros(2, 10);
  C = rot*[x;y]; 
  plot(C(1,:), C(2,:), "mo;C;")
  hold on
  
  D = zeros(2, 10);
  D = rot*[newx; newy];
  D(1,:)+=xc;
  D(2,:)+=yc;
  plot(D(1,:), D(2,:), "co;D;")
  hold on
  
endfunction