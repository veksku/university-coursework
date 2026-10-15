function L=legendre_poly(n)
L{1} = 1;
L{2} = [1 0];
for i=2:n
  L{i+1} = ([(2*i-1)*L{i} 0]-[0 0 (i-1)*L{i-1}])/i;
end
X=linspace(-1,1);
hold on
for i=1:n+1
  plot(X,polyval(L{i},X));
end
hold off
celldisp(L);