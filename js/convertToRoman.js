function convertToRoman(num) {
  let nums = [1,4,5,9,10,40,50,90,100,400,500,900,1000];
  let syms = ["I","IV","V","IX","X","XL","L","LC","C","CD","D","DM","M"];
  let i = 12;
  let res = "";
  while(num > 0) {
    let div = Math.floor(num/nums[i]);
    num = num%nums[i];
    while(div--) {
      res += syms[i];
    }
    i--;
  }
  return res;
}

convertToRoman(36);
