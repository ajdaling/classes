import csv

with open('capitals.csv','wb') as s:
	o = csv.writer(s)
	with open('caps.csv','rb') as f:
		r = csv.reader(f)
		for row in r:
			if row[1] != "N/A":
				o.writerow([row[0]])
				o.writerow([row[1]])
