# algorithm-note

- 推荐使用 **code::blcoks**, **C-Free**, **dev-c++**
- 目录结构 `评测系统名/题号`

### 算法归纳

#### 排序

- 选择排序
- 插入排序
- 排序题与sort函数的应用

#### 散列

- 整数散列
- 字符串hash（ASCII码表示）

#### 递归

- 全排列

```c++
#include <cstdio>
const int maxn = 11;
int n,P[maxn],hashTable[maxn] = {false};

void generateP(int index){
    if(index == n+1){
        for(int i = 1;i <= n;i++){
            printf("%d", P[i]);
        }
        printf("\n");
        return;
    }
    for(int x = 1;x <= n;x++){
        if(hashTable[x] == false){
            P[index] = x;
            hashTable[x] = true;
            generateP(index+1);
            hashTable[x] = false;
        }
    }
}

int main(){
    n = 3; // 1~3的全排列
    generateP(1);
    return 0;
}
```

- n皇后问题

#### 贪心

- 简单贪心
- 区间贪心

#### 二分

- 二分查找
- 二分法拓展
  - `f(x)=x²`计算根号2的值
  - 半圆形储水装置的装水问题
  - 木棒切割问题（段数一定的情况下每段最长多长）
- 快速/二分幂

```c++
// 计算a^b % m
typedef long long LL;

// 递归写法
LL binaryPow(LL a, LL b, LL m){
  if(b == 0) return 1;
  if(b % 2 == 1) return a*binaryPow(a, b-1, m) % m;
  else{
    LL mul = binaryPow(a, b / 2, m);
    return mul * mul % m;
  }
}

// 迭代写法
LL binaryPow(LL a, LL b, LL m){
  LL ans = 1;
  while(b > 0){
    if(b & 1){
      ans = ans * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
}
```

