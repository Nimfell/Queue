//---------------------------------------------------------------------------
#include <vcl.h>
#include <typeinfo.h>
#include <excpt.h>
#include <vector.h>
#pragma hdrstop
#include "Queue.h"
#include "Stack.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
     : TForm(Owner) {}
//---------------------------------------------------------------------------


template <class T>
class Queue
{
      class Node
      {
          public:
          T value;
          Node* next;

          Node(T val=0)
          {
              value = val;
              next = NULL;
          }
      };

      Node* head;
      Node* end;
      int size;

      public:
      Queue()
      {
          head = NULL;
          end = NULL;
          size = 0;
      }

      //-------  add in tail ---------
      void Enqueue(T item)
      {
          Node *node = new Node(item);

          if (size != 0)
               end->next = node;

          end = node;

          if (head == NULL)
               head = node;
          size ++;
      }

      //-------- pop from head --------
      T Dequeue()
      {
          if (Size() == 0) return NULL;   // if queue is empty

          T t = head->value;
          head = head->next;
           size --;
          return t;
      }

      //-------- get size of queue ----
      int Size()
      {
          int S = size;
          return S;
      }

      //------- turn the queue --------
      Turn (T value)
      {
          for(int i = 0; i < value; i++)
          {
               Enqueue(Dequeue());
          }
      }
};

//===============================================================
bool Compare (Queue<int>* queue, int* answer, int size_of_answer)
{
     if ( queue->Size() == size_of_answer )
     {
          for (int i = 0; i < size_of_answer; i++)
          {
               int r = queue->Dequeue();
               int t = answer[i];
               if(r != t)
                    return false;
          }
          return true;
     }
     else
          return false;

}

int Test ()
{
     int result = 0;
     Queue<int> *queue = new Queue<int>;

     queue->Enqueue(1);    //add 3 elements
     queue->Enqueue(2);
     queue->Enqueue(3);
     int answer1[] = {1, 2, 3};
     int size_of_answer = sizeof(answer1)/sizeof(answer1[0]);
     result += !Compare(queue, answer1, size_of_answer);

     queue->Enqueue(1);   //delete 1 element
     queue->Enqueue(2);
     queue->Enqueue(3);
     if (queue->Dequeue() != 1) result++;
     int answer2[] = {2, 3};
     result += !Compare(queue, answer2, 2);

     if (queue->Dequeue() != 0) result++;  // if queue is empty

     queue->Enqueue(1);   //random
     queue->Enqueue(2);
     queue->Enqueue(3);
     if (queue->Dequeue() != 1) result++;
     queue->Enqueue(5);
     if (queue->Dequeue() != 2) result++;
     queue->Enqueue(4);
     if (queue->Dequeue() != 3) result++;
     int answer5[] = {5,4};
     result += !Compare(queue, answer5, 2);

     queue->Enqueue(1);   // turn the queue on one element
     queue->Enqueue(2);
     queue->Enqueue(3);
     queue->Turn(1);
     int answer3[] = {2, 3, 1};
     result += !Compare(queue, answer3, 3);

     queue->Enqueue(1);  // turn the queue on two elements
     queue->Enqueue(2);
     queue->Enqueue(3);
     queue->Turn(2);
     int answer4[] = {3, 1, 2};
     result += !Compare(queue, answer4, 3);

     return result;
}



void __fastcall TForm1::BtnPushClick(TObject *Sender)
{
     Form1->Edit1->Text = Test ();
}
//---------------------------------------------------------------------------

