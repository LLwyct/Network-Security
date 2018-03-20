
const fs = require('fs')
const N = (1e4)
console.log(N);
var prime = []
var vis = new Array(N)
var cnt = 0
for(let i=2;i<N;i++)
{
    if(!vis[i]) prime[cnt++] = i
    for(let j=0;j<cnt&&i*prime[j]<N;j++)
    {
        vis[i*prime[j]] = 1
        if(i%prime[j]==0) break
    }
}
console.log(cnt)
fs.writeFile('./prime.txt', prime.toString(), () => {
})
