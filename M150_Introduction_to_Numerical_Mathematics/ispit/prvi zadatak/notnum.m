function [F,P]=notnum(f)
n = length(f);
P = 1;
for i=1:n
    P=conv(P, [(-1)^i, 0, -f(i)];
endfor
a=ceil(max(f));
if a<0
  a=1;
endif
vrsta=a.*(0:n-1);
F=ones(n);
for i=2:n
  F(i,:)=vrsta.^i;
endfor