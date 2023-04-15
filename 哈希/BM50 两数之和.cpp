// ------------------------- ��ϣ ------------------------------------ 
class Solution {
public:
    /**
     * 
     * @param numbers int����vector 
     * @param target int���� 
     * @return int����vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // map ����ʱ���� O(logn)��unordered_map ����ʱ���� O(1) 
        unordered_map<int, int> hash_map;   // numbers[i], i 
        for (int i = 0; i < numbers.size(); i++) {
        	// if (!hash_map[target - numbers[i]]) ��û�ҵ����ҵ�����Ϊ 0 �������
            if (hash_map.find(target - numbers[i]) == hash_map.end())
                hash_map[numbers[i]] = i;
            else
                return {hash_map[target - numbers[i]] + 1, i + 1};
        }
        return {};
    }
};
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n) 
