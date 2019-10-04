t = linspace(0,2*pi,100)'; 
r = 1:1:10;
circsx = zeros(10,size(t));
circsy = zeros(10,size(t));
circsx = r.*cos(t); 
circsy = r.*sin(t);
x = reshape(circsx, 1, 10*size(t)) 
y = reshape(circsy, 1, 10*size(t)) 
plot(circsx,circsy, "r;;"); 