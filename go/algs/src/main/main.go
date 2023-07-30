package main 

import(
  "fmt"
  "algs/lib/sort"
  "algs/util"
)

func main() {
  arr := rand_arr.Rand_Arr(10)
  fmt.Println(arr);
  sort.Bubble(arr);
  fmt.Println(arr);

  arr = rand_arr.Rand_Arr(10)
  fmt.Println(arr);
  sort.Insertion(arr);
  fmt.Println(arr);

  arr = rand_arr.Rand_Arr(10)
  fmt.Println(arr);
  sort.Selection(arr);
  fmt.Println(arr);
  
  arr = rand_arr.Rand_Arr(10)
  fmt.Println(arr);
  sort.Merge(arr, 0, len(arr)-1);
  fmt.Println(arr);
}
