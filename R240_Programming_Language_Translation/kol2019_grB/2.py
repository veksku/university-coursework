import sys

stanje = 'A'
zavrsno_stanje = 'D'

prelaz = {('A','b'): 'B', ('A','c'):'CE',
            ('B','b'):'D',
            ('CE','a'):'CE', ('CE','b'):'D'}

while True:
    
    try:
        c = input("\nCtrl+Z+Enter za EOF\n\n\nUnesite a, b ili c\n")
        if(c!='a' and c!='b' and c!='c'):
            sys.exit("Pogresno slovo\n")
    except EOFError:
        break

    if prelaz.get((stanje,c)) is None:
        sys.exit("Nedozvoljena rec")

    stanje = prelaz[(stanje,c)]
    print("Trenutno stanje: " + stanje)

if(stanje== zavrsno_stanje):
    print("Rec se prihvata")
else:
    print("Rec se ne prihvata")
