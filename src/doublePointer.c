//
// Created by heihuhu on 26-1-2.
//


#include <stdlib.h>
/**
 * 167在一组有序数字中找到两个之和为目标数值的数。
 * Note: The returned array must be malloced, assume caller calls free().
 * @param numbers 数组
 * @param numbersSize 数组大小
 * @param target 整数目标数值
 * @param returnSize 返回数组大小
 * @return 返回一个数组，是两个下标
 */
int *twoSum167(int *numbers, int numbersSize, int target, int *returnSize) {
    int left = 0, right = numbersSize - 1;
    int *res = malloc(sizeof(int) * 2);
    res[0] = -1;
    res[1] = -1;
    *returnSize = 2;
    while (left <= right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            res[0] = 1 + left;
            res[1] = 1 + right;
            break;
        }
        if (sum < target) {
            left++;
        } else if (sum > target) {
            right--;
        }
    }
    return res;
}

/**
 * 用于快速排序。
 * @param a 左边的
 * @param b 右边的
 * @return 左大于右返回正数
 */
int cmpInt(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

/**
 * 15三数之和为零。固定一个数，另外两个变成两数之和。
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * @param nums 无序数组
 * @param numsSize 数组大小
 * @param returnSize 返回数组的大小
 * @param returnColumnSizes 返回数组的列数，是一个一维数组
 * @return 返回的指针
 */
int **threeSum15(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int **res = malloc(numsSize * numsSize * sizeof(int *));
    *returnColumnSizes = malloc(numsSize * numsSize * sizeof(int));
    int count = 0;

    qsort(nums, numsSize, sizeof(int), (int (*)(const void *, const void *)) cmpInt); //首先进行排序，顺序不重要。
    //-4,-1,-1,0,1,2
    //[-100,-70,-60,110,120,130,160]
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            //跳过重复数字。
            continue;
        }
        if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
            //太大了，没有别的答案了，结束。
            break;
        }
        if (nums[i] + nums[numsSize - 2] + nums[numsSize - 1] < 0) {
            //太小了，下一个。
            continue;
        }
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                //添加三元组到答案中
                int *tuple = malloc(3 * sizeof(int));
                tuple[0] = nums[i];
                tuple[1] = nums[j];
                tuple[2] = nums[k];
                res[count] = tuple;
                (*returnColumnSizes)[count++] = 3;
                //找到了，接下来跳过重复数字
                for (j++; j < k && nums[j] == nums[j - 1]; j++) {
                }
                for (k--; j < k && nums[k] == nums[k + 1]; k--) {
                }
            } else if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            }
        }
    }
    *returnSize = count;
    return res;
}

/**
 * 11盛最多水的容器。
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 返回容器可以储存的最大水量。
 * @param height 柱子的高度
 * @param heightSize 柱子的数量
 * @return 最大的容量
 */
int maxArea11(int *height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int h0 = height[left] < height[right] ? height[left] : height[right]; //是两端柱子的最小高度。
    int res = h0 * (right - left); //初始容量。
    while (left < right) {
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
        int h1 = height[left] < height[right] ? height[left] : height[right]; //是两个柱子的新的最小高度。
        if (h1 * (right - left) > res) {
            res = h1 * (right - left);
        }
    }
    return res;
}

/**
 * 42接雨水。
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * @param height 柱子的高度
 * @param heightSize 柱子的数量
 * @return 一共可以接多少雨水
 */
int trap42(int *height, int heightSize) {
    int res = 0;
    int left = 0, right = heightSize - 1;
    int leftMax = 0; //左边木板最大值。
    int rightMax = 0; //右边木板最大值。
    while (left < right) {
        leftMax = leftMax > height[left] ? leftMax : height[left]; //向右拓展，如果新来的这一个格子是更高的，那么更新左最大高。
        rightMax = rightMax > height[right] ? rightMax : height[right]; //向左拓展，如果新来的这一个格子是更高的，那么更新右最大高。
        if (leftMax < rightMax) {
            //如果左边的最大值小于右边的最大值，那么这一个格子装leftMax的水。
            res += leftMax - height[left];
            left++; //移动指针。
        } else {
            //如果右边的最大值小于左边的最大值，那么这一个格子装rightMax的水。
            res += rightMax - height[right];
            right--; //移动指针。
        }
    }
    return res;
}
