// ------------------ ˫��ת -------------------------- 
class Solution {
public:
    string trans(string s, int n) {
        // ��Сд��ת---------------
        for (char& ch : s) 
            if ('a' <= ch && ch <= 'z')
                ch = ch - 'a' + 'A';
            else if ('A' <= ch && ch <= 'Z')
                ch = ch - 'A' + 'a';
            // else ch = ch;    // �ո�
        // �����ַ�����ת-----------
        reverse(s.begin(), s.end());
        // ���ո񵥴ʷ�ת ----------
        for (int i = 0, j = 0; i < n; i = ++j) {
            while (j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
        }
        return s;
    }
};
// ʱ�临�Ӷ� O(n)��reverse() ��ʱ�临�Ӷ�Ϊ O(n) 
// �ռ临�Ӷ� O(1)��reverse() �Ŀռ临�Ӷ�Ϊ O(1)

// ---------------- �ָ��ַ��� + ջ -------------------
class Solution {
public:
    string trans(string s, int n) {
        // ��Сд��ת
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
        // ���⴦���β�пո����� // "h i ",4
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
// ʱ�临�Ӷ� O(n)
// �ռ临�Ӷ� O(n)��stack ����Ϊ O(n) 
