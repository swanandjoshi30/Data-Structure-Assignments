#include <iostream>
using namespace std;

// Node definition for the linked list
class node
{
public:
    string prn;
    string name;
    node *next;

    // Constructors
    node()
    {
        prn = "";
        name = "";
        next = NULL;
    }

    node(string prn, string name)
    {
        this->prn = prn;
        this->name = name;
        this->next = NULL;
    }
};

// Forward declaration of the function count
int member_count(node *);

// Function to display the linked list
void display_list(node *head)
{
    node *temp = head;

    if (member_count(head) >= 1)
    {
        int count = 1;
        while (temp != NULL)
        {
            cout << count << ". PRN: " << temp->prn;
            cout << " NAME: " << temp->name << endl;
            temp = temp->next;
            count++;
        }
    }
    else
    {
        cout << "Empty List" << endl;
    }
}

// Function to add a president to the list
void add_president(node *&head, string prn, string name)
{
    node *new_president = new node(prn, name);
    new_president->next = head;
    head = new_president;
}

// Function to add a secretary to the list
void add_secretary(node *head, string prn, string name)
{
    node *new_secretary = new node(prn, name);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_secretary;
}

// Function to add a member to the list
void add_member(node *head, string prn, string name)
{
    node *new_member = new node(prn, name);
    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    new_member->next = temp->next;
    temp->next = new_member;
}

// Function to count the number of members in the list
int member_count(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Recursive function to display the list in reverse order
void display_reverse(node *cur)
{
    if (cur != NULL)
    {
        display_reverse(cur->next);
        cout << "PRN : " << cur->prn;
        cout << " NAME : " << cur->name << endl;
    }
}

// Function to concatenate two lists, i.e., append list2 to list1 and make list2 empty
void concatenate(node *head1, node *&head2)
{
    node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    head2 = NULL;
}

// Function to delete the president from the list
void delete_president(node *&head)
{
    node *to_free = head;
    head = head->next;
    delete to_free;
}

// Function to delete the secretary from the list
void delete_secretary(node *head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *to_free = temp->next;
    temp->next = NULL;
    delete to_free;
}

// Function to delete a member with a specific PRN from the list
void delete_member(node *head, string prn)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->prn == prn)
        {
            node *to_free = temp->next;
            temp->next = temp->next->next;
            delete to_free;
        }
        temp = temp->next;
    }
}

// Function to swap two lists
void swap(node *&l1, node *&l2)
{
    node *temp = l1;
    l1 = l2;
    l2 = temp;
}

// Function to initialize the list with president and secretary
node *start(char cur)
{
    string prn, name;
    cout << "Enter Details for Class " << cur << endl;

    // Adding President
    cout << "Enter the PRN of President:";
    cin >> prn;
    cout << "Enter the Name of President:";
    cin.ignore();
    getline(cin, name);
    node *list = new node(prn, name);

    // Adding Secretary
    cout << "Enter the PRN of Secretary:";
    cin >> prn;
    cout << "Enter the Name of Secretary:";
    cin.ignore();
    getline(cin, name);
    add_secretary(list, prn, name);

    return list;
}

// Main function
int main()
{
    char current = 'A';
    string prn, name;
    int choice, choice2;
    bool while_var = true;

    // Creating lists
    node *list1 = start('A');
    node *list2 = start('B');

    // Main loop
    while (while_var)
    {
        cout << "\n----------------------------------" << endl;
        cout << "\tPINNACLE CLUB" << endl;
        cout << " - Current list is Class " << current << endl;
        cout << "1. Display Current List" << endl;
        cout << "2. Add Member" << endl;
        cout << "3. Delete Member" << endl;
        cout << "4. Count Members" << endl;
        cout << "5. Display List in Reverse Order" << endl;
        cout << "6. Switch List" << endl;
        cout << "7. Merge Two Lists" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nThe Members of Class " << current << " are as follows: " << endl;
            display_list(list1);
            break;

        case 2:
            cout << "\n1. Add President" << endl;
            cout << "2. Add Member" << endl;
            cout << "3. Add Secretary" << endl;
            cout << "Enter your choice:";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                cout << "Enter the PRN of President:";
                cin >> prn;
                cout << "Enter the Name of President:";
                cin.ignore();
                getline(cin, name);
                add_president(list1, prn, name);
                cout << "President added successfully to Class " << current << endl;
                break;

            case 2:
                cout << "Enter the PRN:";
                cin >> prn;
                cout << "Enter the Name :";
                cin.ignore();
                getline(cin, name);
                add_member(list1, prn, name);
                cout << "Member added successfully to Class " << current << endl;
                break;

            case 3:
                cout << "Enter the PRN of Secretary:";
                cin >> prn;
                cout << "Enter the Name of Secretary:";
                cin.ignore();
                getline(cin, name);
                add_secretary(list1, prn, name);
                cout << "Secretary added successfully to Class " << current << endl;
                break;

            default:
                cout << "Enter a valid choice" << endl;
                break;
            }
            break;

        case 3:
            cout << "\n1. Delete President" << endl;
            cout << "2. Delete Member" << endl;
            cout << "3. Delete Secretary" << endl;
            cout << "Enter your choice:";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
                delete_president(list1);
                cout << "President deleted successfully from Class " << current << endl;
                break;

            case 2:
                cout << "Enter PRN to delete:";
                cin >> prn;
                delete_member(list1, prn);
                cout << "Member deleted successfully from Class " << current << endl;
                break;

            case 3:
                delete_secretary(list1);
                cout << "Secretary deleted successfully from Class " << current << endl;
                break;

            default:
                cout << "Enter a valid choice" << endl;
                break;
            }
            break;

        case 4:
            cout << "\nMembers in list " << current << " are " << member_count(list1) << endl;
            break;

        case 5:
            cout << "\nThe Members of Class " << current << " in reverse order are as follows: " << endl;
            display_reverse(list1);
            break;

        case 6:
            swap(list1, list2);
            if (current == 'A')
                current = 'B';
            else
                current = 'A';
            cout << "\nThe current list has been changed successfully to class " << current << endl;
            break;

        case 7:
            concatenate(list1, list2);
            cout << "\nThe Members added to Class " << current << " successfully " << endl;
            delete list2;
            list2 = start('B');
            break;

        case 8:
            cout << "\nThank you. " << endl;
            while_var = false;
            break;

        default:
            cout << "Enter a valid choice..." << endl;
            break;
        }
    }

    cout << "Press any key to exit...";
    cin.ignore();
    cin.get();
    return 0;
}

