class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        if (strs.length == 1) {
            return strs[0];
        }

        int minLength = Integer.MAX_VALUE;
        for (String str : strs) {
            minLength = Math.min(minLength, str.length());
        }

        for (int i = 0; i < minLength; i++) {
            char currentChar = strs[0].charAt(i);

            for (int j = 1; j < strs.length; j++) {

                if (strs[j].charAt(i) != currentChar) {
                    return strs[0].substring(0, i);
                }
            }
        }

        return strs[0].substring(0, minLength);
    }
}