package s0016

import (
	"math"
	"slices"
)

func threeSumClosest(nums []int, target int) int {
	slices.Sort(nums)

	bestSum := nums[0] + nums[1] + nums[2]
	n := len(nums)

	for i := 0; i < n-2; i++ {
		m := i + 1
		r := n - 1

		for m < r {
			currSum := nums[i] + nums[m] + nums[r]

			if math.Abs(float64(currSum-target)) < math.Abs(float64(bestSum-target)) {
				bestSum = currSum
			}

			if currSum < target {
				m++
			} else if currSum > target {
				r--
			} else {
				return currSum
			}
		}
	}
	return bestSum
}
