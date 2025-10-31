#include <stdio.h>
#include <string.h>

#define MAX 100

void printLCS(char X[], char Y[], int m, int n, int LCS_table[MAX][MAX]) {
    int index = LCS_table[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }
    printf("LCS: %s\n", lcs);
}

void LCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int LCS_table[MAX][MAX];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
            else
                LCS_table[i][j] = (LCS_table[i - 1][j] > LCS_table[i][j - 1]) ? LCS_table[i - 1][j] : LCS_table[i][j - 1];
        }
    }
    printf("Cost Matrix:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            printf("%d ", LCS_table[i][j]);
        printf("\n");
    }
    printf("Length of LCS: %d\n", LCS_table[m][n]);
    printLCS(X, Y, m, n, LCS_table);
}

void LRS(char S[]) {
    int n = strlen(S);
    int LCS_table[MAX][MAX];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS_table[i][j] = 0;
            else if (S[i - 1] == S[j - 1] && i != j)
                LCS_table[i][j] = 1 + LCS_table[i - 1][j - 1];
            else
                LCS_table[i][j] = (LCS_table[i - 1][j] > LCS_table[i][j - 1]) ? LCS_table[i - 1][j] : LCS_table[i][j - 1];
        }
    }
    int index = LCS_table[n][n];
    char lrs[index + 1];
    lrs[index] = '\0';
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (LCS_table[i][j] == LCS_table[i - 1][j - 1] + 1 && S[i - 1] == S[j - 1] && i != j) {
            lrs[index - 1] = S[i - 1];
            i--; j--; index--;
        } else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
            i--;
        else
            j--;
    }
    printf("Longest Repeating Subsequence: %s\n", lrs);
}

int main() {
    char X[] = "AGCCCTAAGGGCTACCTAGCTT";
    char Y[] = "GACAGCCTACAAGCGTTAGCTTG";
    printf("TASK 1:\n");
    LCS(X, Y);
    printf("\nTASK 2:\n");
    char S[] = "AABCBDC";
    LRS(S);
    return 0;
}
