exports.kLargestElement = (list, k) => {

    list.sort((a, b) => a < b ? 1 : b > a ? -1 : 0)

    if (k > list.length || k <= 0 || !k)
        console.log("k is invalid!")
    else
        console.log(`k-th largest element: ${list[k - 1]}`)


}

