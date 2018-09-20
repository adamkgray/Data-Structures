/* Check for matching brackets in a string */

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 100000

struct bracket {
    char value;
    int position;
};

struct bracket stack[MAX_STACK];
struct bracket *p_stack = stack;

int main() {
    char c;
    struct bracket *p_new_bracket;
    int i = 1;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '{':
            case '[':
            case '(':
                ++p_stack;
                p_stack->value = c;
                p_stack->position = i;
                break;
            case '}':
                if ((p_stack == stack) || (p_stack->value != '{')) {
                    printf("%d\n", i);
                    return i;
                }
                --p_stack;
                break;
            case ']':
                if ((p_stack == stack) || (p_stack->value != '[')) {
                    printf("%d\n", i);
                    return i;
                }
                --p_stack;
                break;
            case ')':
                if ((p_stack == stack) || (p_stack->value != '(')) {
                    printf("%d\n", i);
                    return i;
                }
                --p_stack;
                break;
            default:
                break;
        }
        ++i;
    }

    if (p_stack != stack) {
        printf("%d\n", ((stack+1)->position));
    } else {
        printf("Success\n");
    }

    return 0;
}
