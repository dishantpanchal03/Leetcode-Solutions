class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length-1;
        int maxwater = 0, water = 0;
        while(left < right){
            water = Math.min(height[left], height[right]) * (right - left);
            maxwater = Math.max(maxwater, water);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxwater;
    }
}