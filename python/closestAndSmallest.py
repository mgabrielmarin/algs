# [number-weight, index in strng of number, original coresp number]
strng = "103 123 444 99 2000"
#strng = "456899 50 11992 176 272293 163 389128 96 290193 85 52"

def findMinDiffIndexes(arr, n):
  res = []
  diff = 10 ** 20

  # Find the min diff by comparing difference
  # of all the possible paris in a given array
  for i in range(n-1):
    for j in range(i+1, n):
      #if abs(arr[i]-arr[j]) < diff:
      diff = abs(arr[i]-arr[j])
      idx_dif = abs(i - j)
      res.append([i, j, abs(arr[i]+arr[j]), abs(arr[i]-arr[j])]) 
  return res

def closest(strng):
  weights, minDifIdx, res = [], [], []
  first_nr, second_nr = [], []
  strng_list = strng.split()
  map_object = map(int, strng_list)
  strng_list_int = list(map_object)
  # calculate weights 
  for number in strng_list_int:
    weigth = sum(int(digit) for digit in str(number))
    weights.append(weigth)
  # find the indexes of min dif from weights
  minDifIdx = findMinDiffIndexes(weights, len(weights))
  minDifIdx.sort(key=lambda x: x[3])
  lower_dif = minDifIdx[0][3]
  minDifIdxLow = []
  for i in range(len(minDifIdx)):
    if minDifIdx[i][3] == lower_dif:
      minDifIdxLow.append(minDifIdx[i])
  minDifIdxLow.sort(key=lambda x: x[2])
  first_idx = minDifIdxLow[0][0]
  sec_idx = minDifIdxLow[0][1]
  first_nr = [weights[first_idx], first_idx, strng_list_int[first_idx]]
  second_nr = [weights[sec_idx], sec_idx , strng_list_int[sec_idx]]
  res = [first_nr, second_nr]
  print(res)
  return res

closest(strng)

