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
     //int size();             //-- �������� ������ �����
     //void push(T val);       //-- ��������� ������� �� ���� �����.
     //T pop();                //-- ������� ��������� ������������� � ���� �������.
     //T peek();               //-- �������� ������� ������� �����, �� ������ ���.
     //AnsiString print();     //-- �������� ���������� ����� � ������� AnsiString
 
//---------------------------- ��������� ---------------------------------------
      void  push(T val)
      {
          Node *node = new Node(val);
          if (head == NULL)             //���� ��� ������ �������
               node -> prev = NULL;
          else
               node -> prev = head;

          head = node;
          stackSize += 1;
      }
//-----------------------------�������� ������ �����----------------------------
     int size()
     {
       return stackSize;
     }
//---------------------------- ������� -----------------------------------------
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
//---------------------------- �������� ----------------------------------------
     T peek()
     {
          if(head !=NULL)
          {
               int val = head->value;
               return (val);
          }
          return NULL;
     }
//---------------------------- ������ -----------------------------------------
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