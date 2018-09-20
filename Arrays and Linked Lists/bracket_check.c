/* Check for matching brackets in a string */

#include <stdio.h>
#define MAX_STACK 100000

char bracket_stack[MAX_STACK], *p_bracket_stack = bracket_stack;
int token_stack[MAX_STACK], *p_token_stack = token_stack;

int main() {
    char c;
    int i = 1;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '{':
            case '[':
            case '(':
                ++p_bracket_stack;
                *p_bracket_stack = c;

                ++p_token_stack;
                *p_token_stack = i;
                break;
            case '}':
                if ((p_bracket_stack == bracket_stack) || (*p_bracket_stack != '{')) {
                    printf("%d\n", i);
                    return i;
                }
                --p_bracket_stack;
                --p_token_stack;
                break;
            case ']':
                if ((p_bracket_stack == bracket_stack) || (*p_bracket_stack != '[')) {
                    printf("%d\n", i);
                    return i;
                }
                --p_bracket_stack;
                --p_token_stack;
                break;
            case ')':
                if ((p_bracket_stack == bracket_stack) || (*p_bracket_stack != '(')) {
                    printf("%d\n", i);
                    return i;
                }
                --p_bracket_stack;
                --p_token_stack;
                break;
            default:
                break;
        }
        ++i;
    }

    if (p_token_stack != token_stack) {
        printf("%d\n", *(token_stack+1));
    } else {
        printf("Success\n");
    }

    return 0;
}
