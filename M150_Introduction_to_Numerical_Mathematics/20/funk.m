% I test
% y = funk(0.15)
% dobija se da je y = -0.8500

% II test
%

function y = funk(x)

tablica;
n = length(X);
pr = zeros(n,n-1);

for i=1:n-1
    pr(i,1)=(F(i+1)-F(i))/(X(i+1)-X(i));
end

for j=2:n-1
    for i = 1: n-j
        pr(i,j) = (pr(i+1,j-1)-pr(i,j-1))/(X(i+j)-X(i));
    end
end
%[X' F' pr]
polinom = [ F(1)];
r  = [1];

for i=1:n-1
    r = conv(r,[1 -X(i)]);
    polinom = [0 polinom] + r*pr(1,i);
end
y = polyval(polinom, x);
end