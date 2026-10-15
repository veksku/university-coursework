function x=LUdekomp(A,b)

% kod za LU dekompoziciju (nije ugraðena funkcija, jedinice po dijagonali kod U)

n = length(A);
L = zeros(n);
U = eye(n);

L(:, 1) = A(:, 1);
U(1, 2:n) = A(1, 2:n) / L(1, 1);

for i = 1:n
    for j = 1:n
        if j <= i
            L(i, j) = A(i, j) - (L(i, 1:(j-1)) * U(1:(j-1), j));
        else 
            U(i, j) = (A(i, j)-L(i, 1:i-1) * U(1:i-1, j)) / L(i, i); 
        end
    end
end
disp('L =');
disp(L);
disp('U =');
disp(U);

%%%%%%%%%%%%%% rešavamo sistem L*y = b %%%%%%%%%%%%%%
y = zeros(n, 1);
y(1) = b(1) / L(1, 1);
for i = 2:n
    y(i) = (b(i) - (L(i, 1:i-1) * y(1:i-1))) / L(i, i);
end
disp('y=')
disp(y)
%%%%%%%%%%%%%% rešavamo sistem U*x = y %%%%%%%%%%%%%%
x=zeros(n,1);
x(n)=y(n);
for j=n-1:-1:1
    x(j)=y(j)-(U(j,j+1:n)*x(j+1:n));
end