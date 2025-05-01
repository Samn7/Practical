#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node* stack[MAX];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

struct Node* createNode(char ch) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ch;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* constructTree(char* postfix) {
    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (isspace(ch)) continue;

        struct Node* newNode = createNode(ch);
        if (!isOperator(ch)) {
            push(newNode);
        } else {
            newNode->right = pop();
            newNode->left = pop();
            push(newNode);
        }
    }
    return pop();
}

void inorder(struct Node* root) {
    if (root) {
        if (isOperator(root->data)) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (isOperator(root->data)) printf(")");
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1, j = 0;

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = stack[top--];
            stack[++top] = ch;
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Saksham 08021102024\n");
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    struct Node* root = constructTree(postfix);

    printf("\nInorder (Reconstructed Infix): ");
    inorder(root);

    printf("\nPreorder (Prefix): ");
    preorder(root);

    printf("\nPostorder (Postfix): ");
    postorder(root);

    return 0;
}
