import math

def gcd(a,b):
  a if b == 0 else gcd(a%b, a)

def decompose(n):
  result = []
  iter = 0
  unit_den_array = [0]*10

  if (n.find("/") == 1):
    s = [int(s) for s in n.split("/")]
    num = int(s[0])
    den = int(s[1])

  def greedy_egyptian_fraction(num, den):
    if (num == 1):
      iter = iter+1
      unit_den_array[iter] = den
    else:
      unit_den = math.ceil(den/num)
      iter = iter+1
      unit_den_array[iter] = unit_den
      gcd_of_nr = gcd((num*unit_den) - den, den*unit_den)
      greedy_egyptian_fraction(((num*unit_den)-den)//gcd_nr, (den*unit_den)//gcd_nr)
  for i in unit_den_array:
    result.append("1/" + str(i))
  return result

print(decompose('0'))
