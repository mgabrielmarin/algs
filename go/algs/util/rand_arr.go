package rand_arr

import(
  "math/rand"
  "time"
)

func Rand_Arr(size int)[]int {
  rand.Seed(time.Now().Unix())
  return rand.Perm(size)
}
