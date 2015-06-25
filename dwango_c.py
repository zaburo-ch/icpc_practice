C = []
for i in range(101):
  C += [[]]
  for j in range(i+1):
    if 0<j<i:
      C[i] += [C[i-1][j-1]+C[i-1][j]]
    else:
      C[i] += [1]

P = [0.]*101

for n in range(2,101):
  pa = 0.
  pb = 0.
  for a in range(n+1):
    for b in range(n+1):
      c = n-a-b
      if c>=0:
        x,y,z = sorted([a,b,c])
        while x==0:
          x,y,z = y,z,0

        p = C[n][x]*C[n-x][y]/3.**n

        if x==n:
          pa += p
        else:
          if x<y or (x==y and (y<z or z==0)):
            pb += (P[x]+1.) * p
          else:
            pa += p

  P[n] = (pa+pb) / (1-pa)

"""
for p in P:
  print "%.10f"%
"""