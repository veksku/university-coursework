import sys, json

def gcd(x, y):
	
	if x == 1 and y == 1:
		return True
		
	i = 2
	if x > y:
		while i<x/2+1:
			if x % i == 0 and y % i == 0:
				return False
			else:
				i = i+1
	elif x < y:
		while i<y/2+1:
			if x % i == 0 and y % i == 0:
				return False
			else:
				i = i+1
	else:
		return False
		
	return True
	

def get_primes():
	yield 2
	i = 3
	while True:
		counter = 2
		while counter < i/2+1:
			if not gcd(counter,i):
				i = i+1
				counter = 2
			else:
				counter = counter + 1
		i = i+1
		yield i-1
	
	
def public_rsa(pn, pm):
	n = pn * pm
	ojler = (pn-1)*(pm-1)
	e = 1
	while e < ojler:
		if gcd(e, ojler):
			break
		else:
			e = e+1
	
	return (n, e, ojler)
	
def private_rsa(ojler,k,n,e):
	return (k*ojler+1)/e
	
if __name__ == '__main__':
	
	if len(sys.argv) != 2:
		print("Nisu navedeni argumenti komandne linije kako treba")
		exit()
	path = sys.argv[1]
	
	try:
		with open(path, "r") as f:
			konfiguracija = json.load(f)
	except IOError:
		print("Otvaranje datoteke nije uspelo!")
		sys.exit()
	
	m = konfiguracija['m']
	n = konfiguracija['n']
	k = konfiguracija['k']
	swap = 0
	
	if m > n:
		pom = m
		m = n
		n = pom
		swap = 1
	# uvek vazi m<=n
	pn = 0
	pm = 0
	i = 0
	generator = get_primes()
	
	while i < m:
		pm = generator.__next__()
		i = i+1
		
	if n == m:
		pn = pm
	else:
		while i < n:
			pn = generator.__next__()
			i = i+1
	
	if swap and n != m:
		pom = pm
		pm = pn
		pn = pom
	
	(n, e, ojler) = public_rsa(pn, pm)
	
	print(round(private_rsa(ojler, k, n, e),2))
