// --------------�������� C �鲢 --------------------
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (!n) return;
        vector<int> C(m + n, 0);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
            C[k++] = A[i] < B[j] ? A[i++] : B[j++];
        while (i < m)
            C[k++] = A[i++];
        while (j < n)
            C[k++] = B[j++];
        for (k = 0; k < m + n; k++)
            A[k] = C[k];
    }
};
// ʱ�临�Ӷ� O(m + n)������ 2(m + n) 
// �ռ临�Ӷ� O(m + n)������ C �Ƕ��⸨���ռ� 

// ------------ ԭ���� A �鲢 ----------------------
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (!n) return;
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (~i && ~j)    // i != -1 && j != -1
            A[k--] = A[i] > B[j] ? A[i--] : B[j--];
        while (~j)          // ���� B ��ʣ��
            A[k--] = B[j--];
        // ���� A ��ʣ��Ͳ��ù��ˣ���Ϊ�������� A �Ļ����ϲ���
    }
}; 
// ʱ�临�Ӷ� O(m + n)������ m + n
// �ռ临�Ӷ� O(1)�������� A �ϲ�����ֻ���������±�ָ�룬Ϊ O(1) 
