//
// Created by Zeno on 2020/5/7.
//

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 思路：因为任何一个数异或自己都等于0，所以将数组的所有元素相互异或，出现两次的元素都将被异或抵消掉，最后的结果就是只出现一次的两个元素异或的结果
        // 将数组分成两个部分，每个部分有一个只出现一次的元素，再对这两个数组进行元素的异或，就能分别得出两个只出现一次的元素
        // 在第一步中得到结果的二进制表示必然有一位为1（表示两个元素在该位的值不同），就可以通过这一位是否为1将数组中的元素分成两个部分，只出现一次的两个元素必然被分到不同的部分中
        vector<int> res;
        if (nums.size() < 2) {
            return res;
        }

        int resultExclusiveOR = 0;
        for (int i = 0; i < nums.size(); i++) {
            resultExclusiveOR ^= nums[i];
        }

        int indexOf1 = findFirstBitIs1(resultExclusiveOR);
        int num1 = 0, num2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (isBit1(nums[i], indexOf1)) {
                num1 ^= nums[i];
            } else {
                num2 ^= nums[i];
            }
        }
        res.push_back(num1);
        res.push_back(num2);
        return res;
    }

    // 找到num的二进制表示中从右往左数出现的第一个1
    int findFirstBitIs1(int num) {
        int indexBit = 0;
        while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
            num = num >> 1;
            ++indexBit;
        }

        return indexBit;
    }
    bool isBit1(int num, int indexBit) {
        num = num >> indexBit;
        return num & 1;
    }
};