def pigIt(string):
  # "This is a string" => "hisTay siay aay tringsay"
  res = ""
  words = []
  words = string.split(" ")
  for word in words:
    if word.isalpha():
      temp = word[1:] + word[0] + "ay" + " "
      res += temp
    else:
      res += (word + " ")

  print(res)
  return res 

string = "This is a string"
pigIt(string)
