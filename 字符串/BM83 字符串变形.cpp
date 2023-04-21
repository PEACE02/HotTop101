// ------------------ 双逆转 -------------------------- 
class Solution {
public:
    string trans(string s, int n) {
        // 大小写反转---------------
        for (char& ch : s) 
            if ('a' <= ch && ch <= 'z')
                ch = ch - 'a' + 'A';
            else if ('A' <= ch && ch <= 'Z')
                ch = ch - 'A' + 'a';
            // else ch = ch;    // 空格
        // 整个字符串反转-----------
        reverse(s.begin(), s.end());
        // 按空格单词反转 ----------
        for (int i = 0, j = 0; i < n; i = ++j) {
            while (j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
        }
        return s;
    }
};
// 时间复杂度 O(n)，reverse() 的时间复杂度为 O(n) 
// 空间复杂度 O(1)，reverse() 的空间复杂度为 O(1)

// ---------------- 分割字符串 + 栈 -------------------
class Solution {
public:
    string trans(string s, int n) {
        // 大小写反转
        for (char& ch : s)
            if ('a' <= ch && ch <= 'z')
                ch = ch - 'a' + 'A';
            else if ('A' <= ch && ch <= 'Z')
                ch = ch - 'A' + 'a';
        stack<string> st;
        for (int i = 0, j = 0; i < n; i = ++j) {
            while (j < n && s[j] != ' ') j++;
            st.push(s.substr(i, j - i));
        }
        // 特殊处理结尾有空格的情况 // "h i ",4
        s = s[n - 1] == ' ' ? " " : "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
            if (!st.empty())
                s += " ";
        }
        return s;
    }
};
// 时间复杂度 O(n)
// 空间复杂度 O(n)，stack 最坏情况为 O(n) 
