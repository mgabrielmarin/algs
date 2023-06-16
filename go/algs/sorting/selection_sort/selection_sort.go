package selection

func Sort(arr []int)[]int {
  for i := 0; i < len(arr) - 1; i++ {
    min_idx := i
    for j := i + 1; j < len(arr); j++ {
      if arr[j] < arr[min_idx] {
        min_idx = j
      }
    }
    if min_idx != i {
      arr[i], arr[min_idx] = arr[min_idx], arr[i]
    }
  }
  return arr
}
