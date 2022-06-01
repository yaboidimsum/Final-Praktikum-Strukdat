#include <bits/stdc++.h>

// Taken from https://cppsecrets.com/users/15630114979910410511611297110100101121564864103109971051084699111109/C00-Program-To-Find-Sum-Of-Two-Linked-List.php
using namespace std;

//structure of node for linked list
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* push(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << "";
        n = n->next;
    }
    cout << "]"<< endl;
    cout<< endl;
}

//reverse both linked list
Node *reverse(Node *head)
{
    Node *prev=NULL;
    Node *cur=head;
    while(cur!=NULL)
    {
        Node *n=cur->next;
        cur->next=prev;
        prev=cur;
        cur=n;
    }
    return prev;
}

    //Berfungsi untuk menambahkan dua angka yang berada di linked list..

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
        Node *A=reverse(first);
        Node *B=reverse(second);
        Node *dummy=new Node(0);  //Take dummy node
        Node *temp=dummy;
    int carry=0;  //take care of carry also
    while(A!=NULL ||B!=NULL ||carry)
    {
        int sum=0;
        if(A!=NULL)
        {
            sum+=A->data;
            A=A->next;
        }
        if(B!=NULL)
        {
            sum+=B->data;
            B=B->next;
        }
        sum+=carry;
        carry=sum/10;
        Node *node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    Node *final=reverse(dummy->next); //reverse lagi
        return final;
}

int main()
{
     int list1, list2;
     cin>>list1;
     cin>>list2;
     Node* first = push(list1);  //masukan user input ke 1st linked list
     Node* second = push(list2);  //masukan user input ke 2nd linked list
     Node* res = addTwoLists(first,second);
     cout<<"[";
     printList(res);
     return 0;
}
