def running_median(stream):
    result = []
    parcial = []
    for i in range(len(stream)):
        target_index = 0
        if len(parcial) == 0:
            parcial.append(stream[i])
        else:
            hasChanged = False  # HAX (TODO: improve)
            for j in range(len(parcial)):
                if parcial[j] >= stream[i]:
                    parcial.insert(j, stream[i])
                    hasChanged = True
                    break
            if not hasChanged:
                parcial.append(stream[i])
        meio = len(parcial) // 2 - 1
        if len(parcial) % 2 == 0:
            result.append((parcial[meio] + parcial[meio + 1]) / 2)
        else:
            result.append(parcial[meio + 1])

    print(result)
    return result

running_median([2, 1, 4, 7, 2, 0, 5])
