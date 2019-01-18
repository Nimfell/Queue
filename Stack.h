//---------------------------------------------------------------------------
#ifndef StackH
#define StackH
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

template <class T> class Stack
{
     class Node
     {
          public:
          T value;
          Node* prev;

          Node(T val)
          {
              value = val;
              prev = NULL;
          }
     };
     int stackSize;
     Node* head;

     public:
     Stack()
     {
          head = NULL;
          stackSize = 0;
     }
     //int size();             //-- получить размер стека
     //void push(T val);       //-- поместить элемент на верх стека.
     //T pop();                //-- извлечь последний установленный в стек элемент.
     //T peek();               //-- получить верхний элемент стека, не удаляя его.
     //AnsiString print();     //-- получить содержимое стека в формате AnsiString
 
//---------------------------- поместить ---------------------------------------
      void  push(T val)
      {
          Node *node = new Node(val);
          if (head == NULL)             //если это первый элемент
               node -> prev = NULL;
          else
               node -> prev = head;

          head = node;
          stackSize += 1;
      }
//-----------------------------получить размер стека----------------------------
     int size()
     {
       return stackSize;
     }
//---------------------------- извлечь -----------------------------------------
      T  pop()

      {   if(head != NULL)
          {
               T val = head->value;
               head = head->prev;
          stackSize -= 1;
          return (val);
          }
          return NULL;
      }
//---------------------------- получить ----------------------------------------
     T peek()
     {
          if(head !=NULL)
          {
               int val = head->value;
               return (val);
          }
          return NULL;
     }
//---------------------------- печать -----------------------------------------
      AnsiString print()
      {
          AnsiString string = "";
          Node* tempHead = head;
          while(head != NULL)
          {
               string = string + " " + head->value + " ";
               head = head->prev;
          }
          head = tempHead;
          return string;
      }

      void empty()
      {
          head = NULL;
          stackSize = 0;
      }
};

//---------------------------------------------------------------------------
#endif