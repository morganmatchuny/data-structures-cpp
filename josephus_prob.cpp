/*
Morgan Matchuny
Josephus Problem
 */
#include <ctime> 
#include <iostream>
#include <cstdlib>

using namespace std;

//basic linked list start
struct node {
    int data;
    struct node *next;
};

//functions
void add(struct node **);
void show(struct node *);
int winner(struct node **, int);
 
int main() {
	//first node points as the head of the list
    struct node *head = NULL;
    int win, pass;
    add(&head);
    cout << "Enter the number of passes you want: " << endl;
    cin >> pass;
    win = winner(&head, pass);
    cout << "The person to win is : " << win << endl;
    //delete 
    delete[] head;
    int start = clock();
	int stop = clock();
	cout << "time: " << (stop - start ) / double(CLOCKS_PER_SEC)*100000000 << endl;
 
    return 0;
}
 
int winner(struct node **head, int k) {
	
    struct node *p, *q;
    int i;
    q = p = *head;
    
    while (p->next != p) {
        for (i = 0; i < k - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        cout << p->data << " has been eliminated." << endl;
        free(p);
        p = q->next;
    }
    *head = p;
 
    return (p->data);
}
 
void add (struct node **head) {
    struct node *temp, *back;
    int x, reply;
    
    do {
        cout << "Enter the first person: (ex: 1, then input 2, then 3, for however many people.) " << endl;
        cin >> x;
        //reallocating memory for the size of list
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = x;
        temp->next = NULL;
        
        if (*head == NULL) {
            *head = temp;
        }
        else {
            back->next = temp;
        }
        back = temp;
        cout << "Do you want to add another person? 1 = yes, 2 = no: " << endl;
        cin >> reply;
        
    } while (reply != 2);
    
    back->next = *head;
}
 
void show(struct node *head) {
    struct node *temp;
     temp = head;
    cout << temp->data << endl;
    temp = temp->next;
    
    while (head != temp) {
        cout << temp->data;
        temp = temp->next;
	}
}
