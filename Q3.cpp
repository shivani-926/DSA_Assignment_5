#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void printList() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    ListNode* midOfList() {
        if (!head) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Linked List: ";
    list.printList();

    ListNode* mid = list.midOfList();
    if (mid) {
        cout << "Middle Element: " << mid->data << endl;
    } else {
        cout << "The list is empty." << endl;
    }

    return 0;
}
