import sys

stanje = 'ADE'
zavrsno_stanje = 'C'

prelaz = {('ADE', 'a'):'B', ('ADE', 'b'):'C', ('ADE','c'):'ADE',
            ('B', 'b'):'ADE'}

while True:

    try:
        c=input("Unesite a,b ili c\n")
        if(c!='a' and c!= 'b' and c!='c'):
            sys.exit("Pogresno slovo")
    except EOFError:
        break

    if prelaz.get((stanje,c)) is None:
        sys.exit("Rec nije deo jezika")

    stanje = prelaz[(stanje,c)]
    print('Trenutno stanje: ' + stanje)

if (stanje == zavrsno_stanje):
	print("Rec je deo jezika")
else:
	print("Rec nije deo jezika")