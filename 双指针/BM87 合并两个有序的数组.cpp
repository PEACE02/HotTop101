// --------------辅助数组 C 归并 --------------------
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
// 时间复杂度 O(m + n)，遍历 2(m + n) 
// 空间复杂度 O(m + n)，数组 C 是额外辅助空间 

// ------------ 原数组 A 归并 ----------------------
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (!n) return;
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (~i && ~j)    // i != -1 && j != -1
            A[k--] = A[i] > B[j] ? A[i--] : B[j--];
        while (~j)          // 数组 B 有剩余
            A[k--] = B[j--];
        // 数组 A 有剩余就不用管了，因为本来就在 A 的基础上操作
    }
}; 
// 时间复杂度 O(m + n)，遍历 m + n
// 空间复杂度 O(1)，在数组 A 上操作，只用了三个下标指针，为 O(1) 
