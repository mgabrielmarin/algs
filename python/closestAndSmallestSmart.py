strng = "456899 50 11992 176 272293 163 389128 96 290193 85 52"

def closest(s):
  lst = sorted([sum(map(int, n)), i, int(n)] for i, n in enumerate(s.split()))
  return min(map(list,zip(lst, lst[1:])), key=lambda p:abs(p[0][0] - p[1][0]), default=[])

closest(strng)
