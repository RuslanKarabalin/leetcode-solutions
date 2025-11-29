package s0017

import "strings"

func mVecs(a, b []string) []string {
	result := make([]string, 0)
	for _, oc := range a {
		for _, ic := range b {
			sb := strings.Builder{}
			sb.WriteString(oc)
			sb.WriteString(ic)
			result = append(result, sb.String())
		}
	}
	return result
}

func letterCombinations(digits string) []string {
	m := map[string][]string {
		"2": { "a", "b", "c" },
		"3": { "d", "e", "f" },
		"4": { "g", "h", "i" },
		"5": { "j", "k", "l" },
		"6": { "m", "n", "o" },
		"7": { "p", "q", "r", "s" },
		"8": { "t", "u", "v" },
		"9": { "w", "x", "y", "z" },
	}

	result := make([]string, 0)
	l := len(digits)

	c := m[string(digits[0])]
	result = append(result, c...)
	for i := 1; i < l; i++ {
		c := m[string(digits[i])]
		result = mVecs(result, c)
	}
	return result
}
