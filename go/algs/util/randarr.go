package randarr

import(
  "math/rand"
  "time"
)

func RandArr(size int)[]int {
  rand.Seed(time.Now().Unix())
  return rand.Perm(size)
}
