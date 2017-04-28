
#n = 20




for n in range(20,101, 10):
	ar = [1] * n
	ear = []
	max_es = 0
	for j in range(0,n+1,2):
		flips = 0
		e = 0
		for i in range(0,n-2):
			if(ar[i] * ar[i+1]) == -1:
				flips = flips + 1
		if(ar[0] * ar[n-1]) == -1:
			flips = flips + 1
	
		for i in range(0,n-1):
			e_temp = ar[i] * ar[i+1]
			e += e_temp
		e += ar[0] * ar[n-1]
		#print("***************")
		#print(ar)
		print("#flips: " + str(flips))
		#print("#Energy: " + str(e))
	
		if(e not in ear):
			ear.append(e)
		#print("Number of e's: " + str(len(ear)))
		
	
		if(j < n):
			ar[j] = -1
	print("N: " + str(n) + " e's: " + str(len(ear)))



