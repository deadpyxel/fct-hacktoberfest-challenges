//MOI is Merge Overlapping Intervals
const { MOI } = require('../MOI')

entrance = [
    [1, 3],
    [4, 10],
    [5, 8],
    [20, 25],
    [2, 2],
    [21, 24]
]

console.log('Before remove: ')
console.log(entrance)
MOI(entrance)
console.log('After remove: ')
console.log(entrance)