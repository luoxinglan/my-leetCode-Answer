//
// Created by heihuhu on 26-1-5.
//

#include <string.h>
/**
 * 209长度最小的子数组。
 * 找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
 * 并返回其长度。如果不存在符合条件的子数组，返回 0 。
 * @param target 目标
 * @param nums 数组
 * @param numsSize 数组大小
 * @return 最小数连续子串长度
 */
int minSubArrayLen209(int target, int *nums, int numsSize) {
    int l = 0, r = 0;
    int key = 0; //标记是否存在。
    int sum = nums[0]; //连续子串之和。
    int minLen = 0x7fffffff; //最小长度。
    while (r < numsSize) {
        if (sum < target) {
            //和小于目标，窗口右边向右扩展。
            if (r >= numsSize - 1) {
                break;
            }
            sum += nums[++r];
        } else {
            //和大于等于目标，窗口左边向右缩小。
            key = 1;
            minLen = minLen < r - l + 1 ? minLen : r - l + 1;
            sum -= nums[l++];
        }
    }
    if (key == 0) {
        return 0;
    }
    return minLen;
}

/**
 * 713乘积小于 K 的子数组。
 * 给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 * @param nums 数组
 * @param numsSize 数组大小
 * @param k 目标值
 * @return 连续子数组长度
 */
int numSubarrayProductLessThanK713(int *nums, int numsSize, int k) {
    int l = 0, r = 0;
    int product = nums[0]; //初始的积。
    int res = 0; //字串数量。
    if (k <= 1) {
        return 0;
    }
    while (r < numsSize) {
        if (product < k) {
            //乘积小于目标。窗口右边边向右扩大。
            res += r - l + 1;
            if (r >= numsSize - 1) {
                break;
            }
            product *= nums[++r];
        } else {
            //乘机大于目标。
            product /= nums[l++];
        }
    }
    return res;
}

/**
 * 3无重复字符的最长子串。
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
 * 使用哈希表记录字符出现的次数。
 * @param s 字符串
 * @return 最长无重复字符串长度
 */
int lengthOfLongestSubstring3(char *s) {
    int count[256] = {0}; //字符型常量一个字节，8bit
    int res = 0;
    int l = 0, r = 0;
    int len = strlen(s);
    while (r < len) {
        if (count[s[r]] == 0) {
            //新加进来的字符没有出现过，于是更新长度、count。
            res = res > r - l + 1 ? res : r - l + 1;
            count[s[r]]++;
            r++;
        } else {
            //新加进来的字符出现过，左边的全部不行了。将左指针向右移动，且把count归零。
            if (count[s[l]] > 0) {
                count[s[l]]--;
            }
            l++;
        }
    }
    return res;
}
