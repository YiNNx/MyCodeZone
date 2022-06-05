// 给出两个字符串 $s_1$ 和 $s_2$，若 $s_1$ 的区间 $[l, r]$ 子串与 $s_2$ 完全相同，则称 $s_2$ 在 $s_1$ 中出现了，其出现位置为 $l$。  
// 现在请你求出 $s_2$ 在 $s_1$ 中所有出现的位置。

// 定义一个字符串 $s$ 的 border 为 $s$ 的一个**非 $s$ 本身**的子串 $t$，满足 $t$ 既是 $s$ 的前缀，又是 $s$ 的后缀。  
// 对于 $s_2$，你还需要求出对于其每个前缀 $s'$ 的最长 border $t'$ 的长度。

// ## 输入格式
// ## 输入格式

// 第一行为一个字符串，即为 $s_1$。  
// 第二行为一个字符串，即为 $s_2$。

// ## 输出格式

// 首先输出若干行，每行一个整数，**按从小到大的顺序**输出 $s_2$ 在 $s_1$ 中出现的位置。  
// 最后一行输出 $|s_2|$ 个整数，第 $i$ 个整数表示 $s_2$ 的长度为 $i$ 的前缀的最长 border 长度。

// ## 样例 #1

// ### 样例输入 #1

// ```
// ABABABC
// ABA
// ```

// ### 样例输出 #1

// ```
// 1
// 3
// 0 0 1
// ```
