function x = sistem(A,b)

n = length(A); % Kada se length() primeni na matricu, vraæa broj vrsti 
A1 = zeros(n);
b1 = zeros(n,1);

% Potrebno je transformisati sistem Ax = b u oblik x = A1*x + b1
for i = 1:n
    A1(i,:) = -A(i,:) / A(i,i); % i-tu vrstu delimo sa -A(i,i)
    A1(i,i) = 0;                % na dijagonali su 0
    b1(i) = b(i) / A(i,i);      % i-ti el. vektora b delimo sa A(i,i)
end
disp('A1 =')
disp(A1)
disp('b1 =')
disp(b1)

% Poèetna aproksimacija rešenja je vektor b1
x = b1;

% Za dobijanje nove aproksimacije koristi se rekurentna formula: x_n = A1*x_n-1 + b1
for i = 1:50
    x= A1 * x + b1;
end
