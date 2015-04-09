import subprocess
import time

while True:
	l = []
	proc = subprocess.Popen('./a.out', stdout=subprocess.PIPE)
	output = proc.stdout.read()
	a = output.split('\n')
	foo = [(int(i),float(a)) for (i,a) in
		[line.split(",") for line in a if len(line)>0]]
	
	for f in foo:
		l.append([f[0] * 0.3515625, f[1]])
		
	print l
	time.sleep(1)
