package s0008

import (
	"math"
)

func myAtoi(s string) int {
	i := 0
	n := len(s)

	for i < n && s[i] == ' ' {
		i++
	}

	sign := 1
	if i < n && (s[i] == '-' || s[i] == '+') {
		if s[i] == '-' {
			sign = -1
		}
		i++
	}

	result := 0
	for i < n && '0' <= s[i] && s[i] <= '9' {
		digit := int(s[i] - '0')

		if result > math.MaxInt32/10 || (result == math.MaxInt32/10 && digit > 7) {
			if sign == 1 {
				return math.MaxInt32
			}
			return math.MinInt32
		}

		result = result*10 + digit
		i++
	}

	return sign * result
}
