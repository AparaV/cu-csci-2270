/*
  Write a function called findMax that prints the maximum value in a linked list.
  The function header should be
  void findMax()
  not
  void LinkedList::findMax()

  The linked list class definition is provided as follows:
  struct Node{
     int key;
     Node *next;
     Node *previous;
     Node(int k, Node *n, Node *p){
         key = k;
         next = n;
         previous = p;
     }
  };

  class LinkedList{
  private:
     Node *head;
     Node *search(int value);
  public:
     LinkedList(){head = NULL;};
     void addNode(int value, int newVal);
     void printList()
     void findMax();
  };
*/

struct Node{
   int key;
   Node *next;
   Node *previous;
   Node(int k, Node *n, Node *p){
       key = k;
       next = n;
       previous = p;
   }
};

class LinkedList{
private:
   Node *head;
   Node *search(int value);
public:
   LinkedList(){head = NULL;};
   void addNode(int value, int newVal);
   void printList()
   void findMax();
};

void findMax() {
    int max;
    if (head == NULL) {
        cout << "empty" << endl;
    }
    else {
        max = head->key;
    }
    Node* curr = head->next;
    while (curr != NULL) {
        if (curr->key > max) {
            max = curr->key;
        }
        curr = curr->next;
    }
    cout << max << endl;
}

/*
  Write a function that enqueues a node to a singly linked list

  void Queue::enqueue(node *newNode);

  The function is a member of a class called Queue. Write the function definition only for enqueue. Given below is the class definition:

  struct node
  {
      int value;
      node *next;
  };

  class Queue
  {
      public:
          Queue(node *, node *);
          virtual ~Queue();
          void enqueue(node *newNode);
          void displayQueue();
      protected:
      private:
          node *head;
          node *tail;
  };
*/

struct node
{
    int value;
    node *next;
};

class Queue
{
    public:
        Queue(node *, node *);
        virtual ~Queue();
        void enqueue(node *newNode);
        void displayQueue();
    protected:
    private:
        node *head;
        node *tail;
};

void Queue::enqueue(node* newNode) {
    if (head == NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}
