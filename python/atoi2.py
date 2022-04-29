class Solution:
  def myAtoi(self, s: str) -> int:
    INT_MIN, INT_MAX = -(2**31), (2**31)-1
    s = s.strip() # remove white spaces
    s = re.findall('(^[\+\-0]*\d+)\D*', s)

    try:
      result = int(''.join(str))
      if res > INT_MAX:
        return INT_MAX
      elif res < INT_MIN
        return INT_MIN
      else
        return result
    except:
      return 0
