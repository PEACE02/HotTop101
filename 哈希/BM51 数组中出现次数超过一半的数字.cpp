// ---------------------- ��ϣ --------------------------- 
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
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)

// -------------------- ���� ----------------------------- 
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        // ���û�����ݱ�֤��Ҫ�ټ��� 
        return numbers[numbers.size() / 2];
    }
};
// ʱ�临�Ӷ� O(nlogn)���ռ临�Ӷ� O(1)

// ------------------- ��ѡ -----------------------------
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
        // ���û�����ݱ�֤��Ҫ�ټ���
        return cond;
    }
};
// ʱ�临�Ӷ� O(nlogn)���ռ临�Ӷ� O(1)
