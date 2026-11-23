// Question 3  栈的应用
// -------------------------
// 假设一个算术表达式中可以包含3种括号：圆括号'('和')'、方括号'['和']'、花括号'{' '}'
// 且这3中括号可按任意次序嵌套使用，比如 "[{...}](...)...[]"
// 编写程序判别给定表达式中所含括号是否正确配对出现

#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 100

bool isMatch(const char left, const char right) {
    if (left == '(' && right == ')') return true;
    if (left == '[' && right == ']') return true;
    if (left == '{' && right == '}') return true;
    return false;
}

bool check(const char* expr) {
    // 空返回
    if (expr == NULL) return false;

    // 数组栈
    char stack[MAXSIZE];
    int top = -1; // 栈顶指针，-1为空栈

    for (int i = 0; expr[i] != '\0'; i++) {
        // 左括号入栈
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            // 栈满，返回
            if (top == MAXSIZE - 1) return false;

            stack[++top] = expr[i];
        }
        // 遇到右括号，栈顶左括号出栈
        if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            // 栈空 返回
            if (top == -1) return false;
            // 栈顶匹配
            char output = stack[top--];
            if (!isMatch(output,expr[i])) return false;
        }
    }

    return top == -1;
}

// 测试
int main() {
    char test[] = "{()}[]()";

    printf("Expr: %s -> %s",test, check(test) ? "Success!" : "Failure!");
}