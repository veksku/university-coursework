function X = LUdekompozicija(A, b)

% Rešavamo sistem Ax = b metodom LU dekompozicije
% Na primer:
% A = [24.21 2.42 3.85; 2.31 31.49 1.52; 3.49 4.85 28.72]; 
% b = [1 0 0]';

n = length(b);
% Koristimo ugraðenu funkciju lu() koja vraæa matrice L, U i P
[L U P] = lu(A);

disp('L =')
disp(L)
disp('U =')
disp(U);

% Sada se problem Ax = b svodi na rešavanje dva nova sistema
% L*y = b
% ----------------------------------------
% L(1,1)*y(1)                                      = b(1)
% L(2,1)*y(1) + L(2,2)*y(2)                        = b(2)
% L(2,1)*y(1) + L(2,2)*y(2) + L(2,3)*y(3)          = b(2)
% .....
% L(n,1)*y(1) + L(n,2)*y(2)+    ...   + L(n,n)*y(n)= b(n)
% ----------------------------------------
% U*x = y
% ----------------------------------------
% U(1,1)*x(1) + U(1,2)*x(2) +   ...   + U(1,n)*x(n) = y(1)
%               U(2,2)*x(2) +   ...   + U(2,n)*x(n) = y(2)
%                         .....
%                 U(n-1,n-1)*x(n-1) + U(n-1,n)*x(n) = y(n-1)
%                                       U(n,n)*x(n) = y(n)
% ----------------------------------------
%%%%%%%%%%%%%% rešavamo sistem L*y = b %%%%%%%%%%%%%%
y = zeros(n, 1);
y(1) = b(1);

for i = 2:n
    y(i) = (b(i) - (L(i, :) * y));
end

disp('y =')
disp(y)
%%%%%%%%%%%%%% rešavamo sistem U*x = y %%%%%%%%%%%%%%
X = zeros(n, 1);
X(n) = y(n) / U(n, n);

for i = n-1:-1:1
    X(i) = (y(i) - U(i, :) * X) / U(i, i);
end