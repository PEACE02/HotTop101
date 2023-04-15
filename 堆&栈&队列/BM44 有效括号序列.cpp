// ------------------- ջ --------------------------------
class Solution {
public:
    /**
     * 
     * @param s string�ַ��� 
     * @return bool������
     */
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            switch (ch) {
                case '(': st.push(')'); break;
                case '[': st.push(']'); break;
                case '{': st.push('}'); break;
                default:    // ������
                    if (st.empty()) return false;
                    else if (ch == st.top()) st.pop();
            }
        }
        return st.empty();
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)
