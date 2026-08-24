#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode result;
    struct ListNode *tail = &result;
    result.next = NULL;

    for (size_t i = 0; list1 != NULL && list2 != NULL; i++)
    {
        int cmp = list1->val > list2->val;
        
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = cmp ? list2->val : list1->val;
        node->next = NULL;
        tail->next = node;
        tail = node;

        list1 = !cmp ? list1->next : list1;
        list2 = cmp ? list2->next : list2;
    }
    tail->next = list1 ? list1 : list2;
    return result.next;
}

static struct ListNode *makeList(int *vals, int n)
{
    struct ListNode *head = NULL, **cur = &head;
    for (int i = 0; i < n; i++)
    {
        *cur = malloc(sizeof(struct ListNode));
        (*cur)->val = vals[i];
        (*cur)->next = NULL;
        cur = &(*cur)->next;
    }
    return head;
}

static void printList(struct ListNode *head)
{
    printf("[");
    for (struct ListNode *n = head; n; n = n->next)
        printf("%d%s", n->val, n->next ? "," : "");
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    /* list1 = [1,2,4], list2 = [1,3,4] -> [1,1,2,3,4,4] */
    int a1[] = {1, 2, 4}, b1[] = {1, 3, 4};
    printList(mergeTwoLists(makeList(a1, 3), makeList(b1, 3)));

    /* list1 = [], list2 = [] -> [] */
    printList(mergeTwoLists(NULL, NULL));

    /* list1 = [], list2 = [0] -> [0] */
    int b3[] = {0};
    printList(mergeTwoLists(NULL, makeList(b3, 1)));

    return 0;
}
