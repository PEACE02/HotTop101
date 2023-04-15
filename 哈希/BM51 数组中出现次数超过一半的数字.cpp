// ---------------------- 哈希 --------------------------- 
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int half_size = numbers.size() / 2;
        unordered_map<int, int> hashmap;
        for (const int number : numbers)
            if (++hashmap[number] > half_size)
                return number; 
        return -1;
    }
};
// 时间复杂度 O(n)，空间复杂度 O(n)

// -------------------- 排序 ----------------------------- 
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        // 如果没有数据保证需要再检验 
        return numbers[numbers.size() / 2];
    }
};
// 时间复杂度 O(nlogn)，空间复杂度 O(1)

// ------------------- 候选 -----------------------------
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int cond = numbers[0], cnt = 1;
        for (int i = 1; i < numbers.size(); i++) {
            if (cnt) {
                if (cond == numbers[i]) cnt++;
                else cnt--;
            } else {
                cond = numbers[i];
                cnt = 1;
            }
        }
        // 如果没有数据保证需要再检验
        return cond;
    }
};
// 时间复杂度 O(nlogn)，空间复杂度 O(1)
