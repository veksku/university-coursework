function L=Lagr1(x)
novatablica2;
n=length(X1);
L=0;
for i=1:n
    p=1;
    for j=1:n
        if i~=j
            p=p*(x-X1(j))/(X1(i)-X1(j));
        end
    end
    L=L+p*Y1(i);
end
