exports.MOI = (intervals) => {

    for (let i = 0; i < intervals.length; i++) {
        let aux = intervals[i]
        for (let j = i; j < intervals.length; j++) {

            if (aux[0] > intervals[j][0]) {
                if (aux[1] < intervals[j][1])
                    intervals.splice(i, 1)
            }
            else {
                if (intervals[j][0] > aux[0])
                    if (intervals[j][1] < aux[1])
                        intervals.splice(j, 1)
            }
        }
    }

}