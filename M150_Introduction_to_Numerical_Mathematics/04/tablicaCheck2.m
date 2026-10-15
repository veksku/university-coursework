function t=tablicaCheck()
tablica;

%diff(X)=[X(2)-X(1), X(3)-X(2),...,X(end)-X(end-1)];

r=all(diff(X)>0);
m=all(diff(Y)>0) || all(diff(Y)<0);
t=r&&m;
if r~=1
    disp('Niz X nije rastuci.')
end
if m~=1
    disp('Niz Y nije monoton.')
end