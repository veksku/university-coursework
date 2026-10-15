function d = dominantna(A)

n = length(A);
d = zeros(n, 1); % el. d(i) nosiæe informaciju o ispunjenosti uslova u i-toj vrsti

for i = 1:n
    % Proveravamo da li je suma apsolutnih vrednosti vandijagonalnih el. i-te vrste 
    % manja od apsolutne vrednosti el. na dijagonali
    if sum(abs(A(i, :))) - abs(A(i, i)) <  abs(A(i, i)) 
        d(i) = 1; 
    else
        d(i) = 0;
    end
end
d = all(d==1);
% ili d = all(d);