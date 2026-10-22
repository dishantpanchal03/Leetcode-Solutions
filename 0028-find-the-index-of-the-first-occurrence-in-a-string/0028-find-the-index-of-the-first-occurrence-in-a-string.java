class Solution {
    public int strStr(String haystack, String needle) {
        int index = haystack.indexOf(needle);
        if(index >= 0){
            return index;
        }
      return -1;  
    }
}