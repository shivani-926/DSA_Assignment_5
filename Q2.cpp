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

    int countOccurrences(int key) {
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            if (temp->data == key) count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteAllOccurrences(int key) {
        while (head && head->data == key) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(2);
    list.insert(1);
    list.insert(3);
    list.insert(1);

    int key = 1;

    cout << "Original List: ";
    list.printList();

    int count = list.countOccurrences(key);
    list.deleteAllOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    list.printList();

    return 0;
}
