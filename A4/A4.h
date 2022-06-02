struct ListNode
{
    int value;
    struct ListNode* next;
};

// Specification file for the IntList class
class IntList
{
private:

    ListNode* head;   // List head pointer

public:
    // Constructor
    IntList()
    {
        head = nullptr;
    }
    // Destructor
    ~IntList();

    // List operations

    void insertNode(int);
    void deleteNode(int);
    void print();
    void reverse();
    int getlistSize();
    void removeByPos(int);
    void destroy();
};
