package main

import (
    "algs/sort"
	"algs/util"
	"fmt"
)

func main() {
  arr := randarr.RandArr(10)
  fmt.Println(arr);
  sort.Bubble(arr);
  fmt.Println(arr);

  arr = randarr.RandArr(10)
  fmt.Println(arr);
  sort.Insertion(arr);
  fmt.Println(arr);

  arr = randarr.RandArr(10)
  fmt.Println(arr);
  sort.Selection(arr);
  fmt.Println(arr);
}
