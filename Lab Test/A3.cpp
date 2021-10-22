#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *random;
};

Node *SortedMerge(Node *first, Node *second);
void Split(Node *source, Node **frontRef, Node **backRef);

void MergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *first, *second;
    if ((head == NULL) || (head->random == NULL))
        return;
    Split(head, &first, &second);

    MergeSort(&first);
    MergeSort(&second);

    *headRef = SortedMerge(first, second);
}

Node *SortedMerge(Node *first, Node *second)
{
    Node *result = NULL;

    if (first == NULL)
        return (second);
    else if (second == NULL)
        return (first);

    if (first->data <= second->data)
    {
        result = first;
        result->random = SortedMerge(first->random, second);
    }
    else
    {
        result = second;
        result->random = SortedMerge(first, second->random);
    }
    return (result);
}

void Split(Node *source, Node **frontRef, Node **backRef)
{
    Node *fast, *slow;

    if (source == NULL || source->random == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }

    slow = source, fast = source->random;

    while (fast != NULL)
    {
        fast = fast->random;
        if (fast != NULL)
        {
            slow = slow->random;
            fast = fast->random;
        }
    }

    *frontRef = source;
    *backRef = slow->random;
    slow->random = NULL;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);

    new_node->random = NULL;

    (*head_ref) = new_node;
}

void printList(Node *node, Node *randomNode)
{
    cout << "Traversal using Next Pointer\n";
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }

    printf("\nTraversal using Random Pointer\n");
    while (randomNode != NULL)
    {
        cout << randomNode->data << " ";
        randomNode = randomNode->random;
    }
}

Node *traverseRandom(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        temp->random = temp->next;
        temp = temp->next;
    }

    MergeSort(&head);

    return head;
}

int main()
{
    Node *head = NULL;

    push(&head, 3);
    push(&head, 2);
    push(&head, 10);
    push(&head, 5);

    Node *randomHead = traverseRandom(head);

    cout << "Result Linked List is: \n";
    printList(head, randomHead);
    return 0;
}