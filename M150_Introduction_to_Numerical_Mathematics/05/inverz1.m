function x=inverz1(y)
[X,Y]=tablica();
disp([X,Y])
[X1, I]=sort(Y);
Y1=X(I);

% [X1 I]= sort(Y)
% X1=vektor Y sortiran rastuce
% I= vektor t.d. Y(I)=X1,

disp([X1 Y1])

x=Lagr(y,X1,Y1);

function y=Lagr(x,X,Y)
n=length(X);
y=0;
for i=1:n
    p=1;
    for j=1:n
        if i~=j
            p=p*(x-X(j))/(X(i)-X(j));
        end
    end
    y=y+p*Y(i);
end



