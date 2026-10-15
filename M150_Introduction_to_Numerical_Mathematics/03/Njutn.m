function nj=Njutn(x)
if tablicaCheck()==1
    if polozaj(x)==1
        nj=Njutn1(x);
    else 
        if polozaj(x)==2
            nj=Njutn2(x);
        else
            nj=0;
            disp('Tacka je u sredini');
        end
    end
end