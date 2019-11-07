def findRanges(nums):
    ranges = []
    last = nums[0]
    current_range = str(nums[0]) + "->"
    for i in range(len(nums)):
        if nums[i] != last + 1 and nums[i] != last:
            current_range += str(last)
            ranges.append(current_range)
            current_range = str(nums[i]) + "->"

        last = nums[i]

    current_range += str(last)
    ranges.append(current_range)

    return ranges

print(findRanges([0, 1, 15]))
print(findRanges([0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15]))
print(findRanges([2, 3, 4, 5, 6, 6, 6, 6, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 23, 24]))
