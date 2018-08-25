class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = s.length();
        int b = 0;
        int pos[256];
        while(b < len - ans){
            int p = b, temp = 0;
            memset(pos, 0, sizeof(pos));
            while(p < len){
                if(pos[s[p]] == 0) {pos[s[p]] = p + 1; p++; temp++; continue;}
                b = pos[s[p]]; break;
            } if(temp > ans) ans = temp;
        }
        return ans;
    }
};
