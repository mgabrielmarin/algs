def howMuch(m,n):
  # calculate number of cars;
  nr_cars, nr_boats = 9, 7
  c, b = 0, 0

  res = []
  for i in range(m,n+1):
    c = (i - 1) / nr_cars
    b = (i - 2) / nr_boats
    if c % 1 == 0 and b % 1 == 0:
      res.append(["M: {}".format(i), "B: {0}".format(int(b)), "C: {0}".format(int(c))])
  print(res)
      
    

howMuch(1,100)
