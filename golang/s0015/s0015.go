package s0015

import (
	"slices"
)

func threeSum(nums []int) [][]int {
	slices.Sort(nums)	
	n := len(nums)
	result := make([][]int, 0)

    for i := range (n - 2) {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		m := i + 1
		r := n - 1

        for m < r {
			currSum := nums[i] + nums[m] + nums[r]
            if currSum == 0 {
				v := []int{nums[i], nums[m], nums[r]}
				result = append(result, v)

				for m < r && nums[m] == nums[m+1] {
					m++
				}
				for m < r && nums[r] == nums[r-1] {
					r--
				}
				m++
				r--
            } else if currSum > 0 {
				r--;
			} else {
				m++;
			}
        }
    }
	return result
}
