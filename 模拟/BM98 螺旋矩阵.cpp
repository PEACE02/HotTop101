// ------------------------------------ �߽�ģ�� -------------------------------------- 
#include <vector>
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty()) return {};
        vector<int> res;
        // ��������������ҵı߽�
        int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;
        while (left <= right && up <= down) {
            // ��
            for (int j = left; j <= right; j++)
                res.push_back(matrix[up][j]);
            up++;
            if (up > down) break;       // !!!
            // ��
            for (int i = up; i <= down; i++)
                res.push_back(matrix[i][right]);
            right--;
            if (left > right) break;    // !!!
            // ��
            for (int j = right; j >= left; j--)
                res.push_back(matrix[down][j]);
            down--;
            // ��
            for (int i = down; i >= up; i--)
                res.push_back(matrix[i][left]);
            left++;
        }
        return res;
    }
};
// ʱ�临�Ӷ� O(mn)���൱�ڱ����������� 
// �ռ临�Ӷ� O(1)��res ���ڱ�Ҫ�ռ䣬û���õ����⸨���ռ� 
