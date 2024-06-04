function heapSort(nums) {
    for (let i = nums.length - 1; 0 < i; i--) {
        for (let j = i; 0 < j; j--) {
            if (nums[j] > nums[Math.floor((j - 1) / 2)]) {
                [nums[j], nums[Math.floor((j - 1) / 2)]] = [
                    nums[Math.floor((j - 1) / 2)],
                    nums[j],
                ];
            }
        }
        [nums[0], nums[i]] = [nums[i], nums[0]];
    }
    return nums;
}

let nums = [7, 3, 2, 5, 6, 10, 9, 8, 1];
console.log(nums);
console.log(heapSort(nums));
