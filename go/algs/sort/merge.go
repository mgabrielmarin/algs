// Merge sort
package sort

func Merge(arr []int) []int {
    if len(arr) < 2 {
        return arr
    }
    l := Merge(arr[:len(arr)/2])
    r := Merge(arr[len(arr)/2:])
    return merge(l, r)
}

func merge(l , r []int) []int {
    var final []int 
    var i, j int
    for i < len(l) && j < len(r) {
        if l[i] < r[j] {
            final = append(final, l[i])
            i++
        } else {
            final = append(final, r[j])
            j++
        }
    }
    for ; i < len(l); i++ {
        final = append(final, l[i])
    }
    for ; j < len(r); j++ {
        final = append(final, r[j])
    }
    return final
}
