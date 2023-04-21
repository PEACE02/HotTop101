// ----------------------------------- ����ɨ�裨����-------------------------------------- 
class Solution {
public:
    /**
     * 
     * @param strs string�ַ���vector 
     * @return string�ַ���
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return {};
        int len = 0, flag = 1;
        while (flag) {
            for (string str : strs) {
                if (len == min(str.size(), strs[0].size()) || str[len] != strs[0][len]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) len++;
        }
        return strs[0].substr(0, len);
    }
};
// ʱ�临�Ӷ� O(len*n)���ռ临�Ӷ� O(1) 
