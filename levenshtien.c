#include <stdio.h>
#include <string.h>
int min(int a, int b, int c);
int levenshteinDistance(char *str1, char *str2);

int main() {
    char str1[101], str2[101];
    scanf("%s", str1);
    scanf("%s", str2);
    int distance = levenshteinDistance(str1, str2);
    printf("%d\n", distance);
    return 0;
}
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[len1][len2];
}
