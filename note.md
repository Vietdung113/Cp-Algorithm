TSP:
```
Try(k)
    for v = 1-> n do 
        if check(v,k) do :
            xk = v
            visited[v] = true
            f = f + C(xk-1,xk)
            if k=n then solution
            else if (f + n -k +1) * C min < fmin do
                try(k+1)
            visited[v] = false
            f = f - C(xk-1,xk)
Solution()
    if f + C(xn,x1) < fmin do 
        fmin = f + C(xn,v1)
```
       
BCA
```
m teachers 1,2,3, ...,m
n subjects 1,2,3, ..., n
mỗi môn sẽ có T(i): list các giáo viên có thể dạy
Model x[1,2,...,n] x[i]: là giáo viên phân dạy môn i.


Try(k)
    for v in T[k] do:
        if check(v,k) then 
            x[k] = v; load[v] += h[k];
            if(k==n) then solution();
            else 
                if(....)
                Try(k+1)
            load[v] = h[k]; 
            
check(v,k)
    for i = 1 to k-1 do:
    if A[i,k] = 1 and x[i] = v then
        return false
    return true
```                
Recusive and Dynamic Programing

Laying tiles:

Recursive
```
    Try(x,y)
        if x >n and ktra full matrix => kq++ return
        + if dd[x][y] = true 
            + Try(x,y+1) y+1 <= 3
            + Tr(x+1,y)
        + if dd[x+1][y] == false x <n
            dd[x][y] = dd[x+1][y] = true
            + Try(X,y+1)
            dd[x][y] = dd[x+1][y] = false
        + if dd[x][y+1] = false y < 3
            dd[x][y] = dd[x][y+1] = true 
            + Try(x+1,y)
            dd[x][y] = dd[x][y+1] = false
            
```

Permutation 

Recursive
```
    Try(k)
        if(k==n+1) kq++ return
        for i =1->n
            if dd[i] = false and cond(i):
                dd[i] = true
                try(k+1)
                dd[i] = false
```
UnRecursive
```
    stack stk = {1} // init first element for stack 
    stack sti = {1} // correspond with try(1) in recursive
    while true:
        k = stk.pop()
        i = sti.pop()
        if k== n+1 do kq++
        else then:  
            while (dd[i] == true) i++ // i < n
         + i<=n 
            stk.push(k)
            sti.push(i+1)
            stk.push(k+1)
            sti.push(1) // start with i = 1 when push new k.
            dd[i] = true
            a[k] = i // a is arrray which used for tracking i.
          + i > n
            dd[a[k]] = false

```

Fenwick Tree (BIT)
```
//start with 1
add(i,v):
    for(;i<=N;i+= i and(-i)
        T[i] +=v
get(i)
    w = 0 
    for(; i>0; i-= i and(-i))
        w +=T[i]
    return w
```
