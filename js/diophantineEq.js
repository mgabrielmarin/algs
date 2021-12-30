function soleque(n) {
  let res = [];
  for(let i = 1; i <= Math.sqrt(n); ++i) {
    if(n % i == 0) {
      j = n / i;
      if(((i + j) % 2 == 0) && ((j - i) % 4 == 0)) {
        x = (i + j) / 2;
        y = (j - i) / 4;
        res.push([x,y]);
      }
    }
  }
  return res;
}
