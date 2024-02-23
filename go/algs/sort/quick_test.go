package sort

import (
	"reflect"
	"testing"
)

func TestQuick(t *testing.T) {
	tests := []struct {
		arr  []int
		want []int
	}{
		{[]int{3, 1, 2}, []int{1, 2, 3}},
		{[]int{4, 2, 5}, []int{2, 4, 5}},
	}

	for _, test := range tests {
		got := Quick(test.arr)
        if !reflect.DeepEqual(got, test.want) {
            t.Errorf("Quick(%v), got %v, want %v", test.arr, got, test.want)
        }
	}
}
