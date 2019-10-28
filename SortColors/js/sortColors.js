exports.SortColors = (colors) => {


    for (let i = 0; i < colors.length; i++)
        for (let j = i + 1; j < colors.length; j++)
            if (colors[i] > colors[j]) {
                let aux = colors[i]
                colors[i] = colors[j]
                colors[j] = aux
            }
}