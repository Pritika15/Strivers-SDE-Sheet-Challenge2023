//Merge Two Sorted Linked Lists
#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL && second==NULL) return NULL;
    if(first==NULL && second!=NULL) return second;
    if(first!=NULL && second==NULL) return first;
    Node<int>* curr1=first;
    Node<int>* curr2=second;
    Node<int>* Fans= new Node<int>(0) ;
    Node<int>* Bans=Fans;
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data < curr2->data)
        {
            Node<int>* ans= new  Node<int>(curr1->data);
            curr1=curr1->next;
            Fans->next=ans;
            Fans=Fans->next;
        }
        else if(curr1->data == curr2->data)
        {
            Node<int>* ans= new  Node<int>(curr1->data);
            Node<int>* ans1= new  Node<int>(curr2->data);
            curr1=curr1->next;
            curr2=curr2->next;
            Fans->next=ans;
            Fans=Fans->next;
            Fans->next=ans1;
            Fans=Fans->next;
            
            
        }
        else
        {
            Node<int>* ans= new  Node<int>(curr2->data);
            curr2=curr2->next;
            Fans->next=ans;
            Fans=Fans->next;
        }
        
        
    }
    while(curr1!=NULL)
    {
        Node<int>* ans= new  Node<int>(curr1->data);
        curr1=curr1->next;
        Fans->next=ans;
        Fans=Fans->next;
    }
     while(curr2!=NULL)
    {
        Node<int>* ans= new  Node<int>(curr2->data);
        curr2=curr2->next;
        Fans->next=ans;
        Fans=Fans->next;
    }
    return Bans->next;
    
}

