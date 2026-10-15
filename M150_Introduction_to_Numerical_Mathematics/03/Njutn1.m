function nj1=Njutn1(x)
tablica;
n=length(X);
krazlike=zeros(n,n-1);
for i=1:n-1
    krazlike(i,1)=Y(i+1)-Y(i);
end
for j=2:n-1
    for i=1:n-j
        krazlike(i,j)=krazlike(i+1,j-1)-krazlike(i,j-1);
    end
end
%disp([X' Y' krazlike]);
q=(x-X(1))/(X(2)-X(1));
y=Y(1);
Q=q;
for i=1:n-1
    y=y+krazlike(1,i)*q/factorial(i);
    q=q*(Q-i);
end
nj1=y;