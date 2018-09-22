/* Compute the height of a binary from stdin where each node has an arbitraray number of children */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int children_count;
    struct node **children;
};

void read_word(char *);
void addChild(struct node *, struct node *);
void tree_height(struct node *, int, int *);

char buffer[1000];

int main() {
    /* Get n */
    int n;
    read_word(buffer);
    n = atoi(buffer);

    int i;          /* Current node index */
    int parent_i;   /* Parent node index  */

    /* Allocate tree, create pointer to root */
    struct node tree[n], *p_tree, *root = tree;

    /* Initialize tree with NULL values */
    for (p_tree = tree, i = 0; i < n; ++i, ++p_tree) {
        p_tree->children = NULL;
        p_tree->children_count = 0;
    }

    /* Build tree */
    for (p_tree = tree, i = 0; i < n; ++i, ++p_tree) {
        read_word(buffer);
        parent_i = atoi(buffer);

        /* Find root */
        if (parent_i == -1) {
            root = tree+i;
        } else {
            /* Add child */
            addChild(tree+parent_i, p_tree);
        }
    }

    i = 1; /* i now represents the max_level */
    tree_height(root, 1, &i);
    printf("%d\n", i);
    return 0;
}

void tree_height(struct node *parent, int level, int *max_level) {
    /* If a new max level was found, set it */
    if (level > *max_level) {
        *max_level = level;
    }

    if (parent->children_count > 0) {

        /* Variables to help iterate through list of children */
        struct node **p_children;
        int index;

        /* for each child in the parent's list of children ... */
        for(index = 0, p_children = parent->children; index < parent->children_count; ++index, ++p_children) {
            /* ... compute it's tree height */
            tree_height(*p_children, level + 1, max_level);
        }
    }
}

void addChild(struct node *parent, struct node *child) {
    /* Increment size of parent's list of children */
    parent->children_count = parent->children_count + 1;

    /* Create first child, or reallocate for more children */
    if (parent->children_count == 1) {
        parent->children = (struct node **)malloc(sizeof(struct node *));
    } else {
        parent->children = (struct node **)realloc(parent->children, parent->children_count * sizeof(struct node *));
    }

    /* Set the last element in the list of children to be the new child */
    parent->children[parent->children_count - 1] = child;

    return;
}

void read_word(char *buffer) {
    while (!isspace(*buffer = getchar()) && *buffer != EOF) {
        ++buffer;
    }
    *buffer = '\0';
}
