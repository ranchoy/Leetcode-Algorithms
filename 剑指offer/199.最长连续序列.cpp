class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_val = 0;
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }

        while(!st.empty()) {
            int val = *st.begin();
            st.erase(val);

            int left = val - 1;
            while(st.find(left) != st.end()) {
                st.erase(left);
                left--;
            }

            int right = val + 1;
            while(st.find(right) != st.end()) {
                st.erase(right);
                right++;
            }
            left++; right--;
            max_val = max(max_val, right-left+1);
        }
        return max_val;
    }
};

/*
100 4 200 1 3 2
4
0 3 7 2 5 8 4 6 0 1
9
*/
