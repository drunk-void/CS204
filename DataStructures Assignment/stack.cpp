#include <bits/stdc++.h>
using namespace std;

class sNode
{
public:
    int data;
    sNode *next;
};

sNode *newNode(int data)
{
    sNode *stackNode = new sNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(sNode *root)
{
    return !root;
}

void push(sNode **root, int data)
{
    sNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}

int pop(sNode **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    sNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(sNode *root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

int main()
{
    sNode *root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    cout << pop(&root) << " popped from stack\n";

    cout << "Top element is " << peek(root) << endl;

    return 0;
}
