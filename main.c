#include <stdio.h>
#include <stdlib.h>

#include "include/doublePointer.h"
#include "include/slidingWindow.h"

void print2(int **nums, int numsSize, int *colsize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < colsize[i]; j++) {
            printf("%3d ", nums[i][j]);
        }
        printf("\n");
    }
}

void doublePointer() {
    // int numbers1[] = {2, 7, 11, 15};
    // int numberSize1 = 4;
    // int returnSize1 = 0;
    // int *res1 = twoSum167(numbers1, numberSize1, 13, &returnSize1);
    int numbers2[] = {-100, -70, -60, 110, 120, 130, 160};
    int numberSize2 = 7;
    int returnSize2 = 0;
    int *retunrCulomSizes2 = NULL;
    int **res2 = threeSum15(numbers2, numberSize2, &returnSize2, &retunrCulomSizes2);
    print2(res2, returnSize2, retunrCulomSizes2);
}

void slidingwindow() {
    int nums1[] = {2, 3, 1, 2, 4, 3};
    int numsSize1 = 6;
    int res1 = minSubArrayLen209(7, nums1, numsSize1);
    int nums2[] = {10, 5, 2, 6};
    int numsSize2 = 4;
    int res2 = numSubarrayProductLessThanK713(nums2, numsSize2, 100);
    char s[] = "abcabcbb";
    int res3 = lengthOfLongestSubstring3(s);
}

int main(void) {
    slidingwindow();
    return 0;
}
