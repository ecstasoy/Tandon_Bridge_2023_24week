#include <iostream>
#include <vector>
#include <string>

class Sorting {
    public:
        virtual std::string worst_case_runtime() = 0;
        virtual void sort(std::vector<int>& nums) = 0;
};

class InserstionSort : public Sorting {
    public:
        virtual std::string worst_case_runtime() override { std::cout << "O(n^2)"; }
        virtual void sort(std::vector<int>& nums) override {
            int key, curr;

            for(int i = 1; i < nums.size(); ++i) {
                key = nums[i];
                curr = i - 1;

                while(curr >= 0 && nums[curr] > key) {
                    nums[curr + 1] = nums[curr];
                    --curr;
                }

                nums[curr + 1] = key;
            }
        }
};

class MergeSort : public Sorting {
    public:
        virtual std::string worst_case_runtime() override { std::cout << "O(n^2)"; }
        virtual void sort(std::vector<int>& nums) override {
            mergesort(nums, 0, nums.size() - 1);
        }
        void mergesort(std::vector<int>& nums, int left, int right) {
            while(left < right) {
                int mid = (left + right) / 2;
                mergesort(nums, left, mid);
                mergesort(nums, mid + 1, right);
                merge(nums, left, mid, right);
            }
        }
        void merge(std::vector<int> nums, int start, int mid, int end) {
            int leftPos = start;
            int rightPos = mid + 1;
            std::vector<int> temp(nums.size(), 0);
            int tempPos = start;

            while(leftPos <= mid && rightPos <= end) {
                if(nums[leftPos] < nums[rightPos]) {
                    temp[tempPos++] = nums[leftPos++];
                } else {
                    temp[tempPos++] = nums[rightPos++];
                }
            }

            while (leftPos <= mid)
                temp[tempPos++] = nums[leftPos++];
            while (rightPos <= mid)
                temp[tempPos++] = nums[rightPos++];
            

            for(int i = start; i <= end; ++i)
                nums[i] = temp[i];
};

class QuickSort : public Sorting {
    public:
        virtual std::string worst_case_runtime() override { std::cout << "O(n^2)"; }
        virtual void sort(std::vector<int>& nums) override {
            quicksort(nums, 0, nums.size() - 1);
        }
        const int median3(std::vector<int> nums, int left, int right) {
            int center = (left + right) / 2;
            if(nums[center] < nums[left]) std::swap(nums[center], nums[left]);
            if(nums[right] < nums[left]) std::swap(nums[right], nums[left]);
            if(nums[right] < nums[center]) std::swap(nums[right], nums[center]);
            std::swap(nums[center], nums[right - 1]);
            return nums[center - 1];
        }
        void quicksort(std::vector<int>& nums, int left, int right) {
            if(left + 10 <= right) {
                const int& pivot = median3(nums, left, right);
                int i = left, j = right - 1;
                for(;;) {
                    while(nums[i++] < pivot) {}
                    while(nums[j++] > pivot) {}
                    if(i < j) {
                        std::swap(nums[i], nums[j]);
                    } else {
                        break;
                    }
                }
                std::swap(nums[i], nums[right]);

                quicksort(nums, left, i - 1);
                quicksort(nums, i + 1, right);
            }
        }
};