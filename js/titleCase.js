function capitalize(word) {
  return word.charAt(0).toUpperCase() + word.slice(1).toLowerCase();
}


function titleCase(title, minorWords) {
  var res = "";
  title.split(' ').forEach(function(value, index, array) {
    if(!minorWords.includes(value) || index == 0) {
      array[index] = capitalize(array[index]);
    }
    console.log(array[index]);
    res = array.join(' ');
  });
  console.log(res);
  return res;
}

titleCase('a clash of KINGS', 'a an the of')
