#include <iostream>

using namespace std;
class node {
    public:
        int data;
        node * next;
        node(int val) {
            data = val;
            next = NULL;
        }
};
void insert_at_head(node * & head, int val) {
    node * temp = new node(val);
    temp -> next = head;
    head = temp;
}
bool search(node * head, int n) {
    node * temp = head;
    while (temp != NULL) {
        if (temp -> data == n) return true;
        temp = temp -> next;
    }
    return false;
}
void insert_at_tail(node * & head, int val) {
    node * n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node * temp = head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = n;
}

void display(node * head) {
    node * temp = head;
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}
bool isEmpty(node * head) {
    return (head == NULL);
}
bool delete_node(node * & head, int x) {
    node * del = NULL;
    node * temp = head;
    if (temp -> data == x) {
        del = temp;
        head = temp -> next;
        delete del;
        return true;
    }
    while (temp -> next -> data != x) {
        temp = temp -> next;
    }
    del = temp -> next;
    temp -> next = temp -> next -> next;
    delete del;
    return true;
}

int main() {
    node * head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 23);
    insert_at_tail(head, 24);
    insert_at_tail(head, 25);
    insert_at_tail(head, 26);
    display(head);
    cout << endl;
    delete_node(head, 1);
    delete_node(head, 23);
    delete_node(head, 24);
    delete_node(head, 25);
    delete_node(head, 26);
    cout << "IsEmpty List: " << isEmpty(head) << endl;
    display(head);

}
