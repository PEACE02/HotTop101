// ------------------- Õ» --------------------------------
class Solution {
public:
    /**
     * 
     * @param s string×Ö·û´® 
     * @return bool²¼¶ûÐÍ
     */
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            switch (ch) {
                case '(': st.push(')'); break;
                case '[': st.push(']'); break;
                case '{': st.push('}'); break;
                default:    // ÓÒÀ¨ºÅ
                    if (st.empty()) return false;
                    else if (ch == st.top()) st.pop();
            }
        }
        return st.empty();
    }
};
// Ê±¼ä¸´ÔÓ¶È O(n)£¬¿Õ¼ä¸´ÔÓ¶È O(n)
