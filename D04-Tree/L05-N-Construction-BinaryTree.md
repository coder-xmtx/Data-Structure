# 二叉树的构造

## 一、先序 + 中序

每次通过先序去找根结点，然后利用中序划分左右子树

先序：A B D G E C F H

中序：G D B E A C H F

```mermaid
flowchart TD
    R1["先序首元素 A 是根"]
    R1 --> M1["在中序中定位 A<br/>左边: G D B E<br/>右边: C H F"]
    M1 --> L1["左子树<br/>先序: B D G E<br/>中序: G D B E"]
    M1 --> R2["右子树<br/>先序: C F H<br/>中序: C H F"]

    L1 --> R3["左子树先序首元素 B 是根"]
    R3 --> M3["在中序中定位 B<br/>左边: G D<br/>右边: E"]
    M3 --> L3["B 的左子树<br/>先序: D G<br/>中序: G D"]
    M3 --> R3R["B 的右子树<br/>先序: E<br/>中序: E"]

    L3 --> R4["D 是根"]
    R4 --> M4["在中序中定位 D<br/>左边: G<br/>右边: 空"]
    M4 --> G["G 是 D 的左孩子"]
    R3R --> E["E 是 B 的右孩子"]

    R2 --> R5["右子树先序首元素 C 是根"]
    R5 --> M5["在中序中定位 C<br/>左边: 空<br/>右边: H F"]
    M5 --> R6["C 的右子树<br/>先序: F H<br/>中序: H F"]

    R6 --> R7["F 是根"]
    R7 --> M7["在中序中定位 F<br/>左边: H<br/>右边: 空"]
    M7 --> H["H 是 F 的左孩子"]
```

结果：

<img src="Image/L05-1.svg" alt="L05" width="60%">


## 二、后序 + 中序

每次通过后序去找根结点，然后利用中序划分左右子树

后序：G D B E H F C A

中序：B G D A E C F H

```mermaid
flowchart TD
    R1["后序末元素 A 是根"]
    R1 --> M1["中序定位 A<br/>左: B G D<br/>右: E C F H"]

    M1 --> L1["左子树<br/>后序: G D B<br/>中序: B G D"]
    M1 --> R2["右子树<br/>后序: E H F C<br/>中序: E C F H"]

    L1 --> R3["B 是根"]
    R3 --> M3["中序定位 B<br/>左空，右 G D"]
    M3 --> R4["右子树<br/>后序: G D<br/>中序: G D"]
    R4 --> R5["D 是根"]
    R5 --> M5["中序定位 D<br/>左 G，右空"]
    M5 --> G["G 是 D 的左孩子"]

    R2 --> R6["C 是根"]
    R6 --> M6["中序定位 C<br/>左 E，右 F H"]
    M6 --> E["E 是 C 的左孩子"]
    M6 --> R7["右子树<br/>后序: H F<br/>中序: F H"]
    R7 --> R8["F 是根"]
    R8 --> M8["中序定位 F<br/>左空，右 H"]
    M8 --> H["H 是 F 的右孩子"]
```

结果：

<img src="Image/L05-2.svg" alt="L05-2" width="60%">


## 三、层序 + 中序

层序：A B C D E F G H

中序：F D G B A C H E

```mermaid
flowchart TD
    R1["层序首元素 A 是根"]
    R1 --> M1["中序定位 A<br/>左: F D G B<br/>右: C H E"]

    M1 --> L1["左子树<br/>层序: B D F G<br/>中序: F D G B"]
    M1 --> R2["右子树<br/>层序: C E H<br/>中序: C H E"]

    L1 --> R3["B 是根"]
    R3 --> M3["中序定位 B<br/>左: F D G，右空"]
    M3 --> L3["B 的左子树<br/>层序: D F G<br/>中序: F D G"]

    L3 --> R4["D 是根"]
    R4 --> M4["中序定位 D<br/>左: F，右: G"]
    M4 --> F["F 是 D 的左孩子"]
    M4 --> G["G 是 D 的右孩子"]

    R2 --> R5["C 是根"]
    R5 --> M5["中序定位 C<br/>左空，右: H E"]
    M5 --> R6["C 的右子树<br/>层序: E H<br/>中序: H E"]

    R6 --> R7["E 是根"]
    R7 --> M7["中序定位 E<br/>左: H，右空"]
    M7 --> H["H 是 E 的左孩子"]
```

结果：

<img src="Image/L05-3.svg" alt="L05-3" width="60%">