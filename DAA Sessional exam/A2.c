#include <stdio.h>
#include <string.h>

void Insert(int n, int a[])
{
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Display(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void Heapify(int a[], int n, int i, char *c)
{
    if (strcmp(c, "asc") == 0)
    {
        int max = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (leftChild < n && a[leftChild] > a[max])
            max = leftChild;
        if (rightChild < n && a[rightChild] > a[max])
            max = rightChild;
        if (max != i)
        {
            swap(&a[i], &a[max]);
            Heapify(a, n, max, c);
        }
    }
    else
    {
        int min = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        if (leftChild < n && a[leftChild] < a[min])
            min = leftChild;
        if (rightChild < n && a[rightChild] < a[min])
            min = rightChild;
        if (min != i)
        {
            swap(&a[i], &a[min]);
            Heapify(a, n, min, c);
        }
    }
}

void Sort(int n, int a[], char *c)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i, c);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        Heapify(a, i, 0, c);
    }
}

int Largest(int n, int a[])
{
    Sort(n, a, "desc");
    return a[0];
}

void Replace(int n, int a[], int i, int val)
{
    a[i] = val;
    Sort(n, a, "asc");
}

void InsertOne(int n, int a[])
{
    printf("\n enter the value: ");
    int val;
    scanf("%d", &val);
    a[n - 1] = val;
    Sort(n, a, "acs");
}

void Delete(int n, int a[])
{
    swap(&a[0], &a[n - 1]);
    Sort(n, a, "acs");
}

int main()
{
    int n, s;
    printf("Enter the size of array: ");
    scanf("%d", &s);
    int store[s];
    while (1)
    {
        printf("\n\n");
        printf("\t\t\tMENU\t\t\t");
        printf("\n0. Quit");
        printf("\n1. Insert Element in Array");
        printf("\n2. Display Array");
        printf("\n3 Sort Array in Ascending order using max-Heap");
        printf("\n4. Sort Array in Descending Order");
        printf("\n5. Largest Element");
        printf("\n6. Replace value at a node with new value");
        printf("\n7. Insert new element");
        printf("\n8. Delete an element");
        printf("\n\n");
        printf("\nEnter choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
        {
            printf("\nThank you!\n\n\n");
            return 0;
        }
        case 1:
        {
            printf("\nEnter elements\n");
            Insert(s, store);
            break;
        }
        case 2:
        {
            printf("\nDisplaying elements\n");
            Display(s, store);
            break;
        }
        case 3:
        {
            Sort(s, store, "asc");
            Display(s, store);
            break;
        }
        case 4:
        {
            Sort(s, store, "desc");
            Display(s, store);
            break;
        }
        case 5:
        {
            printf("%d", Largest(s, store));
            break;
        }
        case 6:
        {
            printf("\nEnter index in the range of 0-%d: ", s);
            int index, val;
            scanf("%d", &index);
            printf("Enter the new value: ");
            scanf("%d", &val);
            Replace(s, store, index, val);
            printf("\nArray after the change: \n");
            Display(s, store);
        }
        case 7:
        {
            InsertOne(s, store);
            printf("\nArray after inserting element: \n");
            Display(s, store);
            break;
        }
        case 8:
        {
            Delete(s, store);
            printf("\nArray after deleting element: \n");
            Display(s, store);
            break;
        }
        }
    }
}

-----------------------------------------------------
//O/p:
Enter the size of array: 5


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value     
7. Insert new element
8. Delete an element


Enter choice: 1

Enter elements
12 23 5 2 19


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 2

Displaying elements
12 23 5 2 19


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 3
2 5 12 19 23 


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 4
23 19 12 5 2 


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 5
23

                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 7

 enter the value: 10

Array after inserting element:
23 19 12 10 5


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 8

Array after deleting element:
23 19 12 10 5


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
4. Sort Array in Descending Order
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 2

Displaying elements
23 19 12 10 5


                        MENU
0. Quit
1. Insert Element in Array
2. Display Array
3 Sort Array in Ascending order using max-Heap
5. Largest Element
6. Replace value at a node with new value
7. Insert new element
8. Delete an element


Enter choice: 0

Thank you!
