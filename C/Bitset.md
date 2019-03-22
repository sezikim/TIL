# 비트 연산
- **비트(bit)는 2진수를 저장하는 단위.**
- bit값을 통해, 데이터를 효율적으로 활용할 수 있다.
- 비트연산자

|연산자|설명|
|---|---|
|&|비트 AND|
|I|비트 OR|
|^|비트 XOR|
|~|비트 NOT|
|<<|비트를 왼쪽으로 SHIFT|
|>>|비트를 오른쪽으로 SHIFT|
```C
#include <stdio.h>

int main() {
    unsigned char num1 = 1;
    unsigned char num2 = 25;
    
    printf("%d\n", num1 & num2);
    // 00000001 과 00011000 을 AND
    // 00000001
    printf("%d\n", num1 | num2);
    // `` OR
    // 00011001
    printf("%d\n", num1 ^ num2);
    // `` XOR
    // 00011000
    printf("%d\n", ~num2);
    // 00000001 을 NOT
    // 11100111
    printf("%d\n", num1 << 3);
    // 00000001을 3 LEFT SHIFT
    // 00001000
    printf("%d\n", num2 >> 3 );
    // 00011000을 3 RIGHT SHIFT
    // 00000011
    return 0;
}
```

# Bitset
- 여러 데이터의 유무를 비트셋을 이용하여 표기할 수 있다.
- 비트 하나에 한가지 데이터 유무를 판별.
- 비트셋은 구조체를 이용해서 표현.
```c
enum {
    SWORD = 1 << 0,
    DAGGER = 1 << 1,
    SHIELD = 1 << 2,
    SPEAR = 1 << 3,
    AXE = 1 << 4,
    GUN = 1 << 5,
    STAFF = 1 << 6,
    WAND = 1 << 7
};

struct user {
    unsigned char items;
};

int main() {
    struct user user;
    printf("%ld\n", sizeof(user));
    
    user.items |= SWORD;
    
    if (user.items & SWORD) {
        printf("검이 있다.\n");
    }
    else printf("검이 없다.\n");
    
    user.items &= ~SWORD;
    
    if (user.items & SWORD) {
        printf("검이 있다.\n");
    }
    else printf("검이 없다.\n");
    
}
```
- 위 코드를 DEFINE으로 비트연산을 정의해서 사용한다.
```C
#include <stdio.h>
#DEFINE ADD_ITEM(items, item) items |= item
#DEFINE HAS_ITEM(items, item) items & item
#DEFINE REMOVE_ITEM(items, item) items &= ~ 
enum {
    SWORD = 1 << 0,
    DAGGER = 1 << 1,
    SHIELD = 1 << 2,
    SPEAR = 1 << 3,
    AXE = 1 << 4,
    GUN = 1 << 5,
    STAFF = 1 << 6,
    WAND = 1 << 7
};

struct user {
    unsigned char items;
};

int main() {
    struct user user;
    printf("%ld\n", sizeof(user));
    
    ADD_ITEM(user.item, SWORD);
    
    if (HAS_ITEM(user.item, SWORD) {
        printf("검이 있다.\n");
    }
    else printf("검이 없다.\n");
    
    REMOVE_ITEM(user.item, SWORD)
    
    if (HAS_ITEM(user.item, SWORD) {
        printf("검이 있다.\n");
    }
    else printf("검이 없다.\n");
    
}
```
- 이를 비트셋으로 표현해보자.
```C
#include <stdio.h>
#DEFINE ADD_ITEM(user, item) (user)->items[(item)/32] |= 1 << (item % 32)
#DEFINE HAS_ITEM(user, item) (user)->items[(item)/32] & 1 << (item % 32)
#DEFINE REMOVE_ITEM(user, item) (user)->items[(item)/32] &= ~(1 << (item % 32))

enum {
    SWORD,
    DAGGER,
    SHIELD,
    SPEAR,
    AXE,
    GUN,
    STAFF,
    WAND,
    MAX_ITEM_COUNT = 1024
};

typedef unsigned [MAX_ITEM_COUNT /sizeof(unsigned int) * 8];

struct user {
    bitset items;
};

int main() {
    struct user *user;
    
    ADD_ITEM(user, SWORD);
    
    if (HAS_ITEM(user, SWORD) {
        printf("검이 있다.\n");
    }
    else printf("검이 없다.\n");
    
    REMOVE_ITEM(user, SWORD)
    
    if (HAS_ITEM(user, SWORD) {
        printf("검이 있다.\n");
    }
    else printf("검이 없다.\n");
    
}
```

