#include <stdio.h>

class Queue
{
      class Node
      {
          public:
          int value;
          Node* next;

          Node(int val=0)
          {
              value = val;
              next = NULL;
          }
      };
  public:
      Node* head;
      Node* end;
      int Size;

      public:
      Queue()
      {
          head = NULL;
          end = NULL;
          Size = 0;
      }

      void enqueue(int item)
      {
          Node *node = new Node(item);

          if (Size != 0)
               end->next = node;

          end = node;

          if (head == NULL)
               head = node;
          Size ++;
      }

      int dequeue()
      {
          if (size() == 0) return -1;   // if queue is empty

          int t = head->value;
          head = head->next;
          Size --;
          return t;
      }

      int size()
      {
          return Size;
      }

      void turn (int value)
      {
          for(int i = 0; i < value; i++)
          {
               enqueue(dequeue());
          }
      }
};

