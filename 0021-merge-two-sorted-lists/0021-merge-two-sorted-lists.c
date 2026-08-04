/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(int x)
{
    struct ListNode* p = malloc(sizeof(struct ListNode));
    p->next = NULL;
    p->val = x;
    return p;
}

void addNode(struct ListNode **head, int x)
{
    struct ListNode *new = newNode(x);
    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        struct ListNode *current = *head;
        while(current->next!=NULL)
            current = current->next;
        current->next = new;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode* head = NULL;
    if(list1 == NULL && list2 == NULL)
    return NULL;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->val <= list2->val)
        {
            addNode(&head, list1->val);
            list1 = list1->next;
        }
        else
        {
            addNode(&head, list2->val);
            list2 = list2->next;
        }
    }
    while(list1!=NULL)
    {
        addNode(&head, list1->val);
            list1 = list1->next;
    }
    while(list2!=NULL)
    {
        addNode(&head, list2->val);
            list2 = list2->next;
    }
    return head;    
}