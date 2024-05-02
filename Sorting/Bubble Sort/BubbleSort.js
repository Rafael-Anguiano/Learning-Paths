function bubbleSort(nums) {
    let hasSwaped;

    for (num of nums) {
        hasSwaped = false;
        for (let j = 0; j < nums.length; j++) {
            if (nums[j] > nums[j + 1]) {
                hasSwaped = true;
                [nums[j], nums[j + 1]] = [nums[j + 1], nums[j]];
            }
        }
        if (!hasSwaped) return nums;
    }
    return nums;
}

let nums = [7, 3, 2, 5, 6, 10, 9, 8, 1];
console.log(bubbleSort(nums));
