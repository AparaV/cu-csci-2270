/*
  Write a C++ function to delete nodes in a linked list. The function takes two arguments - the head of the linked list and the value to be deleted. It should delete all nodes which contain the value to be deleted. It should return the head of the linked list.

  node * DeleteNode(node *head, int value);

  The linked list structure:
  struct node
  {
      int value;
      node *next;
      node *prev;
  };
*/

struct node{
  int value;
  node *next;
  node *prev;
};

node* DeleteNode(node* head, int x){
    if (head == NULL) {
        return head;
    }
    node* temp = new node;
    while (head->value == x) {
        temp = head;
        head->next->prev = NULL;
        head = head->next;
        delete temp;
    }
    temp = head;
    while (temp->next != NULL) {
        node* curr = new node;
        if (temp->value == x) {
            curr = temp;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete curr;
        }
        temp = temp->next;
    }
    if (temp->value == x) {
        temp->prev->next = NULL;
        delete temp;
    }
    return head;
}

/*
  Write the function definition only for dequeue for the follow Queue class definition. The queue should use a linked list and be a circular queue.

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
          node* dequeue();
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
        node* dequeue();
        void displayQueue();
    protected:
    private:
        node *head;
        node *tail;
};

node* Queue::dequeue() {
    if (head == NULL) {
        return NULL;
    }
    node* temp = head;
    head = head->next;
    return temp;
}

/*
  Write a function that dequeues a node from a singly linked list.
  node* Queue::dequeue()

  The function is a member of a class called Queue. Write the function definition only for dequeue. Given below is the class definition:

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
          node* dequeue();
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
        node* dequeue();
        void displayQueue();
    protected:
    private:
        node *head;
        node *tail;
};

node* Queue::dequeue() {
    if (head == NULL) {
        return NULL;
    }
    node* temp = head;
    if (head->next == NULL) {
        tail = NULL;
    }
    head = head->next;
    return temp;
}
