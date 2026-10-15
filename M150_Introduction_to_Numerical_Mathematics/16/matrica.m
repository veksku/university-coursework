function [A, b, x] = matrica(broj, d)

b = ones(d, 1); % vektor kolona dužine d sa svim jedinicama
ad = broj*10*ones(d,1);

% Formiramo matricu koja na glavnoj dijagonali ima vektor ad
A = diag(ad);

% Poziv diag(ad, 1) formiraæe matricu koja na prvoj naddijagonali ima vektor ad 
% Poziv diag(ad, -1) formiraæe matricu koja na prvoj poddijagonali ima vektor ad 

for i = 1:d-1
    ad = ones(d-i, 1);
    % popunjavamo matricu ispod (II sabirak) i iznad (I sabirak) glavne dijagonale
    A = A + diag(ad*(broj-i),-1*i) + diag(ad,i); 
end

disp('A =')
disp(A)
x = sistem(A, b);
disp('Resenje sistema je: ')
disp(x)
%Taèno rešenje sistema se može dobiti naredbom x = A\b
