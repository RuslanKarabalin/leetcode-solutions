package s0018

import "slices"

func fourSum(nums []int, target int) [][]int {
	slices.Sort(nums)
	n := len(nums)
	result := make([][]int, 0)

	for i := range n - 3 {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < n-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}

			m := j + 1
			r := n - 1

			for m < r {
				currSum := nums[i] + nums[j] + nums[m] + nums[r]
				if currSum == target {
					v := []int{nums[i], nums[j], nums[m], nums[r]}
					result = append(result, v)

					for m < r && nums[m] == nums[m+1] {
						m++
					}
					for m < r && nums[r] == nums[r-1] {
						r--
					}
					m++
					r--
				} else if currSum > target {
					r--
				} else {
					m++
				}
			}
		}
	}
	return result
}
