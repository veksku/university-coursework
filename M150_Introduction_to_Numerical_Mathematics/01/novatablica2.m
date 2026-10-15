tablica;
n=length(X);
X1=zeros(1,2*n-1);
Y1=zeros(1,2*n-1);

X1(1:2:2*n-1)=X(1:end); 
X1(2:2:2*n-1)=(X(1:end-1)+X(2:end))/2

Y1(1:2:2*n-1)=Y(1:end);
Y1(2:2:2*n-1)=(Y(1:end-1)+Y(2:end))/2
