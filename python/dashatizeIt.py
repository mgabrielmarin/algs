# put '-' before and after each odd number.
# don't put '-' at the start and end of string

def dashatize(nr):
  res = ""
  if nr is None:
    return "None"
  list_nr = [int(x) for x in str(nr)] 
  for i in list_nr:
    if i % 2 != 0:
      res = res + "-" + str(i) + "-"
    else: 
      res = res + str(i)
  res = res.replace("--", "-")
  if(res[-1] == "-"):
    res = res[:-1]
  if(res[0] == "-"):
    res = res[1:]
  print(res)


dashatize(5311)
