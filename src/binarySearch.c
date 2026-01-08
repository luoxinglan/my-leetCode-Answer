//
// Created by heihuhu on 26-1-6.
//

#include <stdlib.h>

/**
 * 34在排序数组中查找元素的第一个和最后一个位置。折半查找。
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 * @param nums 数组
 * @param numsSize 数组大小
 * @param target 目标
 * @param returnSize 返回的数组大小
 * @return 返回一个长度为二的数组，首位置和末位置
 */
int *searchRange34(int *nums, int numsSize, int target, int *returnSize) {
    int left = 0, right = numsSize - 1;
    int mid = 0;
    int flag = 0; //是否找到。
    *returnSize = 2;
    int *res = malloc(sizeof(int) * (*returnSize));
    //找首次出现的位置。5,7,7,8,8,10
    //1, 2, 3, 9, 10, 11
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] >= target) {
            if (nums[mid] == target) {
                flag = 1;
            }
            right = mid - 1;
        }
    }
    if (flag) {
        res[0] = left; //首次出现的位置。
    } else {
        res[0] = -1;
        res[1] = -1;
        return res;
    }
    left = 0, right = numsSize - 1;
    while (left <= right) {
        //5,7,7,8,8,10
        mid = (left + right) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            if (nums[mid] == target) {
                flag = 1;
            }
            right = mid - 1;
        }
    }
    res[1] = right; //最后一次出现的位置。
    return res;
}

/**
 * 162寻找峰值。
 * 峰值元素是指其值严格大于左右相邻值的元素。
 * 给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
 * @param nums 数组大小
 * @param numsSize 数组大小
 * @return 峰值下标
 */
int findPeakElement162(int *nums, int numsSize) {
    int left = 0; //峰值左边的
    int right = numsSize - 1; //峰值右边的
    int mid = 0;
    while (left < right) {
        //9,7,3,7,8
        mid = (left + right) / 2;
        if (mid + 1 < numsSize) {
            if (nums[mid] < nums[mid + 1]) {
                //峰值在右边，上坡
                left = mid + 1;
            } else if (nums[mid] > nums[mid + 1]) {
                //峰值不在右边
                if (mid - 1 >= 0 && nums[mid] > nums[mid - 1] || mid == 0 && nums[mid] > 0x80000000) {
                    //这个是峰值
                    return mid;
                }
                //不是峰值就下坡。
                right = mid - 1;
            }
        } else if (nums[mid] > 0x80000000) {
            //在最右边
            if (mid - 1 > 0 && nums[mid] > nums[mid - 1]) {
                //是峰值
                return mid;
            }
            //不是峰值，往左。
            right = mid - 1;
        } else {
            return 0;
        }
    }
    return left;
}


/**
 * 153寻找旋转排序数组中的最小值。
 * @param nums 数组
 * @param numsSize 数组大小
 * @return 最小值
 */
int findMin153(int *nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    int mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] < nums[numsSize - 1]) {
            //mid大于两头的，那么最小值在mid右边
            if (mid == 0 && nums[mid] < nums[mid + 1]) {
                //在最左边的时候。
                return nums[mid];
            }
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            right = mid - 1;
        } else if (nums[mid] > nums[numsSize - 1]) {
            //mid小于两头的，那么最小值在mid左边
            left = mid + 1;
        }
    }
    return nums[left];
}

//太难了，我根本没搞懂是怎么回事，cnmd
/**
 * 33搜索旋转排序数组。
 * @param nums 数组
 * @param numsSize 数组大小
 * @param target 查找目标
 * @return 下标
 */
int search33(int *nums, int numsSize, int target) {
    int left = -1, right = numsSize - 1; //可能是0号，但不可能是n-1号
    int mid = 0; //中间下标
    int Middle = 0; //中间的数
    int last = nums[numsSize - 1]; //最后一个数
    while (left + 1 < right) {
        mid = left + (right - left) / 2;
        Middle = nums[mid];
        if (Middle <= last && target > last) {
            //targe在左边的有序的那一段,Middle在右边那一段。下一步只需要二分查找左边的有序部分。
            right = mid;
        } else if (Middle > last && target <= last) {
            //targe在右边的有序那一段,Middle在左边那一段。下一步只需要二分查找右边的有序部分。
            left = mid;
        } else if (Middle >= target) {
            //二者在同一段有序序列中，变成常规二分查找
            right = mid;
        } else {
            //二者在同一段有序序列中，变成常规二分查找
            left = mid;
        }
    }
    return nums[right] == target ? right : -1;
}


