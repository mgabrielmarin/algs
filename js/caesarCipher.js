function rot13(str) {
  str = str.toUpperCase();
  return str.replace(/[A-Z]/g, rot13char);

  function rot13char(correspondence) {
    const charCode = correspondence.charCodeAt();
    return String.fromCharCode(
      ((charCode + 13) <= 90) ? charCode + 13
                              : (charCode + 13) % 90 + 64
                              );
  }
}

console.log(rot13("SERR PBQR PNZC"));
