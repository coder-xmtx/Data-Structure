// 滑动窗口（定长）

// 例子：LeetCode 1456 题  求定长窗口内的元音字母个数

#define MAX(a,b) (b > a ? b : a);

int isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

int maxVowels(char* s, int k) {
    int answer = 0;
    int vowel = 0;

    for (int i = 0; s[i]; i++) {
        if (isVowel(s[i])) vowel++;

        int left = i - k + 1;
        if (left < 0) continue;

        answer = MAX(answer,vowel);
        if (answer == k) break;

        char out = s[left];
        if (isVowel(out)) vowel--;
    }

    return answer;
}
