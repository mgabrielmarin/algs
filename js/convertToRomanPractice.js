function convertToRoman(number) {
  let nums = [1,4,5,9,10,40,50,90,100,400,500,900,1000];
  let syms = ["I","IV","V","IX","X","XL","L","LC","C","CD","D","DM","M"];
  let i = 12;
  let res = ""
  
  while(number) {
    let div = Math.floor(number/nums[i]);
    number = number%nums[i];
    while(div--)
      res += syms[i];
    i--;
  }
  return res;
}

console.log(convertToRoman(3999));
