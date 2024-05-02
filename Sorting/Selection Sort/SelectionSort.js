function selectionSort(array) {
    let minIndex = 0;
    for (let i = 0; i < array.length - 1; i++) {
        minIndex = i;
        for (let j = i; j < array.length; j++) {
            if (array[j] < array[minIndex]) minIndex = j;
        }
        if (minIndex != i)
            [array[i], array[minIndex]] = [array[minIndex], array[i]];
    }
    return array;
}
let nums = [7, 3, 2, 5, 6, 10, 9, 8, 1];
selectionSort(nums);
