//---------------------------------------------------------------------------
#ifndef QueuePremH
#define QueuePremH
//---------------------------------------------------------------------------

#include "Stack.h"

template <class T>
class Queue
{
     Stack<T>* SList;
     Stack<T>* QList;

      public:
      Queue()
      {
          SList = new Stack<T>();  // Stack elements list
          QList = new Stack<T>();  // Queue elements list
      }

      //-------  add in tail ---------
      void Enqueue(T item)
      {
          int sizeOfStack = SList->size();
          int sizeOfQueue = QList->size();

          if (sizeOfQueue != 0)   // if the last move was "Dequeue()"
          {
               while(sizeOfQueue != 0)
               {
                    sizeOfQueue--;
                    SList->push( QList->pop() );
               }
          }
          SList->push(item);
      }

      //-------- pop from head --------
      T Dequeue()
      {
          int sizeOfQueue = QList->size();
          int sizeOfStack = SList->size();

          if (sizeOfQueue == 0)
          {
               if (sizeOfStack == 0)  // if the queue is empty
                    return NULL;
               while(sizeOfStack != 0)  // queue to stack
               {
                    sizeOfStack--;
                    QList->push( SList->pop() );
               }
          }
          int result = QList->pop();
          return result;
      }

      //-------- get size of queue ----
      int size()
      {
          int sizeOfStack = SList->size();
          int sizeOfQueue = QList->size();

          if(sizeOfQueue == 0 && sizeOfStack != 0) // if the last move was "Enqueue()"
               return sizeOfStack;
          else
               return sizeOfQueue;
      }

      //------- turn the queue --------
      Turn (T value)
      {
          int sizeOfStack = SList->size();
          int sizeOfQueue = QList->size();

          if(sizeOfQueue == 0 && sizeOfStack != 0)    // if the last move was "Enqueue()"
          {
               for(int i = sizeOfStack; i != 0; i--)  // get all stack to queue
               {
                    QList->push( SList->pop() );
               }
               sizeOfQueue = sizeOfStack;
          }


          for(int i = 0; i < value; i++)
          {
               Enqueue(Dequeue());

               /*-------------------------------------------------------------------
                    -*-  This is almost what happens when we use this method  -*-

               int item = Dequeue();                  // remember the turning element
               for (int i = 1; i < sizeOfQueue; i++)  // queue to stack
               {
                    SList->push( QList->pop() );
               }
               SList->push(item);                     //remembered element to stack

               for (int i = 0; i < sizeOfQueue; i++)  // stack to queue
               {
                    QList->push( SList->pop() );
               }
               ------------------------------------------------------------------*/
          }
      }
};

//---------------------------------------------------------------------------
#endif

