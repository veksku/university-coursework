import sys, json

if len(sys.argv) != 2:
	print("Neispravan broj ulaznih argumenata, poziva se sa python3 <imedatoteke>")
	sys.exit()
	
path = sys.argv[1]

try:
	with open(path, "r") as f:
		igraci = json.load(f)
except IOError:
	print("Fajl ne postoji, proveri putanju i probaj ponovo!")
	sys.exit()

input_godina = input("Unesite gornju granicu starosti igraca: ")
input_pozicija = input("Unesite poziciju igraca: ")

max_visina = -1
ime_igraca = ''
prezime_igraca = ''

for igrac in igraci:
	visina = igrac['visina']
	godine = igrac['godine']
	pozicija = -1
	if visina < 190:
		pozicija = 1
	elif visina >= 200:
		pozicija = 5
	else:
		pozicija = 3
		
	if godine <= int(input_godina):
		if visina > max_visina:
			if pozicija == int(input_pozicija):
				max_visina = visina
				ime_igraca = igrac['ime']
				prezime_igraca = igrac['prezime']

print(ime_igraca + " " + prezime_igraca)				
print("Visina: " + str(max_visina))
