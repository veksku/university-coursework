import sys
import re

try:
	with open("televizori.xml", "r") as f:
		podaci = f.read()
except IOError:
	sys.exit("open")

ri = re.compile(r'<televizor\s+id\s*=\s*"\s*(?P<rbr>[0-9]+)\s*"\s*>\s*' 
				+ r'(?=.*?<rmarka>\s*(?P<marka>([A-Za-z0-9]\s*)+)</rmarka>)'
				+ r'(?=.*?<model>\s*(?P<model>([A-Za-z0-9\s,.+;?!])+)\s*</model>)'
				+ r'(?=.*?<godina>\s*(?P<godina>\d{4})\s*</godina>)'
				+ r'(?=.*?<diag>\s*(?P<diag>[1-9][0-9](\.\d+)?)\s*</diag>)'
				+ r'(?=.*?<kolicina>\s*(?P<kolicina>\d+)\s*</kolicina>)'
				+ r'(?=.*?<panel>\s*(?P<panel>(TN|IPS|VA|LED)-(HD|FHD|UHD|HDR))\s*</panel>)'
				+ r'(?=.*?<cena>\s*(?P<cena>\d+)\s*</cena>)'
				+ r'.*?</televizor>', 
				re.S)

#za testiranje
#for m in ri.finditer(podaci):                
#	print(m.group())

televizori = {}

for m in ri.finditer(podaci):
	rbr = m.group('rbr')
	marka = m.group('marka')
	model = m.group('model')
	godina = int(m.group('godina'))
	diag = float(m.group('diag'))
	kolicina = int(m.group('kolicina'))
	panel = m.group('panel')
	cena = int(m.group('cena'))

	televizori[rbr] = [marka,model,godina,diag,panel,cena,kolicina]

if len(sys.argv) < 2:
	for k,v in televizori.items():
		if v[-1] > 0:
			print(k + ":")
			print(v)

else:
	if sys.argv[1]=='-r' and len(sys.argv)==3:
		robna_marka = sys.argv[2]
		for k,v in televizori.items():
			if v[0] == robna_marka:
				print(v)
	elif sys.argv[1]=='-c' and len(sys.argv)==4:
		cmin = int(sys.argv[2])
		cmax = int(sys.argv[3])
		for k,v in televizori.items():
			if (v[-2] <= cmax and v[-2] >= cmin):
				print(v)
	elif sys.argv[1]=='-d' and len(sys.argv)==4:
		dmin = float(sys.argv[2])
		dmax = float(sys.argv[3])
		for k,v in televizori.items():
			if (v[3] <= dmax and v[3] >= dmin):
				print(v)
	elif sys.argv[1]=='-g' and len(sys.argv)==3:
		godina_izdanja = int(sys.argv[2])
		for k,v in televizori.items():
			if v[2] == godina_izdanja:
				print(v)
	else:
		print("Greska")
