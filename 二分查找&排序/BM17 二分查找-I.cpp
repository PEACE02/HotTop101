// ----------------------------- ���ַ� ���� --------------------------------- 
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * 
     * @param nums int����vector 
     * @param target int���� 
     * @return int����
     */
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return - 1;
    }
};
// ʱ�临�Ӷ� O(logn) ���ռ临�Ӷ� O(1)

