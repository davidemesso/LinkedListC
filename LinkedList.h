#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include "Utility.h"

// Simple LinkedList Node struct
typedef struct Node
{
  /**
   * Int content of this node.
   */
  void* data;
  
  /**
   * Points to the next Node in the list.
   */
  struct Node* next;  
} Node;

// Prototypes definitions
Node*           llNewList         (void* data, Node* next);
Node*           llAddElement      (Node* start, void* data);
Node*           llGetLast         (Node* start);
Node*           llElementAt       (Node* start, unsigned int index);
unsigned int    llGetLength       (Node* start);
void            llRemoveElementAt (Node** start, unsigned int index);
void            llRemoveElement   (Node** start, Node* node);       
bool            llContains        (Node* start, Node* node);


#endif // !LINKED_LIST_H