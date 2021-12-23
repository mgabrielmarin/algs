function checkCashRegister(price, cash, cid) {
  var difference = cash - price;
  const originalDiff = difference;
  var objectReturn = {
    status: '',
    change: []
  }
  let arrCurrency = [
    ["ONE HUNDRED", 100],
    ["TWENTY", 20],
    ["TEN", 10],
    ["FIVE", 5],
    ["ONE", 1],
    ["QUARTER", 0.25],
    ["DIME", 0.1],
    ["NICKEL", 0.05],
    ["PENNY", 0.01]
    ];

  cid.reverse();
  var cidSum = 0;
  for(let i = 0; i < cid.length; ++i) {
    cidSum += cid[i][1];
  }
  var result = [...arrCurrency];
  for(let i = 0; i < arrCurrency.length; ++i) {
    let returnMoney = 0;
    let bill = cid[i][1]/arrCurrency[i][1];
    bill.toFixed(2);
    console.log(bill);
    while(difference.toFixed(2)>=arrCurrency[i][1] && bill>=1){
      difference -= arrCurrency[i][1];
      returnMoney += arrCurrency[i][1];
      bill--;
    }
    if(returnMoney>0){
      if(returnMoney - Math.floor(returnMoney) !== 0){
        result[i][1] = returnMoney.toFixed(2)
        result[i][1] = parseFloat(result[i][1])
      } else {
        result[i][1] = returnMoney;
      }
    } else {
      result[i][1] = returnMoney;
    }
  }

}

checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]);
