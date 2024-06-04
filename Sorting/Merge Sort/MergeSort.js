function merge(arrayA, arrayB) {
    let arrayC = [];
    while (arrayA.length != 0 && arrayB.length != 0) {
        if (arrayA[0] < arrayB[0]) {
            arrayC.push(arrayA.shift());
        } else {
            arrayC.push(arrayB.shift());
        }
    }

    // Either A or B is empty at this point

    if (arrayA.length != 0) {
        arrayC = [...arrayC, ...arrayA];
    }
    if (arrayB.length != 0) {
        arrayC = [...arrayC, ...arrayB];
    }

    return arrayC;
}

function mergeSort(array) {
    if (array.length == 1) return array;

    let arrayA = [];
    let arrayB = [];

    for (let i = 0; i < array.length; i++) {
        if (i < array.length / 2) arrayA.push(array[i]);
        if (i >= array.length / 2) arrayB.push(array[i]);
    }

    arrayA = mergeSort(arrayA);
    arrayB = mergeSort(arrayB);

    return merge(arrayA, arrayB);
}

let nums = [7, 3, 2, 5, 6, 10, 9, 8, 1];
console.log(mergeSort(nums));
