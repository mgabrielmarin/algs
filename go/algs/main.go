package main 

import(
  "fmt"
  "algs/sorting/bubble_sort"
  "algs/sorting/insertion_sort"
  "algs/util"
)

func main() {
  arr := rand_arr.Rand_Arr(10)
  fmt.Println(arr);
  bubble.Sort(arr);
  fmt.Println(arr);

  arr = rand_arr.Rand_Arr(10)
  fmt.Println(arr);
  insertion.Sort(arr);
  fmt.Println(arr);
}
