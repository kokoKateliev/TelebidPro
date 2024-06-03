function draft(N, K, arr){
    let minWeight = Math.max(...arr);
    arr.sort((a,b)=>a-b).reverse();

    let sailSums = [];
    for(let i = 0; i < K; i++) {
        sailSums.push(0);
    }

    let index = 0;
    for(let i = 0; i < N; i++) {
        if( sailSums[index] + arr[i] > minWeight ){
            if(++index > K-1){
                index = 0;
            }
        }
        sailSums[index] += arr[i];
        minWeight = minWeight < sailSums[index] ? sailSums[index] : minWeight;
    }

    return minWeight;
}

N = 20;
K = 3;
let sums = [52, 17946, 27160, 387, 17346, 27505, 20816, 20577, 10961, 6021, 5262, 28278, 24163, 931, 11003, 19738, 17914, 1683, 10320, 10475];

console.log(draft(N, K, sums));