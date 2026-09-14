class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        
        for (int num : nums1) {
            freq[num]++;
        }

        vector<int> result;

        for (int num : nums2) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};