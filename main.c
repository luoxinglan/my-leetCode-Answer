#include <complex.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void InitList(ListNode *head) {
    head = (ListNode *) malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
}

void InsertNode(ListNode *node, int val[], int len) {
    ListNode *rear = node;
    for (int i = 0; i < len; i++) {
        ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
        new_node->val = val[i];
        rear->next = new_node;
        rear = new_node;
        rear->next = NULL;
    }
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *rear = head; //尾指针，进行尾插法


    if (list1 == NULL && list2 == NULL) {
        return NULL;
    } else if (list1 == NULL && list2 != NULL) {
        return list2;
    } else if (list1 != NULL && list2 == NULL) {
        return list1;
    } else {
        //合并两个链表。不带头结点
        struct ListNode *h1 = list1;
        struct ListNode *h2 = list2;

        while (h1 != NULL && h2 != NULL) {
            if (h1->val <= h2->val) {
                rear->next = h1;
                list1 = h1->next;
                h1 = list1;
                rear = rear->next;
                rear->next = NULL;
            } else if (h1->val > h2->val) {
                rear->next = h2;
                list2 = h2->next;
                h2 = list2;
                rear = rear->next;
                rear->next = NULL;
            }
        }
        if (h1 != NULL) {
            rear->next = h1;
        }
        if (h2 != NULL) {
            rear->next = h2;
        }
    }
    return head->next;
}

int partition(int *nums, int low, int high);

void quickSort(int *nums, int low, int high);

/**
 * 删除数组重复元素
 * @param nums
 * @param numsSize
 * @return
 */
int removeDuplicates(int *nums, int numsSize) {
    //[0,0,1,1,1,2,2,3,3,4]
    int k = 1; //表示后面剩下的长度
    int i = 0, j = 0; //i是慢指针，j是快指针；相同时j走，不同时先赋值，再一起走；
    for (i = 0, j = 1; j < numsSize;) {
        if (nums[i] == nums[j]) {
            j++;
        } else {
            nums[++i] = nums[j++];
            k++;
        }
    }
    return k;
}

/**
 * //28. 找出字符串中第一个匹配项的下标
 * @param haystack
 * @param needle
 * @return
 */
int strStr(char *haystack, char *needle) {
    //朴素字符串匹配
    int res = 0;
    int i = 0, j = 0;
    for (i = 0, j = 0; haystack[i] != '\0' && needle[j] != '\0';) {
        if (haystack[i] == needle[j]) {
            j++;
            i++;
        } else {
            i = i - j + 1; //往后移动一个
            j = 0;
        }
    }
    if (needle[j] != '\0') {
        res = -1;
    } else if (needle[j] == '\0') {
        //匹配到最后了
        res = i - j;
    }

    return res;
}

/**
 * 转换大小写
 * @param s
 * @return
 */
char *toLowerCase(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            //大写转换为小写
            s[i] = s[i] + 'a' - 'A';
        }
        // else if (s[i] >= 'a' && s[i] <= 'z') {//小写转换为大写
        //     s[i] = s[i] + 'A' - 'a';
        // }
    }
    return s;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * @param numRows
 * @param returnSize
 * @param returnColumnSizes
 * @return
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
    //returnsize 第一维度
    int **res = malloc(sizeof(int *) * numRows); //返回有numRows个指针的指针数组
    *returnSize = numRows; //有numRows行
    *returnColumnSizes = malloc(sizeof(int) * numRows); //指向一个数组，分别是每一行的大小
    for (int i = 0; i < numRows; i++) {
        res[i] = (int *) malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        res[i][0] = 1;
        res[i][i] = 1;
        if (i > 1) {
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
    }
    return res;
}

/**
 * 输出一个菱形图案
 * @param n
 */
void printDiamond(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1 - i; j > 0; j--) {
            printf(" "); //输出空格
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            //输出*
            printf("*");
        }
        printf("\n");
    }
    for (int i = n; i > 0; i--) {
        for (int j = n - i + 1; j > 0; j--) {
            printf(" ");
        }
        for (int j = (i - 1) * 2 - 1; j > 0; j--) {
            printf("*");
        }
        printf("\n");
    }
}

int drinkSoda(int n) {
    //一瓶汽水1元，一瓶汽水得一个空瓶，2个空瓶=一瓶汽水，求最多能喝多少汽水
    if (n < 1) { return 0; }
    return n + drinkSoda(n / 2);
}

/**
 * 二分查找
 * @param nums
 * @param low
 * @param high
 * @param val
 * @return
 */
int binarySearch(int *nums, int low, int high, int val) {
    int len = high + 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (val == nums[mid]) {
            // return mid + 1;
            return mid;
        }
        if (val > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    //没有找到，插入到low的位置。
    return -1;
}

/**
 * 35. 搜索插入位置请必须使用时间复杂度为 O(log n) 的算法。给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * @param nums
 * @param numsSize
 * @param target
 * @return
 */
int searchInsert(int *nums, int numsSize, int target) {
    //使用折半查找插入算法
    int low = 0, high = numsSize - 1, val = target;
    int len = high + 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (val == nums[mid]) {
            return mid;
        }
        if (val > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    //没有找到，插入到low的位置。
    for (int i = 0; len - i > low; i++) {
        nums[len - i] = nums[len - i - 1];
    }
    nums[low] = val;
    return low;
}

void reverseString(char *s, int sSize) {
    //反转字符串
    for (int i = 0; i < sSize / 2; i++) {
        char temp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = temp;
    }
}

bool isPalindromeString(char *s) {
    //125. 验证回文串
    /*
    * 如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
    * 字母和数字都属于字母数字字符。
    * 给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
     */
    //知道字符串的长度，找到最后一个位置
    int len = strlen(s);
    if (len == 1) {
        return true;
    }
    toLowerCase(s); //转换为小写
    for (int i = 0, j = len - 1; i <= j && i < len & j < len && 0 <= i && 0 <= j;) {
        while (i >= 0 && i < len && (s[i] > 'z' || s[i] < 'a') && (s[i] > '9' || s[i] < '0')) {
            //左指针不是字母或者数字，往右移动
            i++;
        }
        while (j >= 0 && j < len && (s[j] > 'z' || s[j] < 'a') && (s[j] > '9' || s[j] < '0')) {
            //右指针不是字母或者数字，往左移动
            j--;
        }
        if (j < 0 || i < 0 || j >= len || i >= len || i > j) {
            //超过范围了，说明没有字母数字，是回文（题目要求不是字母数字的忽略不计）
            return true;
        }
        if (s[i] != s[j]) {
            //出现了不相等的情况
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int lengthOfLastWord(char *s) {
    //58. 最后一个单词的长度
    /*给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
     *单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。*/
    int len = strlen(s);
    int res = 0, count = 0;
    bool isWord = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            if (isWord) {
                //如果扫描完一个单词，就给res赋值
                res = count;
                isWord = false;
            }
        } else if (s[i] >= 'a' && s[i] <= 'z' || s[i] <= 'Z' && s[i] >= 'A') {
            //是字母，确认为一个单词
            if (!isWord) {
                isWord = true;
                count = 0;
            }
            count++;
        }
    }
    res = count;
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shuffle(int *nums, int numsSize, int n, int *returnSize) {
    //1470. 重新排列数组
    /*
    * 给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。
    * 请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组
    */
    *returnSize = numsSize;
    int *res = malloc(sizeof(int) * *returnSize);
    for (int i = 0, j = n, k = 0; i < n && j < 2 * n && k < 2 * n; i++, j++) {
        res[k++] = nums[i];
        res[k++] = nums[j];
    }
    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * @param gridSize - {grid's size}
 * @param returnSize
 */
int **largestLocal(int **grid, int gridSize, int *gridColSize, int *returnSize, int **returnColumnSizes) {
    int kernelSize = 3; //池化层窗口大小
    int stride = 1; //步长

    int outputSize = gridSize - 2;
    *returnSize = outputSize;
    *returnColumnSizes = (int *) calloc(outputSize, sizeof(int));
    for (int i = 0; i < outputSize; i++) {
        (*returnColumnSizes)[i] = outputSize;
    }
    int **res = (int **) malloc(sizeof(int *) * outputSize); //分配结果的矩阵空间
    for (int i = 0; i < outputSize; i++) {
        res[i] = (int *) calloc(outputSize, sizeof(int));
    }

    //两重循环
    for (int i = 0; i < outputSize; i++) {
        for (int j = 0; j < outputSize; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    res[i][j] = grid[i + k][j + l] > res[i][j] ? grid[i + k][j + l] : res[i][j];
                }
            }
        }
    }
    return res;
}


/**
 * Note: The returned array must be malloced, assume caller calls free(). 进位的判断。
 * @param digits 传进来的数组首地址
 * @param digitsSize 数组的长度
 * @param returnSize 返回的数组的大小
 * @return 将大整数加 1，并返回结果的数字数组
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    bool key = false; //标志位，false不进位，true进位
    int carry = 0; //进的数
    int overFlow = 0; //最高位还要进的
    for (int i = digitsSize - 1; i > -1; i--) {
        if (i == digitsSize - 1) {
            digits[i] += 1; //个位加1
        }
        if (key == true) {
            //进位
            digits[i] += carry;
            key = false;
        }
        if (digits[i] > 9) {
            //判断是否进位
            key = true;
            carry = digits[i] / 10;
            digits[i] %= 10;

            if (i == 0) {
                //是最高位了，还要进位，要重新申请一片空间。
                overFlow += carry;
                key = false;
            }
        }
    }
    int *res;
    if (overFlow != 0) {
        //最高位有进位，重新申请
        *returnSize = digitsSize + 1;
        res = (int *) malloc(sizeof(int) * *returnSize);
        res[0] = overFlow;
        for (int i = 0; i < digitsSize; i++) {
            res[i + 1] = digits[i];
        }
    } else {
        *returnSize = digitsSize;
        res = (int *) malloc(sizeof(int) * *returnSize);
        for (int i = 0; i < digitsSize; i++) {
            res[i] = digits[i];
        }
    }
    return res;
}

/**
 * 比较函数的指针，该函数用于比较两个元素。比较函数应当返回一个整数，表示比较结果
 * 小于零：表示第一个元素小于第二个元素。
 * 等于零：表示两个元素相等。
 * 大于零：表示第一个元素大于第二个元素。
 * @param a 左边的数
 * @param b 右边的数
 * @return 左边的减去右边的表示递增，右边减去左边的表示递减
 */
int cmp(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

/**
 * 「力扣挑战赛」心算项目的挑战比赛中，要求选手从 N 张卡牌中选出 cnt 张卡牌，若这 cnt 张卡牌数字总和为偶数，则选手成绩「有效」且得分为 cnt 张卡牌数字总和。 给定数组 cards 和 cnt，其中 cards[i] 表示第 i 张卡牌上的数字。 请帮参赛选手计算最大的有效得分。若不存在获取有效得分的卡牌方案，则返回 0。
 * @param cards 卡牌数组
 * @param cardsSize 卡牌张数
 * @param cnt 卡牌张数
 * @return 最大的得分
 */
int maximumScore(int *cards, int cardsSize, int cnt) {
    //难道是循环吗？太笨了，应当先排序再计算。（递减序列）
    //贪心的策略
    int tmp = 0;
    int res = 0;
    int odd = -1;
    int even = -1;
    // quickSort(cards, 0, cardsSize - 1);
    qsort(cards, cardsSize, sizeof(int), cmp);
    //https://blog.csdn.net/Cooler_z/article/details/122384559?fromshare=blogdetail&sharetype=blogdetail&sharerId=122384559&sharerefer=PC&sharesource=&sharefrom=from_link
    for (int i = cardsSize - 1, j = 0; i >= 0 && j < cnt; i--, j++) {
        tmp += cards[i];
        if (cards[i] & 1) {
            odd = cards[i];
        } else {
            even = cards[i];
        }
    }
    if (tmp % 2 == 0) return tmp;
    if (tmp % 2 != 0) {
        for (int i = cardsSize - 1 - cnt; i >= 0; i--) {
            if (cards[i] % 2 == 0 && odd != -1) {
                res = fmax(res, tmp + cards[i] - odd);
            } else if (cards[i] % 2 == 1 && even != -1) {
                res = fmax(res, tmp + cards[i] - even);
            }
        }
    }
    return res;
}

/**
 * 交换两个数
 * @param a
 * @param b
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 快速排序的划分算法
 * @param nums
 * @param low
 * @param high
 * @return 划分后的数组的枢纽值下标
 */
int partition(int *nums, int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

/**
 * 快速排序算法。C语言有定义好的qsort库函数
 * 解析：https://www.runoob.com/cprogramming/c-function-qsort.html
 * @param nums
 * @param low
 * @param high
 */
void quickSort(int *nums, int low, int high) {
    if (low < high) {
        int pivotPos = partition(nums, low, high);
        quickSort(nums, low, pivotPos - 1);
        quickSort(nums, pivotPos + 1, high);
    }
}

/**
*给你一个整数数组 nums ，如果 nums 至少 包含 2 个元素，你可以执行以下操作：

选择 nums 中的前两个元素并将它们删除。
一次操作的 分数 是被删除元素的和。

在确保 所有操作分数相同 的前提下，请你求出 最多 能进行多少次操作
 * @param nums 数组
 * @param numsSize 数组大小
 * @return 最多可以进行的操作次数
 */
int maxOperations(int *nums, int numsSize) {
    if (numsSize < 2) {
        return 0;
    }
    int res = 1; //返回最大操作次数
    int tmp = nums[0] + nums[1]; //前面两个元素的和
    for (int i = 2; i < numsSize - 1; i += 2) {
        if (nums[i] + nums[i + 1] == tmp) {
            res++;
        } else {
            break;
        }
    }
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
 * @param numbers
 * @param numbersSize
 * @param target
 * @param returnSize
 * @return
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    *returnSize = 2;
    int *res = (int *) malloc(sizeof(int) * 2);
    int low = 0, high = numbersSize - 1;
    for (int i = 0; i < numbersSize; i++) {
        int pair = binarySearch(numbers, i + 1, numbersSize - 1, target - numbers[i]);
        if (pair != -1) {
            res[0] = i;
            res[1] = pair;
            return res;
        }
    }
    return res;
}

/**
 * 找这一位是不是符合要求。三目运算符竟然这么快...不是的，是注释的问题
 * @param nums
 * @param numsSize
 * @param k
 * @return
 */
bool myKOr(int *nums, int numsSize, int k) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        count += nums[i] & 1 ? 1 : 0; //nums[i] & 1得到第i位
        nums[i] >>= 1;
    }
    return count >= k ? true : false;
}

/**
 * 找出数组中的 K-or 值
 * @param nums
 * @param numsSize
 * @param k
 * @return 返回 nums 的 K-or 值
 */
int findKOr(int *nums, int numsSize, int k) {
    int res = 0;
    for (int i = 0; i < 31; i++) {
        res |= myKOr(nums, numsSize, k) ? 1 << i : 0; //这一位是的吗？
    }
    return res;
}

/**
 * 给定一个整数数组，找出总和最大的连续数列，并返回总和
 * @param nums
 * @param numsSize
 * @return
 */
int maxSubArray(int *nums, int numsSize) {
    int tmp = 0;
    int res = 0x80000000;
    for (int i = 0; i < numsSize; i++) {
        tmp += nums[i];
        if (tmp > res) {
            res = tmp;
        }
        if (tmp < 0) {
            tmp = 0;
        }
    }
    return res;
}

/**
 * 给你一个二维整数数组 nums ，其中 nums[i] 是由 不同 正整数组成的一个非空数组，按 升序排列 返回一个数组，数组中的每个元素在 nums 所有数组 中都出现过
 * @param nums
 * @param numsSize
 * @param numsColSize
 * @param returnSize
 * @return
 */
int *intersection(int **nums, int numsSize, int *numsColSize, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 1001); //返回的数组
    int HashTable[1001] = {0}; //记录每个数出现的次数
    int count = 0; //满足条件的数的个数
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            HashTable[nums[i][j]]++;
        }
    }

    for (int i = 0; i < 1001; i++) {
        if (HashTable[i] == numsSize) {
            res[count++] = i;
        }
    }
    *returnSize = count;
    return res;
}


/**
 * 要是猜对某个槽的颜色，则算一次“猜中”；要是只猜对颜色但槽位猜错了，则算一次“伪猜中”。注意，“猜中”不能算入“伪猜中”
 * @param solution 计算机给的组合
 * @param guess 用户猜的
 * @param returnSize 2
 * @return 猜中次数、伪中次数
 */
int *masterMind(char *solution, char *guess, int *returnSize) {
    *returnSize = 2;
    int *res = (int *) malloc(sizeof(int) * (*returnSize));
    int hashSolution[4] = {0}; //哈希表，记录solution字母出现的次数
    int hashGuess[4] = {0}; //哈希表，记录guess字母出现的次数
    int countReal = 0; //真正猜中的次数
    int countFake = 0; //伪中的次数
    for (int i = 0; i < 4; i++) {
        //比对
        if (guess[i] == solution[i]) {
            countReal++;
        }
        //统计solution字母出现的次数
        switch (solution[i]) {
            case 'R': hashSolution[0]++;
                break;
            case 'G': hashSolution[1]++;
                break;
            case 'B': hashSolution[2]++;
                break;
            case 'Y': hashSolution[3]++;
                break;
            default: break;
        }
        //检查guess字母出现的次数
        switch (guess[i]) {
            case 'R': hashGuess[0]++;
                break;
            case 'G': hashGuess[1]++;
                break;
            case 'B': hashGuess[2]++;
                break;
            case 'Y': hashGuess[3]++;
                break;
            default: break;
        }
    }
    for (int i = 0; i < 4; i++) {
        countFake += hashSolution[i] < hashGuess[i] ? hashSolution[i] : hashGuess[i];
    }
    res[0] = countReal;
    res[1] = countFake - countReal;
    return res;
}

/**
 * 2154. 将找到的值乘以 2
 * @param nums
 * @param numsSize
 * @param original
 * @return
 */
int findFinalValue(int *nums, int numsSize, int original) {
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == original) {
            original *= 2;
            i = -1;
        }
    }
    return original;
}

/**
 * 645. 错误的集合：请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。数字不是按顺序排列的。。。纯数学题，等差数列求和，平方和数列求和
 * @param nums
 * @param numsSize
 * @param returnSize
 * @return
 */
int *findErrorNums(int *nums, int numsSize, int *returnSize) {
    long long int sumReal = 0; //实际数组的和
    long long int sumRight = (1 + numsSize) * numsSize / 2; //正确数组的和
    long long int sumSquareReal = 0; //实际数组的平方和
    long long int sumSquareRight = (long long int) numsSize * (numsSize + 1) * (2 * numsSize + 1) / 6;
    //正确数组的平方和
    *returnSize = 2;
    int *res = (int *) malloc(sizeof(unsigned long long int) * (*returnSize));
    for (int i = 0; i < numsSize; i++) {
        sumReal += nums[i];
        sumSquareReal += nums[i] * nums[i];
    }
    long long int diff = sumRight - sumReal;
    long long int diffSquare = sumSquareRight - sumSquareReal;
    //解方程组解出来，此题纯纯为数学问题
    res[0] = (diffSquare / diff - diff) / 2;
    res[1] = (diff + diffSquare / diff) / 2;
    return res;
}


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 * @param root
 * @return
 */
int countNodes(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


/**
 * 3069将元素分配到两个数组中 I
 * @param nums 下标从1开始的数组
 * @param numsSize
 * @param returnSize
 * @return
 */
int *resultArray(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int *arr1 = (int *) malloc(sizeof(int) * (*returnSize));
    int *arr2 = (int *) malloc(sizeof(int) * (*returnSize));
    arr1[0] = nums[0];
    arr2[0] = nums[1];
    int i = 2, pos1 = 0, pos2 = 0;
    while (i < numsSize) {
        if (arr1[pos1] > arr2[pos2]) {
            arr1[++pos1] = nums[i++];
        } else {
            arr2[++pos2] = nums[i++];
        }
    }
    for (int j = 0; j <= pos2; j++) {
        arr1[pos1 + 1 + j] = arr2[j];
    }
    return arr1;
}

/**
* 给你一个字符串 s ，请你判断字符串 s 是否存在一个长度为 2 的子字符串，在 s 反转后的字符串中也出现。
* 如果存在这样的子字符串，返回 true；如果不存在，返回 false 。
 * @param s
 * @return
 */
bool isSubstringPresent(char *s) {
    int len = strlen(s);
    if (len <= 1) {
        return false;
    }
    char *reverse = (char *) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        reverse[i] = s[len - i - 1];
    }
    reverse[len] = '\0';
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (s[i] == reverse[j] && s[i + 1] == reverse[j + 1]) {
                return true;
            }
        }
    }
    return false;
}

/**
 * 计算多出来的几位（二进制计算）
 * @param a 多出来的数组
 * @param res 结果
 * @param i
 * @param k
 * @param carry 进位
 */
void addRemnant(char *a, char *res, int *i, int *k, int *carry) {
    while (*i >= 0) {
        if (*carry == 1) {
            if (a[*i] == '1') {
                res[*k] = '0';
                *carry = 1;
            } else if (a[*i] == '0') {
                res[*k] = '1';
                *carry = 0;
            }
        } else if (*carry == 0) {
            if (a[*i] == '1') {
                res[*k] = '1';
                *carry = 0;
            } else if (a[*i] == '0') {
                res[*k] = '0';
                *carry = 0;
            }
        }
        (*k)--; //自减的优先级比取值运算符高。。。
        (*i)--;
    }
}

/**
 * 67. 二进制求和 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 * @param a
 * @param b
 * @return
 */
char *addBinary(char *a, char *b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    char *res = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
    res[len1 + len2] = '\0';
    int carry = 0; //进位
    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = len1 + len2 - 1; i >= 0 && j >= 0 && k >= 0; i--, j--, k--) {
        if (carry == 1) {
            if (a[i] == '1' && b[j] == '1') {
                res[k] = '1';
                carry = 1;
            } else if (a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1') {
                res[k] = '0';
                carry = 1;
            } else if (a[i] == '0' && b[j] == '0') {
                res[k] = '1';
                carry = 0;
            }
        } else if (carry == 0) {
            if (a[i] == '1' && b[j] == '1') {
                res[k] = '0';
                carry = 1;
            } else if (a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1') {
                res[k] = '1';
                carry = 0;
            } else if (a[i] == '0' && b[j] == '0') {
                res[k] = '0';
                carry = 0;
            }
        }
    }
    addRemnant(a, res, &i, &k, &carry);
    addRemnant(b, res, &j, &k, &carry);
    if (carry > 0) {
        res[k] = '1';
        res = res + k;
    } else {
        res = res + 1 + k;
    }
    return res;
}

/**
 * 9. 回文数 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 负数，不是。
 * 正数，各位存进数组，双指针头尾依次检查
 * @param x 一个整数
 * @return 是否是回文数
 */
bool isPalindromeNum(int x) {
    if (x < 0) {
        return false; //带符号，不是回文
    }
    int n[10];
    int i = 0;
    int num = x;
    while (num != 0) {
        n[i] = num % 10; //从个位开始存到数组里。
        num /= 10;
        i++;
    }
    for (int j = 0; j < i / 2; j++) {
        if (n[j] != n[j - 1 - j]) {
            return false;
        }
    }
    return true;
}

/**
 * 改进之处：在每次交换之后检查是否产生新的逆序，从而提前结束扫描
 * 升序排列，从后往前扫描。
 * @param arr 待排序数组
 * @param size 数组尺寸
 */
void bubbleSortPlus(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        bool newVerse = false; //有新的逆序
        bool changed = false; //发生了交换
        for (int j = size - 1; j > i; j--) {
            //从后向前扫描
            if (arr[j - 1] > arr[j]) {
                swap(&arr[j], &arr[j - 1]);
                changed = true;
                if (j < size - 1) {
                    if (arr[j] > arr[j + 1]) {
                        //检查是否产生新的逆序
                        newVerse = true;
                    }
                }
            }
        }
        if (!newVerse || !changed) {
            //没发生交换，或者交换了以后没有产生逆序
            return;
        }
    }
}

/**
 *69. x 的平方根
* 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
 * @param x
 * @return
 */
int mySqrt(int x) {
    int low = 1, high = x;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (mid == x / mid) {
            return mid;
        }
        if (mid > x / mid) {
            high = mid - 1;
        }
        if (mid < x / mid) {
            low = mid + 1;
        }
    }
    return low - 1;
}

/**
 * 树的节点从0开始编号，建立大根堆
 * @param arr
 * @param l
 * @param r
 * @param pos
 */
void heapAdjust(int *arr, int k, int size) {
    int temp = arr[k];
    for (int i = k * 2 + 1; i < size; i *= 2) {
        //查看k的左子节点
        if (i < size - 1 && arr[i] < arr[i + 1]) {
            ++i; //较大的叶节点的下标
        }
        if (arr[i] > temp) {
            //根小于大叶，要互换位置
            arr[k] = arr[i];
            k = i;
        } else {
            //根大于大叶，没有问题
            break;
        }
    }
    arr[k] = temp;
}

/**
 * 依次调整每一个非叶节点，时间复杂度为O(n)
 * @param arr
 * @param size
 */
void buildMaxHeap(int *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        //依次调整每一个非叶节点
        heapAdjust(arr, i, size);
    }
}

/**
 * 堆排序，时间复杂度为O(nlogn)
 * @param arr
 * @param size
 */
void heapSort(int *arr, int size) {
    buildMaxHeap(arr, size);
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapAdjust(arr, 0, i);
    }
}

/**
 *70. 爬楼梯
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢
 * @param n
 * @return
 */
int climbStairsRecursive(int n) {
    if (n <= 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
}

/**
 *70. 爬楼梯
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢。我真牛逼吧，这就是动态规划？？？就是递归倒过来，存到数组里面。
 * @param n
 * @return
 */
int climbStairs(int n) {
    int *step = (int *) malloc(sizeof(int) * (n + 1));
    step[0] = 1;
    step[1] = 1;
    for (int i = 2; i <= n; i++) {
        step[i] = step[i - 1] + step[i - 2];
    }
    return step[n];
}

/**
 * 新建一个单链表。使用尾插法。
 * @param data 要插入的数据
 * @param dataSize 数据的个数
 * @return 返回头节点
 */
ListNode *initList(int data[], int dataSize) {
    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    ListNode *temp = head;
    for (int i = 0; i < dataSize; i++) {
        //尾插法初始化链表。
        ListNode *node = (ListNode *) malloc(sizeof(ListNode));
        node->val = data[i];
        node->next = NULL;
        temp->next = node;
        temp = temp->next;
    }
    return head;
}

/**
 * 删除所有重复的元素，使每个元素只出现一次。题目不带头结点
 * 使用双指针
 * @param head 一个已排序的链表的头 head
 * @return 已排序的链表
 */
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *p = head; //工作指针的前驱
    struct ListNode *q = head->next; //工作指针
    while (q) {
        if (p->val == q->val) {
            p->next = q->next;
            free(q);
            q = p->next;
        } else {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

int main(void) {
    int arr[] = {1, 1, 1, 1, 1};
    ListNode *head = initList(arr, 5);
    ListNode *res = deleteDuplicates(head);
    return 0;
}
