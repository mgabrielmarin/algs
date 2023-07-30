// Merge sort
package sort

func Merge(arr []int, l, r int) {
    if l < r {
        m := l + (r - l) / 2
        Merge(arr, l, m)
        Merge(arr, m+1, r)

        merge(arr, l, m, r)
    }
}

func merge(arr []int, l, m, r int) {
    lL := m - l + 1
    lR := r - m 

    L := make([]int, lL)
    R := make([]int, lR)
    for i := 0; i < lL; i++ {
        L[i] = arr[l+i]
    }
    for j := 0; j < lR; j++ {
        R[j] = arr[m+j+1]
    }

    var i, j, k = 0, 0, l
    for i < lL && j < lR {
        if L[i] < R[j] {
            arr[k] = L[i]
            i++
        } else {
            arr[k] = R[j]
            j++
        }
        k++
    }
    for i < lL {
        arr[k] = L[i]
        i++
        k++
    }
    for j < lR {
        arr[k] = R[j]
        j++
        k++
    }
}
