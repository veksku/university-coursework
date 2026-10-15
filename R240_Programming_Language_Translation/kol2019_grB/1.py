import sys
import re

try:
    with open("vozilo.xml", 'r') as f:
        podaci = f.read()
except IOError:
    print("open")

ri = re.compile(r'<vozilo\s+id\s*=\s*"\s*(?P<id>\d+)\s*"\s*>' +
                r'(?=.*?<fabrika>\s*(?P<fabrika>[A-Za-z ]+)\s*</fabrika>\s*)' +
                r'(?=.*?<model>\s*(?P<model>[a-zA-Z\d ,.?!-:;]+)\s*</model>\s*)' +
                r'(?=.*?<godina>\s*(?P<godina>\d{4})\s*</godina>\s*)' +
                r'(?=.*?<cena>\s*(?P<cena>\d+)\s*</cena>\s*)' +
                r'(?=.*?<snaga_motora>\s*(?P<snaga_motora>\d+)\s*</snaga_motora>\s*)' +
                r'(?=.*?<zapremina>\s*(?P<zapremina>([7-9][0-9]{2}|[1-9]\d{3,4})(\.\d)?)\s*</zapremina>\s*)' +
                r'(?=.*?<gorivo>\s*(?P<gorivo>(Benzin|Dizel|TNG)-(EURO3|EURO4|EURO5|EURO6))\s*</gorivo>\s*)' +
                r'.*?</vozilo>',re.S)

vozilo = {}

#for m in ri.finditer(podaci):
#    print(m.group())

for m in ri.finditer(podaci):
    id = int(m.group('id'))
    fabrika = m.group('fabrika')
    model = m.group('model')
    godina = int(m.group('godina'))
    cena = int(m.group('cena'))
    snaga_motora = int(m.group('snaga_motora'))
    zapremina = float(m.group('zapremina'))
    gorivo = m.group('gorivo')

    vozilo[id] = [fabrika,model,godina,cena,snaga_motora,zapremina,gorivo]




if len(sys.argv) < 2:
    for k,v in vozilo.items():
        print(v)
else:
    if sys.argv[1] == '-f' and len(sys.argv) == 3:
        fabr = sys.argv[2]
        for k,v in vozilo.items():
            if fabr == v[0]:
                print(v)
    elif sys.argv[1] == '-c' and len(sys.argv) == 4:
        cmin = int(sys.argv[2])
        cmax = int(sys.argv[3])
        for k,v in vozilo.items():
            if (v[3] <= cmax and v[3] >= cmin):
                print(v)
    elif sys.argv[1] == '-z' and len(sys.argv) == 4:
        zmin = float(sys.argv[2])
        zmax = float(sys.argv[3])
        for k,v in vozilo.items():
            if (v[-2] <= zmax and v[-2] >= zmin):
                print(v)
    elif sys.argv[1] == '-g' and len(sys.argv) == 4:
        gorivo = sys.argv[2]
        norma = sys.argv[3]
        s = gorivo + "-" + norma
        for k,v in vozilo.items():
            #print(k)
            #print(v[-1])
            #print(s)
            if (s == v[-1]):
                print(v)
    else:
        sys.exit("Greska")
