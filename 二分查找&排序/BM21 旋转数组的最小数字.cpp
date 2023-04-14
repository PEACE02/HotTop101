// ---------------- 遍历数组求最小值 ---------------------------------
// ... 
// 时间复杂度 O(n)，空间复杂度 O(1) 

// ---------------- 二分法 ------------------------------------------- 
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (rotateArray[mid] > rotateArray[right]) left = mid + 1;
            else if (rotateArray[mid] == rotateArray[right]) right--;
            else right = mid;
        }
        return rotateArray[left];
    }
};
// 时间复杂度 O(logn)，空间复杂度 O(1) 
// test: [3, 4]、[4, 3]、[1, 1, 0, 1, 1, 1]
