class Solution {
private:
    int returnLeftHead(int num1, int num2) {
        return std::max(num1, num2);
    }

    int returnRightHead(int num1, int num2) {
        return std::min(num1, num2);
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> array1 = nums1;
        std::vector<int> array2 = nums2;
        if (nums1.size() + 1 > nums2.size()) {
            array1 = nums2;
            array2 = nums1;
        }

        int len1 = array1.size();
        int len2 = array2.size();

        if (len1 == 0) {
            if (len2 % 2 == 0) {
                return (array2[len2 / 2] + array2[len2 / 2 - 1]) * 1.0 / 2;
            }
            else {
                return array2[len2 / 2];
            }
        }

        int min = 0;
        int max = array1.size();
        while (min <= max) {
            int i = (min + max) / 2;
            int j = (len1 + len2 + 1) / 2 - i;
            if ((i == 0 || j == len2 || array1[i - 1] <= array2[j]) &&
                (j == 0 || i == len1 || array1[i] >= array2[j - 1])) {
                int left_head = 0;
                int right_head = 0;
                if (i == 0) {
                    left_head = array2[j - 1];
                }
                else if (j == 0) {
                    left_head = array1[i - 1];
                }
                else {
                    left_head = returnLeftHead(array1[i - 1], array2[j - 1]);
                }

                if (i == len1) {
                    right_head = array2[j];
                }
                else if (j == len2)  {
                    right_head = array1[i];
                }
                else {
                    right_head = returnRightHead(array1[i], array2[j]);
                }

                if ((len1 + len2) % 2 == 0) {
                    return (left_head + right_head) * 1.0 / 2;
                }
                else {
                    if (2 * i + 2 * j > len1 + len2) {
                        return left_head;
                    }
                    else {
                        return right_head;
                    }
                }
            }

            if (array1[i - 1] > array2[j]) {
                max = i - 1;
                continue;
            }

            if (array1[i] < array2[j - 1]) {
                min = i + 1;
                continue;
            }
        }

        return 0;
    }
};
