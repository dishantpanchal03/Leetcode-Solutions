import java.util.*;

class Solution {

    String[] map = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();

        if (digits.length() == 0) return ans;

        solve(digits, 0, "", ans);
        return ans;
    }

    private void solve(String digits, int index, String str, List<String> ans) {
        if (index == digits.length()) {
            ans.add(str);
            return;
        }

        String letters = map[digits.charAt(index) - '0'];

        for (int i = 0; i < letters.length(); i++) {
            solve(digits, index + 1, str + letters.charAt(i), ans);
        }
    }
}