class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int r1 = s1.length();
        int r2 = s2.length();
        vector<int> c1(26);
        vector<int> c2(26);
        for(const char c:s1)
            ++c1[c-'a'];
        for(int i=0; i<r2; ++i){
            if(i>=r1)
            --c2[s2[i-r1] - 'a'];
            ++c2[s2[i] - 'a'];
            if(c1 == c2)return true;
        }
        return false;

    }
};