function insertionSort(nums) {
    let currentIndex;
    for (let i = 1; i < nums.length; i++) {
        currentIndex = i;
        while (
            currentIndex > 0 &&
            nums[currentIndex - 1] > nums[currentIndex]
        ) {
            [nums[currentIndex], nums[currentIndex - 1]] = [
                nums[currentIndex - 1],
                nums[currentIndex],
            ];
            currentIndex--;
        }
    }
    return nums;
}

let nums = [7, 3, 2, 5, 6, 10, 9, 8, 1];
console.log(nums);
console.log(insertionSort(nums));
