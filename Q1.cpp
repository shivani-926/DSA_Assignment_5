#include <iostream>
using namespace std;

struct Node {
    int data ;
    Node * next ;
};

Node * head = nullptr ;

Node * createNode(int value)
{
    Node * newNode = new Node();
    newNode -> data = value ;
    newNode -> next = nullptr ;
    return newNode ;
}

void insertAtBeg(int value)
{
    Node * newNode = createNode(value);
    newNode -> next =  head ;
    head = newNode ;
}

void insertAtEnd(int value)
{
    Node * newNode = createNode(value);
    Node * temp = head ;
    while(temp -> next != nullptr)
    {
        temp = temp -> next ;
    }
    temp -> next = newNode ;
}

void insertBefore(int target , int value)
{
    if(head == nullptr) return ;
    if(head -> data == target)
    {
        insertAtBeg(value);
        return ;
    }
    Node * temp = head ;
    while(temp -> next != nullptr && temp -> next -> data != target)
    {
        temp = temp -> next ;
    }
    if(temp->next == nullptr)
    {
        cout << "Node " << target << "not found \n";
    } 
    else{
        Node * newNode = createNode(value);
        newNode->next = temp->next ;
        temp -> next = newNode ;
    }
}

void insertAfter(int target , int value){
    Node * temp = head ;
    while(temp != nullptr && temp -> data != target)
    {
        temp = temp-> next ;
    }
    if(temp == nullptr)
    {
        cout << "Node" << target << "not found\n" ;
    }
    else{
        Node * newNode = createNode(value);
        newNode -> next = temp -> next ;
        temp -> next = newNode ;
    }
}

void deleteFromBeg() {
    if(head==nullptr)
    {
        cout << "NOthing to delete "<< endl ;
        return ;
    }
    Node * temp = head ;
    head = head->next ;
    delete temp ;

}

void deleteFromEnd(){
    if(head == nullptr)
    {
        cout << "LIst is Empty \n" ;
        return ;
    }
    Node * temp = head ;
    while(temp->next->next != nullptr)
    {
        temp = temp -> next ;
    }
    delete temp -> next ;
    temp -> next = nullptr ;
}

void deleteNode(int target)
{
    if(head == nullptr) return ;
    if(head -> data == target)
    {
        deleteFromBeg();
        return;
    }
    Node * temp = head ;
    while(temp -> next != nullptr && temp->next->data != target)
    {
        temp = temp -> next ;
    }
    if(temp -> next == nullptr){
        cout << "Not forund " << endl ;
    }
    else {
        Node * toDelete = temp->next;
        temp->next = toDelete->next ;
        delete toDelete ;
    }
}

void searchNode(int target)
{
    Node * temp = head ;
    int pos = 1 ;
    while(temp != nullptr)
    {
        if(temp -> data == target)
        {
            cout << "Node" << target << "found at pos " << pos << endl;
            return;
        }
        temp = temp -> next ;
        pos = pos +1 ;
    }
    cout << "Node" << target << "not found !\n";
}

void displayList()
{
    if(head == nullptr)
    {
        cout << "List is emplty " << endl ;
        return ;
    }
    Node * temp = head ;
    while(temp != nullptr)
    {
        cout << temp -> data << "->";
        temp = temp -> next ;
    }
    cout << "NULL\n";
}

int main(){
    int choice , value , target ;
    while(true){
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1 :
                cout << "Enter value : ";
                cin >> value ;
                insertAtBeg(value);
                break ;
            case 2 :
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3 :
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                insertBefore(target, value);
                break;
            case 4 :
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new value: ";
                cin >> value;
                insertAfter(target, value);
                break;
            case 5 : 
                deleteFromBeg();
                break;
            case 6 :
                deleteFromEnd();
                break;
            case 7 :
                cout << "Enter value to delete: ";
                cin >> target;
                deleteNode(target);
                break;
            case 8 :
                cout << "Enter value to search: ";
                cin >> target;
                searchNode(target);
                break;
            case 9 :
                displayList();
                break;
            case 10 :
                cout << "Exiting .." << endl ;
                return 0 ;
            default :
                cout << "Invalid choice \n";
        }
    }
}
