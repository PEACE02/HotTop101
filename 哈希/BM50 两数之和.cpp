// ------------------------- 哈希 ------------------------------------ 
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // map 插入时间是 O(logn)，unordered_map 插入时间是 O(1) 
        unordered_map<int, int> hash_map;   // numbers[i], i 
        for (int i = 0; i < numbers.size(); i++) {
        	// if (!hash_map[target - numbers[i]]) 有没找到和找到索引为 0 两种情况
            if (hash_map.find(target - numbers[i]) == hash_map.end())
                hash_map[numbers[i]] = i;
            else
                return {hash_map[target - numbers[i]] + 1, i + 1};
        }
        return {};
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n) 
