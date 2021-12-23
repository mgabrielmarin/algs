function palindrome(str) {
  console.log(str.replace(/[^a-zA-Z]/g, ""))
  res = str.toLowerCase().replace(/[^a-zA-Z]/g, "");
  rev = res.split("").reverse().join("");
  console.log(res);
  console.log(rev);
  if (res === rev)
    return true;
  return false;

}


console.log(palindrome("1 eye for of 1 eye"));
